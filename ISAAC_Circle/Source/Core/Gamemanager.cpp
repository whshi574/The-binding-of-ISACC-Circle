#include "Gamemanager.h"

#include <iostream>
#include <spdlog/spdlog.h>

#include "AI/Hero.h"
#include "Tools/GameLog.h"

Gamemanager* Gamemanager::instance_ = nullptr;
Gamemanager::Gamemanager(): bulletPool_(std::make_unique<BulletPool>(5)), enemyPool_(std::make_unique<EnemyPool>(5))
{
    CreateHero(1,300,300);
}

Gamemanager* Gamemanager::get_instance()
{
    if (instance_ == nullptr) {
        instance_ = new Gamemanager();
    }
    return instance_;
}

void Gamemanager::CreateEnemy(int enemyType, float x, float y)
{
    //according to the enemy type, create the enemy
    /**
    * @brief create actor function
    * 
    * now it needs positionx and positiony to create the object
    */
    std::unique_ptr<enemy_base> tempEnemy = enemyPool_->acquire_enemy(enemyType,hero_);
    if(tempEnemy != nullptr)
    {
        tempEnemy->setPosition(sf::Vector2f(x, y));
        enemies_.push_back(move(tempEnemy)); 
    }

}

void Gamemanager::CreateHero(int heroType, float x, float y)
{
    factory_hero* factory_hero_ =new factory_hero();
    hero_=factory_hero_->create_object(heroType,sf::Vector2f(x,y),nullptr);
    delete factory_hero_;
}


void Gamemanager::update(sf::Time deltaTime)
{
    for (auto& enemy : enemies_)
    {
        enemy->update(deltaTime);
    }
    hero_->update(deltaTime);
    for (size_t i = 0; i < hero_bullets_.size(); ++i)
    {
        auto& bullet = hero_bullets_[i];
        bullet->update(deltaTime);
        if (bullet->is_out_of_bounds_)
        {
            bulletPool_->release_bullet(move(bullet));
            hero_bullets_.erase(hero_bullets_.begin() + i);
            --i; // 调整索引
        }
    }
    check_collision();
}

void Gamemanager::render(sf::RenderWindow& window)
{
    for (const auto& enemy : enemies_)
    {
        enemy->render(window);
    }
    
    hero_->render(window);
    for (const auto& bullet : hero_bullets_)
    {
        bullet->render(window);
    }
}

void Gamemanager::handle_event(const sf::Event& event)
{
    hero_->handleEvent(event);
}

sf::Vector2f Gamemanager::get_attack_target_pos() const
{
    // 计算敌人数组中哪个敌人离hero最近，返回这个敌人的位置
    if (enemies_.empty())
    {
        return {0, 0};
    }
    sf::Vector2f targetPos = enemies_[0]->getPosition();
    sf::Vector2f heroPos = hero_->getPosition();
    float minDis = std::sqrt(std::pow(targetPos.x - heroPos.x, 2) + std::pow(targetPos.y - heroPos.y, 2));

    for (int i = 1; i < enemies_.size(); i++)
    {
        sf::Vector2f enemyPos = enemies_[i]->getPosition();
        float dis = std::sqrt(std::pow(enemyPos.x - heroPos.x, 2) + std::pow(enemyPos.y - heroPos.y, 2));
        if (dis < minDis)
        {
            minDis = dis;
            targetPos = enemyPos;
        }
    }
    return targetPos;
}

void Gamemanager::attack(float angle)
{
    const auto bullet = bulletPool_->acquire_bullet(1,hero_->getPosition(),angle);
    if(bullet != nullptr)
        hero_bullets_.push_back(bullet);
    else
    {
        SPDLOG_ERROR("Max bullets reached");
    }
}

void Gamemanager::check_collision()
{
    //检测英雄子弹数组是否与敌人发生碰撞，将碰撞的子弹从数组中移除
    for (auto it = hero_bullets_.begin(); it != hero_bullets_.end();)
    {
        bool collision = false;
        for (size_t i = 0; i < enemies_.size(); ++i)
        {
            auto& enemy = enemies_[i];
            if (enemy->check_collision(*it))
            {
                
                float enemylife = enemy->cause_damage_to_self((*it)->damage_);
                
                if (enemylife <= 0)
                {
                    enemyPool_->release_enemy(move(enemy));
                    enemies_.erase(enemies_.begin() + i);
                }
                bulletPool_->release_bullet(move(*it));
                it = hero_bullets_.erase(it);
                collision = true;
                break;
            }
        }
        if (!collision) {
            ++it;
        }
    }
}


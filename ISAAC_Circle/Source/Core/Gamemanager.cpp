#include "Gamemanager.h"

#include <iostream>
#include <spdlog/spdlog.h>

Gamemanager::Gamemanager(): enemyPool_(std::make_unique<EnemyPool>(5))
{
    
}

void Gamemanager::CreateEnemy(int enemyType, float x, float y,std::shared_ptr<hero_base> hero_)
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
        SPDLOG_INFO("get enemy successfully");
        tempEnemy->setPosition(sf::Vector2f(x, y));
        enemies_.push_back(move(tempEnemy)); 
    }

}

void Gamemanager::remove_enemy(int enemyID)
{
    auto temp=move(enemies_.back());
    enemies_.pop_back();
    enemyPool_->release_enemy(enemyID,move(temp));
}

void Gamemanager::update(sf::Time deltaTime)
{
    for (auto& enemy : enemies_)
    {
        enemy->update(deltaTime);
    }
}

void Gamemanager::render(sf::RenderWindow& window)
{
    for (const auto& enemy : enemies_)
    {
        enemy->render(window);
    }
}

void Gamemanager::handle_event(const sf::Event& event)
{
}

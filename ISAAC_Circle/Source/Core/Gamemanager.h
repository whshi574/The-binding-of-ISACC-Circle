#pragma once
#include <vector>

#include "AI/Bullet.h"
#include "AI/BulletPool.h"
#include "AI/Factory.h"
#include "AI/EnemyPool.h"
namespace sf
{
    class Event;
    class Time;
    class RenderWindow;
}

class Gamemanager
{
private: 
    Gamemanager();// private constructor to prevent instantiation

public:
    static Gamemanager* get_instance();
    ~Gamemanager()=default;
    
    void CreateEnemy(int enemyType, float x, float y);
    void CreateHero(int heroType, float x, float y);
    
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void handle_event(const sf::Event& event);

    //提供给Hero的关于攻击的函数
    sf::Vector2f get_attack_target_pos() const;
    void attack(float angle);

    //检测碰撞
    void check_collision();
private:
    std::vector<std::unique_ptr<enemy_base>> enemies_;
    std::vector<std::shared_ptr<Bullet_Base>> enemies_bullets_;

    std::shared_ptr<hero_base> hero_;
    std::vector<std::shared_ptr<Bullet_Base>> hero_bullets_;

    //两个对象池
    std::unique_ptr<BulletPool> bulletPool_;
    std::unique_ptr<EnemyPool> enemyPool_;

    //单例模式
    static Gamemanager* instance_;
};

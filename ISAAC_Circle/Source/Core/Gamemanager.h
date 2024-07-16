#pragma once
#include <vector>

#include "AI/Bullet.h"
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
    
    void CreateEnemy(int enemyType, float x, float y,std::shared_ptr<hero_base> hero_);
    void CreateHero(int heroType, float x, float y);
    void remove_enemy(int enemyID);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void handle_event(const sf::Event& event);
private:
    std::vector<std::unique_ptr<enemy_base>> enemies_;
    std::vector<std::shared_ptr<Bullet_Base>> enemies_bullets_;

    std::shared_ptr<hero_base> hero_;
    std::vector<std::shared_ptr<Bullet_Base>> hero_bullets_;
    
    std::unique_ptr<EnemyPool> enemyPool_;
    static Gamemanager* instance_;
};

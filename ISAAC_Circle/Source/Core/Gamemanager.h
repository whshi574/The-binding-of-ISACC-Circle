#pragma once
#include <vector>

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
public:
    Gamemanager();
    ~Gamemanager()=default;
    
    void CreateEnemy(int enemyType, float x, float y,std::shared_ptr<hero_base> hero_);
    void remove_enemy(int enemyID);
    void update(sf::Time deltaTime);
    void render(sf::RenderWindow& window);
    void handle_event(const sf::Event& event);
private:
    std::vector<std::unique_ptr<enemy_base>> enemies_;
    std::unique_ptr<EnemyPool> enemyPool_;
};

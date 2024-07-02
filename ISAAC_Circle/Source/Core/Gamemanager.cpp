#include "Gamemanager.h"

#include <iostream>

Gamemanager::Gamemanager(): enemyPool_(std::make_unique<EnemyPool>(5))
{
    
}

void Gamemanager::CreateEnemy(int enemyType, float x, float y)
{
    //according to the enemy type, create the enemy
    /**
    * @brief create actor function
    * 
    * now it needs positionx and positiony to create the object
    */
    std::unique_ptr<enemy_base> tempEnemy = enemyPool_->acquire_enemy();
    if(tempEnemy != nullptr)
    {
        std::cout << "get enemy successfully " << std::endl;
        tempEnemy->setPosition(sf::Vector2f(x, y));
        enemies_.push_back(move(tempEnemy)); 
    }

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

#include "Gamemanager.h"
#include "AI/EnemyPool.h"
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
    enemies_.push_back(enemyPool_->acquire_enemy());
}

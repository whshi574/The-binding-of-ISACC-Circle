#pragma once
#include <vector>

#include "AI/Factory.h"
class EnemyPool;
class Gamemanager
{
public:
    Gamemanager();
    ~Gamemanager()=default;
    
    void CreateEnemy(int enemyType, float x, float y);
private:
    std::vector<std::unique_ptr<enemy_base>> enemies_;
    std::unique_ptr<EnemyPool> enemyPool_;
};

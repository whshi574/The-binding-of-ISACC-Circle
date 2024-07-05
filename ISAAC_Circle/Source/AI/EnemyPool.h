#pragma once
#include <memory>
#include <unordered_map>
#include <vector>
#include "Enemy.h"
class factory_hero;
class factory_enemy;
class EnemyPool
{
public:
    EnemyPool(size_t size);
    ~EnemyPool()=default;

    void release_enemy(int type, std::unique_ptr<enemy_base> enemy);
    std::unique_ptr<enemy_base> acquire_enemy(int type);
    
    void clear(); // clear all enemies in the pool
    
    void set_size(size_t size); // set the size of the pool
private:
    size_t m_size_;
    size_t m_current_index_;

    std::unordered_map<int, std::vector<std::unique_ptr<enemy_base>>> pools;
    
    std::unique_ptr<factory_hero> hero_factory_;
    std::unique_ptr<factory_enemy> enemy_factory_;
};

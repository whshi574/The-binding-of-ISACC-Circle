
#include "EnemyPool.h"

#include <iostream>
#include <spdlog/spdlog.h>

#include "Factory.h"
#include "Enemy.h"
EnemyPool::EnemyPool(size_t size): m_size_(size), m_current_index_(0),
                                   hero_factory_(std::make_unique<factory_hero>()),
                                   enemy_factory_(std::make_unique<factory_enemy>())
{
}

void EnemyPool::release_enemy(std::unique_ptr<enemy_base> enemy)
{
    enemy->reset();
    pools[enemy->get_enemy_type()].push_back(std::move(enemy));
}

std::unique_ptr<enemy_base> EnemyPool::acquire_enemy(int type,std::shared_ptr<hero_base> hero_ptr)
{
    auto& pool = pools[type];
    if (!pool.empty()) {
        auto enemy = std::move(pool.back());
        pool.pop_back();
        return enemy;
    }
        // 没有符合的对象，创建新的对象
    if(m_current_index_ < m_size_)
    {
        SPDLOG_INFO("EnemyPool::acquire_enemy create new enemy");
        m_current_index_++;
        std::unique_ptr<enemy_base> enemy = enemy_factory_->create_object(type,sf::Vector2f(0,0),move(hero_ptr));
        return enemy;
    }
    return nullptr;
    
}

void EnemyPool::clear()
{
    pools.clear();
    m_current_index_ = 0;
}

void EnemyPool::set_size(size_t size)
{
    m_size_ = size;
    for (auto it = pools.begin(); it != pools.end(); ++it) {
        if (it->second.size() > m_size_) {
            it->second.resize(m_size_);
        }
    }
}


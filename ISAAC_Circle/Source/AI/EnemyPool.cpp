
#include "EnemyPool.h"
#include "Factory.h"
#include "Enemy.h"
EnemyPool::EnemyPool(size_t size): m_size_(size), m_current_index_(0), pool_(size),
                                   hero_factory_(std::make_unique<factory_hero>()),
                                   enemy_factory_(std::make_unique<factory_enemy>())
{
}

void EnemyPool::release_enemy(std::unique_ptr<enemy_base> enemy)
{
    enemy->reset();
    pool_.push_back(std::move(enemy));
}

std::unique_ptr<enemy_base> EnemyPool::acquire_enemy()
{
    if (pool_.empty())
    {
        // create new enemy
        if(m_current_index_ < m_size_)
        {
            m_current_index_++;
            return enemy_factory_->create_object(1);
        }
        return nullptr;
    }
    auto enemy = std::move(pool_.back());
    pool_.pop_back();
    return enemy;
}

void EnemyPool::clear()
{
    pool_.clear();
    m_current_index_ = 0;
}

void EnemyPool::set_size(size_t size)
{
    m_size_ = size;
    // 如果新大小小于当前的敌人数量，移除多余的敌人
    while (pool_.size() > m_size_) {
        pool_.pop_back();
    }
    pool_.shrink_to_fit();
}


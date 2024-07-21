#include "BulletPool.h"

#include <spdlog/spdlog.h>

BulletPool::BulletPool(size_t size): m_size_(size), m_current_index_(0),
                                     bullet_factory_(std::make_unique<factory_bullet>())

{
}

void BulletPool::release_bullet(std::shared_ptr<Bullet_Base> buller_ptr)
{
    
    buller_ptr->reset();
    pools[buller_ptr->type_].push_back(std::move(buller_ptr));
}

std::shared_ptr<Bullet_Base> BulletPool::acquire_bullet(int type,sf::Vector2f pos,float angle)
{
    auto& pool = pools[type];
    if (!pool.empty()) {
        auto bullet = std::move(pool.back());
        pool.pop_back();
        bullet->setPosition(pos);
        bullet->move_direction_=angle;
        
        return bullet;
    }
    // 没有符合的对象，创建新的对象
    if(m_current_index_ < m_size_)
    {
        
        m_current_index_++;
        std::shared_ptr<Bullet_Base> bullet = bullet_factory_->create_bullet(1,pos,angle);
        return bullet;
    }
    return nullptr;
    
}

void BulletPool::clear()
{
    pools.clear();
    m_current_index_ = 0;
}

void BulletPool::set_size(size_t size)
{
    m_size_ = size;
    for (auto it = pools.begin(); it != pools.end(); ++it) {
        if (it->second.size() > m_size_) {
            it->second.resize(m_size_);
        }
    }
}
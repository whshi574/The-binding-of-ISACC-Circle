#pragma once
#include <memory>
#include <unordered_map>

#include "Bullet.h"
#include "Factory.h"

class BulletPool
{
public:
    BulletPool(size_t size);
    ~BulletPool()=default;

    void release_bullet(std::shared_ptr<Bullet_Base> buller_ptr);
    std::shared_ptr<Bullet_Base> acquire_bullet(int type,sf::Vector2f pos,float angle);
    
    void clear(); // clear all bullets in the pool
    
    void set_size(size_t size); // set the size of the pool
    private:
    size_t m_size_;
    size_t m_current_index_;

    std::unordered_map<int, std::vector<std::shared_ptr<Bullet_Base>>> pools;
    
    std::unique_ptr<factory_bullet> bullet_factory_;
    
};

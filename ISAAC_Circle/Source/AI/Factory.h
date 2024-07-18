#pragma once
#include <memory>
#include <SFML/System/Vector2.hpp>

class Bullet_Base;
class hero_base;
class enemy_base;

template<typename T>
class factory_base
{
public:
    factory_base()=default;
    virtual ~factory_base()=default;

    //used to create objects of type T,may be enemy or hero
    
        /**
     * @brief create actor function
     * 
     * now it needs positionx and positiony to create the object
     */
    virtual T create_object(int type,sf::Vector2f position,std::shared_ptr<hero_base> hero_ptr)=0;
};
class factory_hero : public factory_base<std::shared_ptr<hero_base>>
{
public:
    factory_hero();
    ~factory_hero() override;
    std::shared_ptr<hero_base>create_object(int type,sf::Vector2f position,std::shared_ptr<hero_base> hero_ptr) override;
};


class factory_enemy : public factory_base<std::unique_ptr<enemy_base>>
{
public:
    factory_enemy();
    ~factory_enemy() override;
    std::unique_ptr<enemy_base> create_object(int type,sf::Vector2f position,std::shared_ptr<hero_base> hero_ptr) override;
};


class factory_bullet
{
    
public:
    factory_bullet()=default;
    ~factory_bullet()=default;

    std::shared_ptr<Bullet_Base> create_bullet(int type,sf::Vector2f position,float direction);
};
#pragma once
#include <memory>

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
    virtual T create_object(int type)=0;
};


class factory_hero : public factory_base<std::unique_ptr<hero_base>>
{
public:
    factory_hero();
    ~factory_hero() override;
    std::unique_ptr<hero_base> create_object(int type) override;
};


class factory_enemy : public factory_base<std::unique_ptr<enemy_base>>
{
public:
    factory_enemy();
    ~factory_enemy() override;
    std::unique_ptr<enemy_base> create_object(int type) override;
};
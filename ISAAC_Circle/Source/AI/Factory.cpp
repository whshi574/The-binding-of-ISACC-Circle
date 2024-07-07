#include "Factory.h"

#include "Enemy.h"
#include "Hero.h"

factory_hero::factory_hero()
= default;

factory_hero::~factory_hero()
= default;

std::shared_ptr<hero_base> factory_hero::create_object(int type,sf::Vector2f position,std::shared_ptr<hero_base> hero_ptr)
{
    return std::make_shared<hero_base>(position);
}

factory_enemy::factory_enemy()
= default;

factory_enemy::~factory_enemy()
= default;

std::unique_ptr<enemy_base> factory_enemy::create_object(int type,sf::Vector2f position,std::shared_ptr<hero_base> hero_ptr)
{
    return std::make_unique<enemy1>(type,position,hero_ptr);
}



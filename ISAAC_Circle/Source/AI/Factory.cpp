#include "Factory.h"

#include "Enemy.h"
#include "Hero.h"

factory_hero::factory_hero()
= default;

factory_hero::~factory_hero()
= default;

std::shared_ptr<hero_base> factory_hero::create_object(int type)
{
    return std::make_shared<hero_base>(sf::Vector2f(0,0));
}

factory_enemy::factory_enemy()
= default;

factory_enemy::~factory_enemy()
= default;

std::shared_ptr<enemy_base> factory_enemy::create_object(int type)
{
    return std::make_shared<enemy1>(std::make_shared<hero_base>(sf::Vector2f(0,0)),sf::Vector2f(0,0));
}



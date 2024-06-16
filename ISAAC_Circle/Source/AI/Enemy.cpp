#include "Enemy.h"
#include <cmath>
enemy_base::enemy_base(): move_direction_(sf::Glsl::Vec2(0, 0)), speed(0),location_(sf::Glsl::Vec2(0, 0)),attack_damage_(0),
                                            attack_target_(nullptr),health_(100)
{
}


void enemy_base::set_move_speed(float move_speed)
{
    speed=move_speed;
}

float enemy_base::get_move_speed() const
{
    return speed;
}

sf::Glsl::Vec2 enemy_base::get_move_direction() const
{
    return move_direction_;
}

sf::Glsl::Vec2 enemy_base::get_current_location() const
{
    return location_;
}

void enemy_base::move()
{
    float angle = std::atan2(move_direction_.y, move_direction_.x);
    sf::Glsl::Vec2 temp_vec2(location_.x+speed*cos(angle),location_.y+speed*sin(angle));
    location_=temp_vec2;
}

void enemy_base::cause_damage_to_hero()
{
    
}

void enemy_base::cause_damage_to_self(float damage)
{
    health_ -= damage;
}

void enemy1::Attack()
{
}

void enemy_base::set_move_direction(const sf::Glsl::Vec2& vec2)
{
    move_direction_=vec2;
}

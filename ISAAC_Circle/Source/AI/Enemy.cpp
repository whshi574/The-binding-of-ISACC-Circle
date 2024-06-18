#include "Enemy.h"
#include <cmath>
#include "Hero.h"
enemy_base::enemy_base(std::shared_ptr<hero_base> attack_target, const sf::Vector2f& position):Actor(position),move_direction_(sf::Glsl::Vec2(0, 0)), speed(0),attack_damage_(0),
                                                                 attack_target_(std::move(attack_target)), health_(100)
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


void enemy_base::move()
{
    float angle = std::atan2(move_direction_.y, move_direction_.x);
    const sf::Vector2f temp_vec2(getPosition().x+speed*cos(angle),getPosition().y+speed*sin(angle));
    setPosition(temp_vec2);
}

void enemy_base::cause_damage_to_hero()
{
    
}

void enemy_base::cause_damage_to_self(float damage)
{
    health_ -= damage;
}

float enemy_base::calculate_distance()
{
    const float distance=std::sqrt(std::pow(getPosition().x-attack_target_->getPosition().x,2)+std::pow(getPosition().y-attack_target_->getPosition().y,2));
    return distance;
}

void enemy_base::update(const sf::Time& delta)
{
    
}

void enemy_base::render(sf::RenderWindow& window)
{
}

void enemy_base::handleEvent(const sf::Event& event)
{
    Actor::handleEvent(event);
}

enemy1::enemy1(std::shared_ptr<hero_base> attack_target, const sf::Vector2f& position):enemy_base(std::move(attack_target), position)
{
}

void enemy1::Attack()
{
}

void enemy_base::set_move_direction(const sf::Glsl::Vec2& vec2)
{
    move_direction_=vec2;
}

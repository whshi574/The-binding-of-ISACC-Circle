#pragma once
#include <memory>

#include "SFML/Graphics/Glsl.hpp"
constexpr float PI = 3.14159265358979323846f;
class hero_base;
class enemy_base
{
public:
    enemy_base();
    virtual ~enemy_base()=default;

    
    void set_move_speed(float move_speed);
    float get_move_speed() const;
    sf::Glsl::Vec2 get_move_direction() const;
    sf::Glsl::Vec2 get_current_location() const;
    void set_move_direction(const sf::Glsl::Vec2& vec2);
    
    /**
     * @brief enemy moveFunction
     * 
     * According to the move_direction to calculate the next position
     */
    void move();

        /**
     * @brief enemy Attack Function
     * 
     * Do attack action,yuancheng or jincheng, so it needs to set to pure virtual 
     */
    virtual void Attack()=0;
    
    void cause_damage_to_hero();

    void cause_damage_to_self(float damage);
private:
    //Control the Enemy Move Direction
    sf::Glsl::Vec2 move_direction_;
    //move speed
    float speed;
    //enemy location
    sf::Glsl::Vec2 location_;
    //self Damage
    float attack_damage_;
    std::shared_ptr<hero_base> attack_target_;
    //health
    float health_;
    
};

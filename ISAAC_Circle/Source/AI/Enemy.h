#pragma once
#include "SFML/Graphics/Glsl.hpp"
constexpr float PI = 3.14159265358979323846f;
class enemy_base
{
public:
    enemy_base();
    virtual ~enemy_base()=default;

    
    void set_move_speed(float move_speed);
    float get_move_speed() const;
    sf::Glsl::Vec2 get_move_direction() const;
    sf::Glsl::Vec2 get_current_location() const;

    /**
     * @brief enemy moveFunction
     * 
     * According to the move_direction to calculate the next position
     */
    void move();

    
    void set_move_direction(const sf::Glsl::Vec2& vec2);
private:
    //Control the Enemy Move Direction
    sf::Glsl::Vec2 move_direction_;
    //move speed
    float speed;
    //enemy location
    sf::Glsl::Vec2 location_;
};

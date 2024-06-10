#pragma once
#include <SFML/Graphics/Glsl.hpp>

class enemy_base
{
public:
    virtual ~enemy_base()=default;

    sf::Glsl::Vec2 get_move_direction() const;
    void set_move_direction(const sf::Glsl::Vec2& vec2);
private:
    //Control the Enemy Move Direction
    sf::Glsl::Vec2 move_direction_; 
};

#include "Enemy.h"

sf::Glsl::Vec2 enemy_base::get_move_direction() const
{
    return move_direction_;
}

void enemy_base::set_move_direction(const sf::Glsl::Vec2& vec2)
{
    move_direction_=vec2;
}

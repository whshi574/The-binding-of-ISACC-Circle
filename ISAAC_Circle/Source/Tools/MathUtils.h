#pragma once
#include <SFML/System/Vector2.hpp>
#include <cmath>

class MathUtils
{
public:
    static bool approximatelyEqual(sf::Vector2f a, sf::Vector2f b, float epsilon)
    {
        return std::abs(a.x - b.x) < epsilon && std::abs(a.y - b.y) < epsilon;
    }

    static bool approximatelyEqual(float a, float b, float epsilon)
    {
        return std::abs(a - b) < epsilon;
    }
};

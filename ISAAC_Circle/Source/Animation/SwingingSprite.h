#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class SwingingSprite {
public:
    SwingingSprite(sf::Sprite& sprite, float elasticity, float damping)
        : sprite(sprite), angle(0.0f), angularVelocity(1.0f), elasticity(elasticity), damping(damping) {}

    void UpdateTick(sf::Time deltaTime);

private:
    sf::Sprite& sprite;

    //Now angle
    float angle;

    //Now angularVelocity
    float angularVelocity;

    //Restore elasticity parameter
    float elasticity;

    //Air damping parameter
    float damping;            
};
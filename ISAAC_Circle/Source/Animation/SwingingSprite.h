#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class SwingingSprite {
public:
    SwingingSprite(sf::Sprite& sprite, float initAngle, float initAngularVelocity, float elasticity, float damping)
        : sprite(sprite), angle(initAngle), angularVelocity(initAngularVelocity), elasticity(elasticity), damping(damping) {}

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
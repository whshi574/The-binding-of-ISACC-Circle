#include "SwingingSprite.h"

#include <spdlog/spdlog.h>

void SwingingSprite::UpdateTick(sf::Time deltaTime)
{
    float time = deltaTime.asSeconds();
    float angularAcceleration = -elasticity * angle - damping * angularVelocity;
    
    angularVelocity += angularAcceleration * time;
    angle += angularVelocity * time;
    
    sprite.setRotation(angle * 180.0f / 3.14159f);
}
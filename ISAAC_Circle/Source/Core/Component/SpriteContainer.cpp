#include "SpriteContainer.h"

#include <SFML/Graphics/Sprite.hpp>
#include <spdlog/spdlog.h>
#include "Tools/GameLog.h"

SpriteContainer::SpriteContainer():position(0, 0), scale(1, 1), angle(0)
{
}

SpriteContainer::~SpriteContainer()
{
}

void SpriteContainer::addSprite(sf::Sprite& sprite, const sf::Vector2f relativePosition)
{
    addSprite(sprite, relativePosition, sf::Vector2f(1, 1), 0);
}

void SpriteContainer::addSprite(sf::Sprite& sprite, const sf::Vector2f relativePosition,
    const sf::Vector2f relativeScale, float relativeAngle)
{
    sprites.push_back(&sprite);
    relativePositions.push_back(relativePosition);
    relativeScales.push_back(relativeScale);
    relativeAngles.push_back(relativeAngle);
}

void SpriteContainer::removeSprite(sf::Sprite& sprite)
{

}

bool SpriteContainer::getSpriteIndex(const sf::Sprite& sprite, size_t& index) const
{
    if (sprites.empty()) {
        SPDLOG_WARN("Sprite container is empty, getSpriteIndex will be return 0.");
        return false;
    }
    
    const auto it = std::find(sprites.begin(), sprites.end(), &sprite);
    if (it != sprites.end()) {
        index = std::distance(sprites.begin(), it);
    } else {
        SPDLOG_WARN("Target sprite not found in container,getSpriteIndex will be return 0.");
        return false;
    }

    return true;
}

void SpriteContainer::setPosition(const sf::Vector2f position)
{
    this->position = position;
    updatePositions();
}

void SpriteContainer::setScale(float factorX, float factorY)
{
    this->scale = sf::Vector2f(factorX, factorY);
    updateScales();
}

void SpriteContainer::setScale(sf::Vector2f scale)
{
    this->scale = scale;
    updateScales();
}


void SpriteContainer::setRotation(float angle)
{
    this->angle = angle;
    updateRotations();
}

void SpriteContainer::setRelativePosition(sf::Sprite& sprite, const sf::Vector2f newRelativePosition)
{
    size_t index;
    
    if (!getSpriteIndex(sprite, index)) {
        SPDLOG_WARN("Target sprite not found in container, setRelativePosition will be not be changed.");
        return;
    }
    
    relativePositions[index] = newRelativePosition;
    updatePositions();
}

void SpriteContainer::setRelativeScale(sf::Sprite& sprite, const sf::Vector2f newRelativeScale)
{
    size_t index;
    
    if (!getSpriteIndex(sprite, index)) {
        SPDLOG_WARN("Target sprite not found in container, setRelativePosition will be not be changed.");
        return;
    }

    relativeScales[index] = newRelativeScale;
    updateScales();
}

void SpriteContainer::setRelativeAngle(sf::Sprite& sprite, float newRelativeAngle)
{
    size_t index;
    
    if (!getSpriteIndex(sprite, index)) {
        SPDLOG_WARN("Target sprite not found in container, setRelativePosition will be not be changed.");
        return;
    }

    relativeAngles[index] = newRelativeAngle;
    updateRotations();
}

void SpriteContainer::updateTransforms()
{
    for (size_t i = 0; i < sprites.size(); ++i)
    {
        if (sprites[i] == nullptr)
        {
            SPDLOG_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            LOG_GAME_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            sprites.erase(sprites.begin() + i);
            continue;
        }
        
        sprites[i]->setPosition(position + relativePositions[i]);
        sprites[i]->setRotation(angle + relativeAngles[i]);
        sprites[i]->setScale(scale.x * relativeScales[i].x, scale.y * relativeScales[i].y);
    }
}

void SpriteContainer::updatePositions()
{
    for (size_t i = 0; i < sprites.size(); ++i)
    {
        if (sprites[i] == nullptr)
        {
            SPDLOG_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            LOG_GAME_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            sprites.erase(sprites.begin() + i);
            continue;
        }
        
        sprites[i]->setPosition(position + relativePositions[i]);
    }
}

void SpriteContainer::updateScales()
{
    for (size_t i = 0; i < sprites.size(); ++i)
    {
        if (sprites[i] == nullptr)
        {
            SPDLOG_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            LOG_GAME_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            sprites.erase(sprites.begin() + i);
            continue;
        }
        
        sprites[i]->setScale(scale.x * relativeScales[i].x, scale.y * relativeScales[i].y);
    }
}

void SpriteContainer::updateRotations()
{
    for (size_t i = 0; i < sprites.size(); ++i)
    {
        if (sprites[i] == nullptr)
        {
            SPDLOG_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            LOG_GAME_ERROR("Your sprite container has a nullptr sprite, please check your sprite life circle, now the sprite pointer will be removed automatically from the container.");
            sprites.erase(sprites.begin() + i);
            continue;
        }
        
        sprites[i]->setRotation(angle + relativeAngles[i]);
    }
}

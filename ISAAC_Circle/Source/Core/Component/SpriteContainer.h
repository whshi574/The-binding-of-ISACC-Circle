#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

namespace sf
{
    class Sprite;
}

class SpriteContainer
{
public:
    SpriteContainer();
    ~SpriteContainer();

public:
    void addSprite(sf::Sprite& sprite, const sf::Vector2f relativePosition);
    void addSprite(sf::Sprite& sprite, const sf::Vector2f relativePosition, const sf::Vector2f relativeScale, float relativeAngle);

    void removeSprite(sf::Sprite& sprite);

    bool getSpriteIndex(const sf::Sprite& sprite, size_t& index) const;

public:
    void setPosition(const sf::Vector2f position);
    void setScale(float factorX, float factorY);
    void setScale(sf::Vector2f scale);
    void setRotation(float angle);

    void setRelativePosition(sf::Sprite& sprite, const sf::Vector2f newRelativePosition);
    void setRelativeScale(sf::Sprite& sprite, const sf::Vector2f newRelativeScale);
    void setRelativeAngle(sf::Sprite& sprite, float newRelativeAngle);

private:
    std::vector<sf::Sprite*> sprites;
    std::vector<sf::Vector2f> relativePositions;
    std::vector<sf::Vector2f> relativeScales;
    std::vector<float> relativeAngles;
    
private:
    sf::Vector2f position;
    sf::Vector2f scale;
    float angle;

private:
    void updateTransforms();
    void updatePositions();
    void updateScales();
    void updateRotations();

};

#pragma once
#include "AnimationClip.h"
#include <SFML/Graphics.hpp>

class SpriteAnimationClip : public AnimationClip
{
public:
    SpriteAnimationClip(sf::Sprite* sprite, float time);
    ~SpriteAnimationClip();
private:
    sf::Sprite* m_nowSprite;

public:
    sf::Sprite* getSprite() const;

public:
    void update(sf::Time deltaTime) override;
    void render(sf::RenderWindow& window) override;
};

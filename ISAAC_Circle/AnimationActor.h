#pragma once
#include "Actor.h"

class AnimationActor : public Actor
{
public:
    AnimationActor();
    virtual ~AnimationActor() = default;
    
    virtual void update(const sf::Time& deltaTime) override;
    virtual void render(sf::RenderWindow& window) override;

private:
    AnimationSequence* m_animation;
};

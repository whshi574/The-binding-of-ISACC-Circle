#pragma once
#include "Core/World.h"
#include "Animation/AnimationActor.h"

class SHIWEIHAO_Test : public World
{
public:
    SHIWEIHAO_Test(Game* game);
    ~SHIWEIHAO_Test();
public:
    void UpdateTick(sf::Time deltaTime) override;
    void RenderTick(sf::RenderWindow& window) override;
    void HandleEventsTick(const sf::Event& event) override;

private:
    AnimationActor m_pAnimationActor;
};

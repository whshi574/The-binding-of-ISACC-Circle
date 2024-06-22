#pragma once
#include "Core/World.h"

class LUOJIAWEN_Test : public World
{
public:
    LUOJIAWEN_Test(Game* game);
    ~LUOJIAWEN_Test();
public:
    void UpdateTick(sf::Time deltaTime) override;
    void RenderTick(sf::RenderWindow& window) override;
    void HandleEventsTick(const sf::Event& event) override;
};

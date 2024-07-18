#pragma once
#include "AI/Hero.h"
#include "Core/Gamemanager.h"
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
    void create_enemy();
private:
    
    Gamemanager* gamemanager_;
    
    sf::Clock clock;
    sf::Time timeSinceLastCall_create_enemy;
    sf::Time create_enemy_interval;
};

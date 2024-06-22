#include "LUOJIAWEN_Test.h"
#include "SFML/System/Time.hpp"

LUOJIAWEN_Test::LUOJIAWEN_Test(Game* game): World(game)
{
    
}

LUOJIAWEN_Test::~LUOJIAWEN_Test()
{
    
}

void LUOJIAWEN_Test::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
}

void LUOJIAWEN_Test::RenderTick(sf::RenderWindow& window)
{
    World::RenderTick(window);
}

void LUOJIAWEN_Test::HandleEventsTick(const sf::Event& event)
{
    World::HandleEventsTick(event);
}
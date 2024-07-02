#include "LUOJIAWEN_Test.h"

#include "AI/Factory.h"
#include "SFML/System/Time.hpp"
#include "Core/Game.h"
LUOJIAWEN_Test::LUOJIAWEN_Test(Game* game): World(game)
{
    factory_hero* factory_hero_ =new factory_hero();
    hero=factory_hero_->create_object(1,sf::Vector2f(GetGame()->GetWindowWidth()/2,GetGame()->GetWindowHeight()/2));
    delete factory_hero_;
}
LUOJIAWEN_Test::~LUOJIAWEN_Test()
{
    
}

void LUOJIAWEN_Test::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
    hero->update(deltaTime);
}

void LUOJIAWEN_Test::RenderTick(sf::RenderWindow& window)
{
    World::RenderTick(window);
    hero->render(window);
}

void LUOJIAWEN_Test::HandleEventsTick(const sf::Event& event)
{
    World::HandleEventsTick(event);
    hero->handleEvent(event);
}
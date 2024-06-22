#include "World.h"
#include "SFML/System/Time.hpp"
#include "Game.h"

World::World(Game* game)
{
    m_game = game;
}

World::~World()
{
    delete m_game;
}

void World::UpdateTick(sf::Time deltaTime)
{
    
}

void World::HandleEventsTick(const sf::Event& event)
{
    
}

void World::RenderTick(sf::RenderWindow& window)
{
    
}
#include "World.h"
#include <spdlog/spdlog.h>
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
    for (auto drawable : m_drawables)
    {
        if (drawable == nullptr)
        {
            SPDLOG_ERROR("You are runnig a nullptr in the render list");
            continue;
        }
        window.draw(*drawable);
    }
}

void World::AddObjectToRender(sf::Drawable* drawable)
{
    if (drawable == nullptr)
    {
        SPDLOG_ERROR("You are trying to add a nullptr to the render list, please check code");
        return;
    }

    m_drawables.push_back(drawable);
}

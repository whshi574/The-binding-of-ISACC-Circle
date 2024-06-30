#include "World.h"
#include <spdlog/spdlog.h>
#include "SFML/System/Time.hpp"
#include "Game.h"
#include "Actor.h"
#include "Tools/GameLog.h"

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
    for (const auto& actor : m_actors)
    {
        if (actor == nullptr)
        {
            SPDLOG_ERROR("You are running a nullptr in the world actors list, maybe somewhere you deleted an actor without removing it from the world");
            LOG_GAME_ERROR("You are running a nullptr in the world actors list, maybe somewhere you deleted an actor without removing it from the world");
            continue;
        }
        
        actor->update(deltaTime);
    }
}

void World::HandleEventsTick(const sf::Event& event)
{
    for (const auto& actor : m_actors)
    {
        if (actor == nullptr)
        {
            SPDLOG_ERROR("You are running a nullptr in the world actors list, maybe somewhere you deleted an actor without removing it from the world");
            LOG_GAME_ERROR("You are running a nullptr in the world actors list, maybe somewhere you deleted an actor without removing it from the world");
            continue;
        }
        
        actor->handleEvent(event);
    }
}

void World::RenderTick(sf::RenderWindow& window)
{
    for (auto drawable : m_drawables)
    {
        if (drawable == nullptr)
        {
            SPDLOG_ERROR("You are runnig a drawable item nullptr in the render list");
            LOG_GAME_ERROR("You are runnig a drawable item nullptr in the render list");
            continue;
        }
        window.draw(*drawable);
    }
}

void World::AddObjectToRenderTick(sf::Drawable* drawable)
{
    if (drawable == nullptr)
    {
        SPDLOG_ERROR("You are trying to add a nullptr to the render list, please check your drawable life circle");
        LOG_GAME_ERROR("You are trying to add a nullptr to the render list, please check your drawable life circle");
        return;
    }

    m_drawables.push_back(drawable);
}

void World::AddActorToWorld(Actor* actor)
{
    if (actor == nullptr)
    {
        SPDLOG_ERROR("You are trying to add a nullptr to the world actor, please check your actor life circle");
        LOG_GAME_ERROR("You are trying to add a nullptr to the world actor, please check your actor life circle");
        return;
    }

    m_actors.push_back(actor);
}

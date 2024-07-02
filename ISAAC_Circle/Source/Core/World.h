#pragma once
#include <vector>

class Game;
class Object;

namespace sf
{
    class Drawable;
    class Time;
    class RenderWindow;
    class Event;
}

class World
{
public:
    World(Game* game);
    ~World();
public:
    void Init();
    virtual void UpdateTick(sf::Time deltaTime);
    virtual void HandleEventsTick(const sf::Event& event);
    virtual void RenderTick(sf::RenderWindow& window);

public:
    Game* GetGame() const { return m_game; }
private:
    Game* m_game;

private:
    std::vector<sf::Drawable*> m_drawables;
    std::vector<Object*> m_objects;

public:
    void AddObjectToRenderTick(sf::Drawable* drawable);

    void AddActorToWorld(Object* actor);
};

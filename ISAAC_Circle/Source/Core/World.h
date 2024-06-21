#pragma once

namespace sf
{
    class Time;
}

class World
{
public:
    void Init();
    void UpdateTick(sf::Time deltaTime);
    void HandleEventsTick(sf::Time deltaTime);
    void RenderTick(sf::Time deltaTime);
};

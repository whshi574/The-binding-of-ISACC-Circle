#pragma once
#include "Core/Actor.h"

class Button : public Actor
{
public:
    Button();
    ~Button() override;
public:
    void update(const sf::Time& delta) override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event) override;
};

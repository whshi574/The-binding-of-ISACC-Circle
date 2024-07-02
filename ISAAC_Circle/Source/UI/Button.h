#pragma once
#include "..\Core\Object.h"

class Button : public Object
{
public:
    Button();
    ~Button() override;
public:
    void update(const sf::Time& delta) override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event) override;
};

#pragma once
#include "SFML/Graphics.hpp"

class Actor
{
public:
    Actor(const sf::Vector2f& position) : m_position(position) {}
    
    virtual ~Actor() {}
    
    virtual void update(const sf::Time& delta) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleEvent(const sf::Event& event) {}
    
protected:
    sf::Vector2f m_position;

public:
    virtual void setPosition(const sf::Vector2f& position) { m_position = position; }
    virtual const sf::Vector2f& getPosition() const { return m_position; }
};

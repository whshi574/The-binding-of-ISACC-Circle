#include "Hero.h"
#include "Observer.h"

hero_base::hero_base(const sf::Vector2f& position):Actor(position), health(100), max_health(100)
{
}

void hero_base::cause_damage_to_self(float damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}

void hero_base::heal_self(float amount)
{
    health += amount;
    if (health > max_health)
    {
        health = max_health;
    }
}

void hero_base::register_observer(Observer_Base* observer)
{
    observers.push_back(observer);
}

void hero_base::notify_observers() const
{
    for (const auto observer : observers)
    {
        observer->update();
    }
}

void hero_base::update(const sf::Time& delta)
{
}

void hero_base::render(sf::RenderWindow& window)
{
}

void hero_base::handleEvent(const sf::Event& event)
{
    Actor::handleEvent(event);
}

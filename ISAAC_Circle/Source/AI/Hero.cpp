#include "Hero.h"
#include "Observer.h"

hero_base::hero_base(const sf::Vector2f& position):Actor(position)
{
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

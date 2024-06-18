#pragma once
#include <vector>

#include "Core/Actor.h"

class hero_base: public Actor
{
public:
    explicit hero_base(const sf::Vector2f& position);
    ~hero_base() override=default;

    //register observer
    void register_observer(class Observer_Base* observer);

    //notify all observers
    void notify_observers() const;

    //Actor override
    void update(const sf::Time& delta) override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event) override;
    
private:
    //store observers, only use in Hero class,so don't need to use shared_ptr
    std::vector<class Observer_Base*> observers;
};

#include "Hero.h"
#include "Observer.h"
void hero_base::register_observer(Observer_Base* observer)
{
    observers.push_back(observer);
}

void hero_base::notify_observers() const
{
    for (auto observer : observers)
    {
        observer->update();
    }
}

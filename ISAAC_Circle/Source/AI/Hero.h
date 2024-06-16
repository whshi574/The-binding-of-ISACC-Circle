#pragma once
#include <vector>
class hero_base
{
public:
    hero_base()=default;
    virtual ~hero_base()=default;

    //register observer
    void register_observer(class Observer_Base* observer);

    //notify all observers
    void notify_observers() const;
private:
    //store observers, only use in Hero class,so don't need to use shared_ptr
    std::vector<class Observer_Base*> observers;
};

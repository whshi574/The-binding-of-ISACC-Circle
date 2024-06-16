#pragma once

class Observer_Base
{
public:
    virtual void update() = 0;
    
    Observer_Base() = default;
    virtual ~Observer_Base() = default;
};

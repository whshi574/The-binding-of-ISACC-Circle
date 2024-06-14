#pragma once

namespace sf
{
    class Time;
    class RenderWindow;
}

class AnimationClip
{
protected:
    AnimationClip(float time);

public:
    virtual ~AnimationClip(); // 使基类成为多态类型
    virtual void update(sf::Time delta) = 0;
    virtual void render(sf::RenderWindow& window);
private:
    //A clip of the animation, in seconds.
    float m_time;

public:
    float GetTime() const{ return m_time; }
    void SetTime(float time);
};

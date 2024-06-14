#include "AnimationClip.h"
#include "spdlog/spdlog.h"

AnimationClip::AnimationClip(float time)
{
    m_time = time;
}

AnimationClip::~AnimationClip()
{
}

void AnimationClip::render(sf::RenderWindow& window)
{
    
}


void AnimationClip::SetTime(float time)
{
    if (time < 0.0f)
    {
        SPDLOG_WARN("You are trying to set a negative time for an animation node. This is not allowed.");
        m_time = 0.0f;
        return;
    }
    m_time = time;
}

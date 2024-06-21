#include "AnimationActor.h"
#include <spdlog/spdlog.h>
#include "AnimationSequence.h"
#include "SpriteAnimationClip.h"
#include "Tools/GameLog.h"

AnimationActor::AnimationActor(): Actor(sf::Vector2f(0.0f, 0.0f))
{
    m_clock.restart();
}

AnimationActor::AnimationActor(sf::Vector2f position) : Actor(position)
{
    m_clock.restart();
}

AnimationActor::~AnimationActor()
{
    delete m_animation;
}

void AnimationActor::update(const sf::Time& deltaTime)
{
    if (m_animation == nullptr)
    {
        return;
    }

    if (m_isPlaying)
    {
        m_animation->update(deltaTime);
    }
}

void AnimationActor::render(sf::RenderWindow& window)
{
    if (m_animation == nullptr)
    {
        return;
    }
    
    m_animation->render(window);
}

void AnimationActor::playAnimation(bool loop)
{
    if (m_animation == nullptr)
    {
        SPDLOG_WARN("No animation set for this actor, play animation failed");
        LOG_GAME_ERROR("No animation set for this actor, play animation failed");
        return;
    }

    if (m_isPlaying)
    {
        //Todo:Reset the animation to the beginning
        LOG_GAME_INFO("You are trying to play a animation which is runing");
        m_isLoopPlay = loop;
        return;
    }

    m_isPlaying = true;
    m_isLoopPlay = loop;
    m_animation->play(m_isLoopPlay, true);
}

void AnimationActor::stopAnimation()
{
    
}

void AnimationActor::setPosition(const sf::Vector2f& position)
{
    Actor::setPosition(position);
}

const sf::Vector2f& AnimationActor::getPosition() const
{
    return Actor::getPosition();
}

AnimationSequence* AnimationActor::createAnimationSequence()
{
    if (m_animation)
    {
        SPDLOG_WARN("Animation already exists for this actor, you are trying to create a new one");
        LOG_GAME_WARN("""Animation already exists for this actor, you are trying to create a new one");

        m_isPlaying = false;
        
        //Maybe have some memory problem here?
        delete m_animation;
    }

    m_animation = new AnimationSequence();
    
    return m_animation;
}

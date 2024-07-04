#include "AnimationActor.h"
#include <spdlog/spdlog.h>
#include "AnimationSequence.h"
#include "SpriteAnimationClip.h"
#include "Tools/GameLog.h"
#include <string>

AnimationActor::AnimationActor(): Object(sf::Vector2f(0.0f, 0.0f))
{

}

AnimationActor::AnimationActor(sf::Vector2f position) : Object(position)
{

}

AnimationActor::~AnimationActor()
{
    for (auto& sequence : m_animations)
    {
        delete sequence;
    }
}

void AnimationActor::update(const sf::Time& deltaTime)
{
    for (auto& sequence : m_animations)
    {
        if (sequence == nullptr)
        {
            SPDLOG_ERROR("One sequence in m_animations is nullptr, please check your sequence lifecircle, the sequence will be removed automatically");
            LOG_GAME_ERROR("One sequence in m_animations is nullptr, please check your sequence lifecircle, the sequence will be removed automatically");
            auto it = std::remove(m_animations.begin(), m_animations.end(), sequence);
            m_animations.erase(it, m_animations.end());
            continue;
        }

        if (sequence->isPlayingSequence())
        {
            sequence->update(deltaTime);
        }
    }
}

void AnimationActor::render(sf::RenderWindow& window)
{
    for (auto& sequence : m_animations)
    {
        if (sequence == nullptr)
        {
            SPDLOG_ERROR("One sequence in m_animations is nullptr, please check your sequence lifecircle, the sequence will be removed automatically");
            LOG_GAME_ERROR("One sequence in m_animations is nullptr, please check your sequence lifecircle, the sequence will be removed automatically");
            auto it = std::remove(m_animations.begin(), m_animations.end(), sequence);
            m_animations.erase(it, m_animations.end());
            continue;
        }

        sequence->render(window);
    }
}

void AnimationActor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}

AnimationSequence* AnimationActor::createAnimationSequenceByName(std::string name)
{
    AnimationSequence* newSequence = new AnimationSequence(name);
    m_animations.push_back(newSequence);
    return newSequence;
}

void AnimationActor::removeAnimationSequenceByName(std::string name)
{
    AnimationSequence* removed = getAnimationByName(name);

    if (removed == nullptr)
    {
        SPDLOG_WARN("Sequence not found in m_animations, please check your sequence when remove animation");
        LOG_GAME_WARN("Sequence not found in m_animations, please check your sequence when remove animation");
        return;
    }

    auto it = std::remove(m_animations.begin(), m_animations.end(), removed);
    m_animations.erase(it, m_animations.end());

    delete removed;
}

void AnimationActor::playAnimationByName(std::string name, bool loop, bool fromStart)
{
    for (auto& sequence : m_animations)
    {
        if (sequence->getName() == name)
        {
            playAnimation_SRC(sequence, loop, fromStart);
            return;
        }
    }
    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when play animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when play animation");
}

void AnimationActor::playAnimationBySequence(AnimationSequence* sequence, bool loop, bool fromStart)
{
    for (auto& seq : m_animations)
    {
        if (seq == sequence)
        {
            playAnimation_SRC(seq, loop, fromStart);
            return;
        }
    }
    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when play animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when play animation");
}

void AnimationActor::stopAnimationByName(std::string name)
{
    for (auto& sequence : m_animations)
    {
        if (sequence->getName() == name)
        {
            stopAnimation_SRC(sequence);
            return;
        }
    }

    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
}

void AnimationActor::stopAnimationBySequence(AnimationSequence* sequence)
{
    for (auto& seq : m_animations)
    {
        if (sequence == seq)
        {
            stopAnimation_SRC(sequence);
            return;
        }
    }

    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");

}

void AnimationActor::showAnimationByName(std::string name, bool isShow)
{
    for (auto& sequence : m_animations)
    {
        if (sequence->getName() == name)
        {
            showAnimation_SRC(sequence, isShow);
            return;
        }
    }

    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
}

void AnimationActor::showAnimationBySequence(AnimationSequence* sequence, bool isShow)
{
    for (auto& seq : m_animations)
    {
        if (sequence == seq)
        {
            stopAnimation_SRC(sequence);
            return;
        }
    }

    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when stop animation");
}

AnimationSequence* AnimationActor::getAnimationByName(std::string name)
{
    for (auto& sequence : m_animations)
    {
        if (sequence->getName() == name)
        {
            return sequence;
        }
    }

    SPDLOG_ERROR("Sequence not found in m_animations, please check your sequence when find animation");
    LOG_GAME_ERROR("Sequence not found in m_animations, please check your sequence when find animation");
    return nullptr;
}

void AnimationActor::playAnimation_SRC(AnimationSequence* sequence, bool loop, bool fromStart)
{
    if (sequence == nullptr)
    {
        SPDLOG_WARN("No animation set for this actor, play animation failed");
        LOG_GAME_ERROR("No animation set for this actor, play animation failed");
        auto it = std::remove(m_animations.begin(), m_animations.end(), sequence);
        m_animations.erase(it, m_animations.end());
        return;
    }
    
    sequence->play(loop, fromStart);
}

void AnimationActor::stopAnimation_SRC(AnimationSequence* sequence)
{
    if (sequence == nullptr)
    {
        SPDLOG_WARN("No animation set for this actor, stop animation failed");
        LOG_GAME_ERROR("No animation set for this actor, stop animation failed");
        auto it = std::remove(m_animations.begin(), m_animations.end(), sequence);
        m_animations.erase(it, m_animations.end());
        return;
    }

    sequence->stop();
}

void AnimationActor::showAnimation_SRC(AnimationSequence* sequence, bool isShow)
{
    if (sequence == nullptr)
    {
        SPDLOG_WARN("No animation set for this actor, stop animation failed");
        LOG_GAME_ERROR("No animation set for this actor, stop animation failed");
        auto it = std::remove(m_animations.begin(), m_animations.end(), sequence);
        m_animations.erase(it, m_animations.end());
        return;
    }

    sequence->setIsRendered(isShow);
}

void AnimationActor::setPosition(const sf::Vector2f& position)
{
    Object::setPosition(position);
}

const sf::Vector2f& AnimationActor::getPosition() const
{
    return Object::getPosition();
}

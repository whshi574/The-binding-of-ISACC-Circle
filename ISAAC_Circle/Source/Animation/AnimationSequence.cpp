#include "AnimationSequence.h"
#include <spdlog/spdlog.h>
#include "AnimationClip.h"
#include "SpriteAnimationClip.h"
#include "Tools/GameLog.h"

AnimationSequence::AnimationSequence()
{
    LOG_GAME_INFO("One Animation sequence created.");
}

AnimationSequence::~AnimationSequence()
{
    LOG_GAME_INFO("One Animation sequence destroyed.");
}

void AnimationSequence::addClip(std::unique_ptr<AnimationClip> node)
{
    if (node == nullptr)
    {
        SPDLOG_ERROR("Cannot add a nullptr node to the animation sequence, add node to the sequence failed.");
        LOG_GAME_ERROR("Cannot add a nullptr node to the animation sequence, add node to the sequence failed.");
        return;
    }
    
    seqContainer.push_back(std::move(node));
}

void AnimationSequence::nextClip()
{
    if ((currentIndex+1) >= seqContainer.size())
    {
        if (isLooping)
        {
            currentIndex = 0;
        }else
        {
            isPlaying = false;
            stop();
        }
        return;
    }
    currentIndex++;
}

void AnimationSequence::update(sf::Time delta)
{
    if (isPlaying)
    {
        if (playClock->getElapsedTime().asSeconds() >= seqContainer[currentIndex]->GetTime())
        {
            nextClip();
            delete playClock;
            if (isPlaying)
            {
                playClock = new sf::Clock();
            }
        }
    }
    
    getNode<AnimationClip>(currentIndex)->update(delta);
}

void AnimationSequence::render(sf::RenderWindow& window)
{
    getNode<AnimationClip>(currentIndex)->render(window);
}

void AnimationSequence::play(bool loop, bool fromStart)
{
    if (fromStart)
    {
        delete nowPlayingTime;
        nowPlayingTime = new sf::Time(sf::seconds(0));
    }
    
    isLooping = loop;
    isPlaying = true;

    delete playClock;
    playClock = new sf::Clock();
}

void AnimationSequence::stop()
{
    
}

template <typename T>
T* AnimationSequence::getNode(size_t index) const
{
    if (index < seqContainer.size() && index >= 0) {
        return dynamic_cast<T*>(seqContainer[index].get());
    }
    SPDLOG_ERROR("Cannot get node at index, index out of range, get node failed.");
    LOG_GAME_ERROR("Cannot get node at index, index out of range, get node failed.");
    return nullptr;
}

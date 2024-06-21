#pragma once
#include <vector>
#include <memory>

namespace sf
{
    class RenderWindow;
    class Time;
    class Clock;
}

class AnimationClip;

class AnimationSequence
{
public:
    AnimationSequence();
    ~AnimationSequence();
    void addClip(std::unique_ptr<AnimationClip> node);
    void removeClip(size_t index);
    void removeAllClips();
    void removeClip(std::unique_ptr<AnimationClip> node);

    template <typename T>
    T* getNode(size_t index) const;

private:
    std::vector<std::unique_ptr<AnimationClip>> seqContainer;

    // Now playing frame index
    size_t currentIndex = 0;

    bool isPlaying = false;
    bool isLooping = false;

    void nextClip();
    
public:
    void update(sf::Time delta);
    void render(sf::RenderWindow& window);

public:
    void play(bool loop, bool fromStart);
    void stop();

private:
    //This time is used to keep track of the time elapsed in one animation clip, not the hole sequence time tracker.
    sf::Time* nowPlayingTime;
    //This clock is used to keep track of the time elapsed in one animation clip, not the hole sequence time tracker.
    sf::Clock* playClock;

};

#pragma once
#include "..\Core\Object.h"

/*
 * This class is created to play begin animations for the game.
 */
class AnimationSequence;

class AnimationActor : public Object
{
public:
    AnimationActor();
    AnimationActor(sf::Vector2f position);
    ~AnimationActor();
    
    virtual void update(const sf::Time& deltaTime) override;
    virtual void render(sf::RenderWindow& window) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    AnimationSequence* m_animation;
    bool m_isPlaying = false;
    bool m_isLoopPlay = true;

public:
    AnimationSequence* createAnimationSequence();
    
    void playAnimation(bool loop, bool fromStart);
    void stopAnimation();

    void setPosition(const sf::Vector2f& position) override;
    const sf::Vector2f& getPosition() const override;
    
};


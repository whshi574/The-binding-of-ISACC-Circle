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
    std::vector<AnimationSequence*> m_animations;

public:
    AnimationSequence* createAnimationSequenceByName(std::string name);
    void removeAnimationSequenceByName(std::string name);

    void playAnimationByName(std::string name, bool loop = true, bool fromStart = true);
    void playAnimationBySequence(AnimationSequence* sequence, bool loop = true, bool fromStart = true);
    
    void stopAnimationByName(std::string name);
    void stopAnimationBySequence(AnimationSequence* sequence);

    void showAnimationByName(std::string name, bool isShow);
    void showAnimationBySequence(AnimationSequence* sequence, bool isShow);

    AnimationSequence* getAnimationByName(std::string name);

    void setPosition(const sf::Vector2f& position) override;
    const sf::Vector2f& getPosition() const override;

private:
    void playAnimation_SRC(AnimationSequence* sequence, bool loop, bool fromStart);
    void stopAnimation_SRC(AnimationSequence* sequence);
    void showAnimation_SRC(AnimationSequence* sequence, bool isShow);
};
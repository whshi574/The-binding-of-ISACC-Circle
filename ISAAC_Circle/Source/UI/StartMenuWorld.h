#pragma once
#include <SFML/System/Vector2.hpp>

#include "Core/World.h"


class SwingingSprite;
class AnimationSequence;
class AnimationActor;
class SpriteContainer;

namespace sf
{
    class Sprite;
    class Texture;
}

class StartMenuWorld : public World
{
public:
    StartMenuWorld(Game* game);
    ~StartMenuWorld();

public:
    virtual void UpdateTick(sf::Time deltaTime) override;
    virtual void RenderTick(sf::RenderWindow& window) override;
    virtual void HandleEventsTick(const sf::Event& event) override;

private:
    void LoadAndSetTextures();
private:
    //Start Menu
    sf::Texture* textureTitleMenu;
    sf::Sprite* spriteTitleBG;
    sf::Sprite* spriteTitle;
    SwingingSprite* spriteTitleSwing;
    sf::Sprite* spriteStartButton_0;
    sf::Sprite* spriteStartButton_1;
    AnimationActor* startButtonActor;
    SpriteContainer* titleContainer;

    //Play Menu
    SpriteContainer* playMenuContainer;
    sf::Texture* texturePlayMenu;
    sf::Sprite* playMenuBG;
    sf::Sprite* playMenuNewRunButton;
    sf::Sprite* playMenuContinueButton;
    sf::Sprite* playMenuChallengeButton;
    sf::Sprite* playMenuStatsButton;
    sf::Sprite* playMenuOptionsButton;
    sf::Sprite* playMenuBeChooesedArrow;

private:
    void startMenuInAnimation(SpriteContainer* container, sf::Vector2f startPos);
    void startMenuOutAnimation(SpriteContainer* container, sf::Vector2f targetPos);
    
    void playMenuInAnimationTick(sf::Time deltaTime);
    void playMenuOutAnimationTick(sf::Time deltaTime);

    sf::Vector2f upAnimationPos;
    sf::Vector2f downAnimationPos;
    sf::Vector2f leftAnimationPos;
    sf::Vector2f rightAnimationPos;
    sf::Vector2f middleAnimationPos;
    
    SpriteContainer* inAnimationContainer;
    sf::Vector2f inAnimationStartPos;
    sf::Vector2f inAnimationTargetPos;
    
    SpriteContainer* outAnimationContainer;
    sf::Vector2f outAnimationStartPos;
    sf::Vector2f outAnimationTargetPos;

    bool isplayMenuInAnimating = false;
    bool isplayMenuOutAnimating = false;
};

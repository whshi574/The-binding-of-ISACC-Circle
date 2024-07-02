#pragma once
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
    sf::Texture* textureTitleMenu;
    
    sf::Sprite* spriteTitleBG;
    sf::Sprite* spriteTitle;
    SwingingSprite* spriteTitleSwing;
    
    sf::Sprite* spriteStartButton_0;
    sf::Sprite* spriteStartButton_1;

    AnimationActor* startButtonActor;

    SpriteContainer* titleContainer;
};

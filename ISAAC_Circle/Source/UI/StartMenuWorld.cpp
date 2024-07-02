#include "StartMenuWorld.h"
#include "Core/Game.h"
#include "SFML/System/Time.hpp"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"
#include "Animation//AnimationActor.h"
#include "Animation/AnimationSequence.h"
#include "Animation/SpriteAnimationClip.h"
#include "Animation/SwingingSprite.h"

StartMenuWorld::StartMenuWorld(Game* game) : World(game)
{
    LoadAndSetTextures();
    
    startButtonActor = new AnimationActor();
    AnimationSequence* tempSequence = startButtonActor->createAnimationSequence();
    tempSequence->addClip(std::make_unique<SpriteAnimationClip>(spriteStartButton_0, 0.15f));
    tempSequence->addClip(std::make_unique<SpriteAnimationClip>(spriteStartButton_1, 0.15f));

    startButtonActor->playAnimation(true,true);
}


StartMenuWorld::~StartMenuWorld()
{
    
}

void StartMenuWorld::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
    startButtonActor->update(deltaTime);
    spriteTitleSwing->UpdateTick(deltaTime);
}

void StartMenuWorld::RenderTick(sf::RenderWindow& window)
{
    World::RenderTick(window);
    startButtonActor->render(window);
}

void StartMenuWorld::HandleEventsTick(const sf::Event& event)
{
    World::HandleEventsTick(event);
    startButtonActor->handleEvent(event);
}

void StartMenuWorld::LoadAndSetTextures()
{
    spriteTitleBG = new sf::Sprite();
    spriteTitle = new sf::Sprite();
    spriteStartButton_0 = new sf::Sprite();
    spriteStartButton_1 = new sf::Sprite();
    textureTitleMenu = new sf::Texture();
    
    loadAndSetSprite(*spriteTitleBG, *textureTitleMenu, "Resource/images/ui/main menu/titlemenu.png");

    TextureParser parser("Resource/images/ui/main menu/titlemenu.json",*textureTitleMenu);

    spriteTitleBG->setTextureRect(parser.GetDataByName("titlemenu_0"));
    AlignedCenterSprite(*spriteTitleBG);
    spriteTitleBG->setScale(4.5,4.5);
    spriteTitleBG->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    AddObjectToRenderTick(spriteTitleBG);

    spriteTitle->setTexture(*textureTitleMenu);
    spriteTitle->setTextureRect(parser.GetDataByName("titlemenu_1"));
    spriteTitle->setScale(2,2);
    AlignedCenterSprite(*spriteTitle);
    spriteTitle->setPosition(GetGame()->GetWindowWidth()/2, spriteTitle->getGlobalBounds().height/2);
    spriteTitleSwing = new SwingingSprite(*spriteTitle, 1.5f, 0.3f);
    AddObjectToRenderTick(spriteTitle);

    int buttonOffset = 70;
    
    spriteStartButton_0->setTexture(*textureTitleMenu);
    spriteStartButton_0->setTextureRect(parser.GetDataByName("titlemenu_2"));
    AlignedCenterSprite(*spriteStartButton_0);
    spriteStartButton_0->setScale(2.5,2.5);
    spriteStartButton_0->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2 + buttonOffset);

    spriteStartButton_1->setTexture(*textureTitleMenu);
    spriteStartButton_1->setTextureRect(parser.GetDataByName("titlemenu_3"));
    AlignedCenterSprite(*spriteStartButton_1);
    spriteStartButton_1->setScale(2.5,2.5);
    spriteStartButton_1->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2+ buttonOffset);
}

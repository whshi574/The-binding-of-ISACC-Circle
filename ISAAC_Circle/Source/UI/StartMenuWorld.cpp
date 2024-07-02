#include "StartMenuWorld.h"
#include "Core/Game.h"
#include "SFML/System/Time.hpp"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"
#include "Animation//AnimationActor.h"
#include "Animation/AnimationSequence.h"
#include "Animation/SpriteAnimationClip.h"
#include "Animation/SwingingSprite.h"
#include "Core/Component/SpriteContainer.h"

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
    AddObjectToRenderTick(spriteTitleBG);

    spriteTitle->setTexture(*textureTitleMenu);
    spriteTitle->setTextureRect(parser.GetDataByName("titlemenu_1"));
    AlignedCenterSprite(*spriteTitle);
    spriteTitleSwing = new SwingingSprite(*spriteTitle, 0.f, 0.1f,1.5f, 0.3f);
    AddObjectToRenderTick(spriteTitle);

    int buttonOffset = 70;
    
    spriteStartButton_0->setTexture(*textureTitleMenu);
    spriteStartButton_0->setTextureRect(parser.GetDataByName("titlemenu_2"));
    AlignedCenterSprite(*spriteStartButton_0);

    spriteStartButton_1->setTexture(*textureTitleMenu);
    spriteStartButton_1->setTextureRect(parser.GetDataByName("titlemenu_3"));
    AlignedCenterSprite(*spriteStartButton_1);

    titleContainer = new SpriteContainer();

    titleContainer->addSprite(*spriteTitleBG, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    titleContainer->addSprite(*spriteTitle, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    titleContainer->addSprite(*spriteStartButton_0, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    titleContainer->addSprite(*spriteStartButton_1, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);

    titleContainer->setPosition(sf::Vector2f(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2));
    titleContainer->setScale(4.f,4.f);

    float titleY = (GetGame()->GetWindowHeight()/2 - 150);
    titleY *= -1.f;
    titleContainer->setRelativePosition(*spriteTitle, sf::Vector2f(0, titleY));
    titleContainer->setRelativeScale(*spriteTitle, sf::Vector2f(0.8f, 0.8f));
}
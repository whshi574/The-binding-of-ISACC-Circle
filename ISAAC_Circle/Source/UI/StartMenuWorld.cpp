#include "StartMenuWorld.h"

#include <spdlog/spdlog.h>

#include "Core/Game.h"
#include "SFML/System/Time.hpp"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"
#include "Animation//AnimationActor.h"
#include "Animation/AnimationSequence.h"
#include "Animation/SpriteAnimationClip.h"
#include "Animation/SwingingSprite.h"
#include "Core/Component/SpriteContainer.h"
#include "Tools/GameLog.h"
#include "Tools/MathUtils.h"

StartMenuWorld::StartMenuWorld(Game* game) : World(game)
{
    //Todo: Resoulution change maybe need to update the value
    float x = GetGame()->GetWindowHeight();
    x = x *(-1);
    upAnimationPos = sf::Vector2f(GetGame()->GetWindowWidth()/2, x);
    downAnimationPos = sf::Vector2f(GetGame()->GetWindowWidth()/2, 3*GetGame()->GetWindowHeight()/2 );
    leftAnimationPos = sf::Vector2f(-2*GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2 );
    rightAnimationPos = sf::Vector2f(3*GetGame()->GetWindowWidth()/2, -2*GetGame()->GetWindowHeight()/2 );
    middleAnimationPos = sf::Vector2f(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2 );
    
    LoadAndSetTextures();
    
    startButtonActor = new AnimationActor();
    AnimationSequence* tempSequence = startButtonActor->createAnimationSequenceByName("ShakeTitle");
    tempSequence->addClip(std::make_unique<SpriteAnimationClip>(spriteStartButton_0, 0.15f));
    tempSequence->addClip(std::make_unique<SpriteAnimationClip>(spriteStartButton_1, 0.15f));

    startButtonActor->playAnimationByName("ShakeTitle",true,true);
}


StartMenuWorld::~StartMenuWorld()
{
    
}

void StartMenuWorld::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
    startButtonActor->update(deltaTime);
    spriteTitleSwing->UpdateTick(deltaTime);
    playMenuInAnimationTick(deltaTime);
    playMenuOutAnimationTick(deltaTime);
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

    titleContainer->setPosition(middleAnimationPos);
    titleContainer->setScale(4.f,4.f);

    float titleY = (GetGame()->GetWindowHeight()/2 - 150);
    titleY *= -1.f;
    titleContainer->setRelativePosition(*spriteTitle, sf::Vector2f(0, titleY));
    titleContainer->setRelativeScale(*spriteTitle, sf::Vector2f(0.8f, 0.8f));

    //PlayMenu
    playMenuBG = new sf::Sprite();
    texturePlayMenu = new sf::Texture();
    loadAndSetSprite(*playMenuBG, *texturePlayMenu, "Resource/images/ui/main menu/gamemenu.png");
    
    playMenuNewRunButton = new sf::Sprite();
    playMenuChallengeButton = new sf::Sprite();
    playMenuContinueButton = new sf::Sprite();
    playMenuStatsButton = new sf::Sprite();
    playMenuOptionsButton = new sf::Sprite();
    playMenuBeChooesedArrow = new sf::Sprite();

    TextureParser parser_playMenu("Resource/images/ui/main menu/gamemenu.json",*texturePlayMenu);

    playMenuBG->setTextureRect(parser_playMenu.GetDataByName("gamemenu_0"));
    AlignedCenterSprite(*playMenuBG);
    AddObjectToRenderTick(playMenuBG);

    playMenuNewRunButton->setTexture(*texturePlayMenu);
    playMenuNewRunButton->setTextureRect(parser_playMenu.GetDataByName("gamemenu_1"));
    AlignedCenterSprite(*playMenuNewRunButton);
    AddObjectToRenderTick(playMenuNewRunButton);

    playMenuContinueButton->setTexture(*texturePlayMenu);
    playMenuContinueButton->setTextureRect(parser_playMenu.GetDataByName("gamemenu_2"));
    AlignedCenterSprite(*playMenuContinueButton);
    AddObjectToRenderTick(playMenuContinueButton);

    playMenuChallengeButton->setTexture(*texturePlayMenu);
    playMenuChallengeButton->setTextureRect(parser_playMenu.GetDataByName("gamemenu_3"));
    AlignedCenterSprite(*playMenuChallengeButton);
    AddObjectToRenderTick(playMenuChallengeButton);

    playMenuStatsButton->setTexture(*texturePlayMenu);
    playMenuStatsButton->setTextureRect(parser_playMenu.GetDataByName("gamemenu_4"));
    AlignedCenterSprite(*playMenuStatsButton);
    AddObjectToRenderTick(playMenuStatsButton);

    playMenuOptionsButton->setTexture(*texturePlayMenu);
    playMenuOptionsButton->setTextureRect(parser_playMenu.GetDataByName("gamemenu_5"));
    AlignedCenterSprite(*playMenuOptionsButton);
    AddObjectToRenderTick(playMenuOptionsButton);

    playMenuBeChooesedArrow->setTexture(*texturePlayMenu);
    playMenuBeChooesedArrow->setTextureRect(parser_playMenu.GetDataByName("gamemenu_6"));
    AlignedCenterSprite(*playMenuBeChooesedArrow);
    AddObjectToRenderTick(playMenuBeChooesedArrow);

    playMenuContainer = new SpriteContainer();

    playMenuContainer->addSprite(*playMenuBG, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    playMenuContainer->addSprite(*playMenuNewRunButton, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    playMenuContainer->addSprite(*playMenuContinueButton, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    playMenuContainer->addSprite(*playMenuChallengeButton, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    playMenuContainer->addSprite(*playMenuStatsButton, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    playMenuContainer->addSprite(*playMenuOptionsButton, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);
    playMenuContainer->addSprite(*playMenuBeChooesedArrow, sf::Vector2f(0,0), sf::Vector2f(1,1), 0.f);

    float buttonGap = 130.f;
    playMenuContainer->setRelativePosition(*playMenuNewRunButton, sf::Vector2f(0, -buttonGap*2));
    playMenuContainer->setRelativePosition(*playMenuContinueButton, sf::Vector2f(0, -buttonGap*1));
    playMenuContainer->setRelativePosition(*playMenuChallengeButton, sf::Vector2f(0, -buttonGap*0));
    playMenuContainer->setRelativePosition(*playMenuStatsButton, sf::Vector2f(0, buttonGap*1));
    playMenuContainer->setRelativePosition(*playMenuOptionsButton, sf::Vector2f(0, buttonGap*2));
    playMenuContainer->setRelativePosition(*playMenuBeChooesedArrow, sf::Vector2f(-260, -buttonGap*2));
    
    playMenuContainer->setPosition(sf::Vector2f(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2 + 1000));
    playMenuContainer->setScale(4.f,4.f);
    
    startMenuOutAnimation(titleContainer, upAnimationPos);
}

void StartMenuWorld::startMenuInAnimation(SpriteContainer* container, sf::Vector2f startPos)
{
    if (isplayMenuInAnimating)
    {
        
    }
    
    isplayMenuInAnimating = true;
    inAnimationContainer = container;
}

void StartMenuWorld::startMenuOutAnimation(SpriteContainer* container, sf::Vector2f targetPos)
{
    if (isplayMenuOutAnimating)
    {
        
    }
    
    isplayMenuOutAnimating = true;
    outAnimationContainer = container;
    outAnimationStartPos = middleAnimationPos;
    outAnimationTargetPos = targetPos;
}

void StartMenuWorld::playMenuInAnimationTick(sf::Time deltaTime)
{
    if (!isplayMenuInAnimating)
        return;

    if (inAnimationContainer = nullptr)
    {
        SPDLOG_ERROR("Your inAnimationContainer is nullptr when you try to play in animation.");
        LOG_GAME_ERROR("Your inAnimationContainer is nullptr when you try to play in animation.");
        return;
    }

    
}

void StartMenuWorld::playMenuOutAnimationTick(sf::Time deltaTime)
{
    if (!isplayMenuOutAnimating)
        return;

    if (outAnimationContainer == nullptr)
    {
        SPDLOG_ERROR("Your inAnimationContainer is nullptr when you try to play in animation.");
        LOG_GAME_ERROR("Your inAnimationContainer is nullptr when you try to play in animation.");
        return;
    }

    if (MathUtils::approximatelyEqual(outAnimationStartPos, outAnimationTargetPos, 0.01f))
    {
        outAnimationContainer->setPosition(outAnimationTargetPos);
        isplayMenuOutAnimating = false;
    }
    
    if (outAnimationStartPos.x > outAnimationTargetPos.x)
    {
        outAnimationStartPos.x -= 1000.f * deltaTime.asSeconds();
    }else
    {
        outAnimationStartPos.x += 1000.f * deltaTime.asSeconds();
    }

    if (outAnimationStartPos.y > outAnimationTargetPos.y)
    {
        outAnimationStartPos.y -= 1000.f * deltaTime.asSeconds();
    }else
    {
        outAnimationStartPos.y += 1000.f * deltaTime.asSeconds();
    }

    outAnimationContainer->setPosition(outAnimationStartPos);
    SPDLOG_INFO("{0}, {1}", outAnimationStartPos.x, outAnimationStartPos.y);
}

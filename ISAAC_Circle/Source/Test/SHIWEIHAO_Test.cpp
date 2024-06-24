#include "SHIWEIHAO_Test.h"
#include "Animation/AnimationSequence.h"
#include "SFML/System/Time.hpp"
#include "Animation/SpriteAnimationClip.h"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"
#include <memory>

#include "Core/Game.h"

SHIWEIHAO_Test::SHIWEIHAO_Test(Game* game): World(game)
{
    AnimationSequence* pAnimationSequence = m_pAnimationActor.createAnimationSequence();

    // Free memory where?
    sf::Texture pTexture;
    sf::Sprite* pSprite_1 = new sf::Sprite();

    loadAndSetSprite(*pSprite_1, pTexture, "Resource/images/characters/costumes/character_001_isaac.png");
    TextureParser textureParser("Resource/images/characters/costumes/character_001_isaac.json", pTexture);

    pSprite_1->setTextureRect(textureParser.GetDataByName("character_001_isaac_0"));
    pSprite_1->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    AlignedCenterSprite(*pSprite_1);
    pSprite_1->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_1, 0.1f));

    sf::Sprite* pSprite_2 = new sf::Sprite();
    pSprite_2->setTexture(pTexture);
    pSprite_2->setTextureRect(textureParser.GetDataByName("character_001_isaac_2"));
    AlignedCenterSprite(*pSprite_2);
    pSprite_2->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_2->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_2, 0.1f));

    sf::Sprite* pSprite_3 = new sf::Sprite();
    pSprite_3->setTexture(pTexture);
    pSprite_3->setTextureRect(textureParser.GetDataByName("character_001_isaac_3"));
    AlignedCenterSprite(*pSprite_3);
    pSprite_3->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_3->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_3, 0.1f));

    sf::Sprite* pSprite_4 = new sf::Sprite();
    pSprite_4->setTexture(pTexture);
    pSprite_4->setTextureRect(textureParser.GetDataByName("character_001_isaac_4"));
    AlignedCenterSprite(*pSprite_4);
    pSprite_4->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_4->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_4, 0.1f));

    sf::Sprite* pSprite_5 = new sf::Sprite();
    pSprite_5->setTexture(pTexture);
    pSprite_5->setTextureRect(textureParser.GetDataByName("character_001_isaac_5"));
    AlignedCenterSprite(*pSprite_5);
    pSprite_5->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_5->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_5, 0.1f));

    sf::Sprite* pSprite_6 = new sf::Sprite();
    pSprite_6->setTexture(pTexture);
    pSprite_6->setTextureRect(textureParser.GetDataByName("character_001_isaac_6"));
    AlignedCenterSprite(*pSprite_6);
    pSprite_6->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_6->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_6, 0.1f));

    sf::Sprite* pSprite_7 = new sf::Sprite();
    pSprite_7->setTexture(pTexture);
    pSprite_7->setTextureRect(textureParser.GetDataByName("character_001_isaac_7"));
    AlignedCenterSprite(*pSprite_7);
    pSprite_7->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_7->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_7, 0.1f));

    sf::Sprite* pSprite_8 = new sf::Sprite();
    pSprite_8->setTexture(pTexture);
    pSprite_8->setTextureRect(textureParser.GetDataByName("character_001_isaac_8"));
    AlignedCenterSprite(*pSprite_8);
    pSprite_8->setPosition(GetGame()->GetWindowWidth()/2, GetGame()->GetWindowHeight()/2);
    pSprite_8->setScale(2.0f, 2.0f);
    pAnimationSequence->addClip(std::make_unique<SpriteAnimationClip>(pSprite_8, 0.1f));
    
    m_pAnimationActor.playAnimation(true, true);
}

SHIWEIHAO_Test::~SHIWEIHAO_Test()
{
    
}

void SHIWEIHAO_Test::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
    m_pAnimationActor.update(deltaTime);
}

void SHIWEIHAO_Test::RenderTick(sf::RenderWindow& window)
{
    World::RenderTick(window);
    m_pAnimationActor.render(window);
}

void SHIWEIHAO_Test::HandleEventsTick(const sf::Event& event)
{
    World::HandleEventsTick(event);
    m_pAnimationActor.handleEvent(event);
}

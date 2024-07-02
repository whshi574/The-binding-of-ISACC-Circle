#include "Hero.h"

#include <iostream>

#include "Observer.h"
#include "Animation/AnimationSequence.h"
#include "Animation/SpriteAnimationClip.h"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"

hero_base::hero_base(const sf::Vector2f& position):Object(position),
                                                   animation_actor_(std::make_unique<AnimationActor>()),
                                                   velocity_(0.0f, 0.0f),
                                                   speed(0.1f), health(100), max_health(100)

{
    init();
}

void hero_base::cause_damage_to_self(float damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}

void hero_base::heal_self(float amount)
{
    health += amount;
    if (health > max_health)
    {
        health = max_health;
    }
}

void hero_base::register_observer(Observer_Base* observer)
{
    observers.push_back(observer);
}

void hero_base::notify_observers() const
{
    for (const auto observer : observers)
    {
        observer->update();
    }
}

void hero_base::update(const sf::Time& delta)
{
    m_position += velocity_;
    for (const auto& sprite : run_sprites_)
    {
        sprite->setPosition(m_position);
    }
    animation_actor_->update(delta);
}

void hero_base::render(sf::RenderWindow& window)
{
    animation_actor_->render(window);
}

void hero_base::handleEvent(const sf::Event& event)
{
    Object::handleEvent(event);
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
                {
                    velocity_.x = -speed;
                }else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                {
                    velocity_.x = speed;
                }
                
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
                {
                   velocity_.y = -speed;
                }
                else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                {
                    velocity_.y = speed;
                }
                break;
            }
        case sf::Event::KeyReleased:
            {
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                {
                    velocity_.x = 0.0f;
                }else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                {
                    velocity_.y = 0.0f;
                }
                break;
            }
    default:
        break;
    }

            
    animation_actor_->handleEvent(event);
}

void hero_base::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}

void hero_base::init()
{
    LoadAndSetTextures();

    AnimationSequence* run_sequence = animation_actor_->createAnimationSequence();
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[0], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[1], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[2], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[3], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[4], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[5], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[6], 0.15f));
    run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprites_[7], 0.15f));
    
    animation_actor_->playAnimation(true, true);
}

void hero_base::LoadAndSetTextures()
{
    sf::Texture* run_texture=new sf::Texture();
    textures_.push_back(run_texture);
    sf::Sprite* run1_sprite=new sf::Sprite();
    sf::Sprite* run2_sprite=new sf::Sprite();
    sf::Sprite* run3_sprite=new sf::Sprite();
    sf::Sprite* run4_sprite=new sf::Sprite();
    sf::Sprite* run5_sprite=new sf::Sprite();
    sf::Sprite* run6_sprite=new sf::Sprite();
    sf::Sprite* run7_sprite=new sf::Sprite();
    sf::Sprite* run8_sprite=new sf::Sprite();
    loadAndSetSprite(*run1_sprite, *run_texture, "Resource/images/characters/costumes/character_001_isaac.png");
    TextureParser parser("Resource/images/characters/costumes/character_001_isaac.json", *run_texture);

    run1_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_0"));
    run1_sprite->setPosition(m_position.x, m_position.y);
    run1_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run1_sprite);

    run2_sprite->setTexture(*run_texture);
    run2_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_2"));
    run2_sprite->setPosition(m_position.x, m_position.y);
    run2_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run2_sprite);

    run3_sprite->setTexture(*run_texture);
    run3_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_3"));
    run3_sprite->setPosition(m_position.x, m_position.y);
    run3_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run3_sprite);

    run4_sprite->setTexture(*run_texture);
    run4_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_4"));
    run4_sprite->setPosition(m_position.x, m_position.y);
    run4_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run4_sprite);

    run5_sprite->setTexture(*run_texture);
    run5_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_5"));
    run5_sprite->setPosition(m_position.x, m_position.y);
    run5_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run5_sprite);

    run6_sprite->setTexture(*run_texture);
    run6_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_6"));
    run6_sprite->setPosition(m_position.x, m_position.y);
    run6_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run6_sprite);

    run7_sprite->setTexture(*run_texture);
    run7_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_7"));
    run7_sprite->setPosition(m_position.x, m_position.y);
    run7_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run7_sprite);

    run8_sprite->setTexture(*run_texture);
    run8_sprite->setTextureRect(parser.GetDataByName("character_001_isaac_8"));
    run8_sprite->setPosition(m_position.x, m_position.y);
    run8_sprite->setScale(sf::Vector2f(2, 2));
    AlignedCenterSprite(*run8_sprite);
    
    run_sprites_.push_back(run1_sprite);
    run_sprites_.push_back(run2_sprite);
    run_sprites_.push_back(run3_sprite);
    run_sprites_.push_back(run4_sprite);
    run_sprites_.push_back(run5_sprite);
    run_sprites_.push_back(run6_sprite);
    run_sprites_.push_back(run7_sprite);
    run_sprites_.push_back(run8_sprite);
    
}   

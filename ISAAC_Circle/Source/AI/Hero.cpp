#include "Hero.h"

#include <iostream>
#include <spdlog/spdlog.h>

#include "Observer.h"
#include "Animation/AnimationSequence.h"
#include "Animation/SpriteAnimationClip.h"
#include "Core/Gamemanager.h"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"

hero_base::hero_base(const sf::Vector2f& position):Object(position),
                                                   animation_actor_(std::make_unique<AnimationActor>()),
                                                   velocity_(0.0f, 0.0f),
                                                   speed(500.0f), health(100), max_health(100),attack_interval(sf::seconds(2.0f)),attack_distance(200.0f)


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

float hero_base::get_health() const
{
    return health;
}

void hero_base::render(sf::RenderWindow& window)
{
    animation_actor_->render(window);
}

void hero_base::update(const sf::Time& delta)
{
    attack();

    m_position += velocity_ * delta.asSeconds();

    Object::update(delta);

    runSpriteContainer.setPosition(m_position);
    
    animation_actor_->update(delta);
}

void hero_base::handleEvent(const sf::Event& event)
{
    // Object::handleEvent(event);

    // Track the state of the keys
    static bool isLeftPressed = false;
    static bool isRightPressed = false;
    static bool isUpPressed = false;
    static bool isDownPressed = false;

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            isLeftPressed = true;
            velocity_.x = -speed;
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            isRightPressed = true;
            velocity_.x = speed;
        }
        else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            isUpPressed = true;
            velocity_.y = -speed;
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            isDownPressed = true;
            velocity_.y = speed;
        }
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
        {
            isLeftPressed = false;
            if (isRightPressed)
            {
                velocity_.x = speed;
            }
            else
            {
                velocity_.x = 0.0f;
            }
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
        {
            isRightPressed = false;
            if (isLeftPressed)
            {
                velocity_.x = -speed;
            }
            else
            {
                velocity_.x = 0.0f;
            }
        }
        else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            isUpPressed = false;
            if (isDownPressed)
            {
                velocity_.y = speed;
            }
            else
            {
                velocity_.y = 0.0f;
            }
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            isDownPressed = false;
            if (isUpPressed)
            {
                velocity_.y = -speed;
            }
            else
            {
                velocity_.y = 0.0f;
            }
        }
    }
    animation_actor_->handleEvent(event);
}

void hero_base::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}

void hero_base::init()
{
    LoadAndSetTextures();

    AnimationSequence* run_sequence = animation_actor_->createAnimationSequenceByName("Run");

    for (auto& run_sprite : runSpriteContainer.getAllSprites())
    {
        run_sequence->addClip(std::make_unique<SpriteAnimationClip>(run_sprite, 0.15f));
    }
    
    animation_actor_->playAnimationByName("Run", true, true);
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

    runSpriteContainer.addSprite(*run1_sprite);
    runSpriteContainer.addSprite(*run2_sprite);
    runSpriteContainer.addSprite(*run3_sprite);
    runSpriteContainer.addSprite(*run4_sprite);
    runSpriteContainer.addSprite(*run5_sprite);
    runSpriteContainer.addSprite(*run6_sprite);
    runSpriteContainer.addSprite(*run7_sprite);
    runSpriteContainer.addSprite(*run8_sprite);
    
/*  run_sprites_.push_back(run1_sprite);
    run_sprites_.push_back(run2_sprite);
    run_sprites_.push_back(run3_sprite);
    run_sprites_.push_back(run4_sprite);
    run_sprites_.push_back(run5_sprite);
    run_sprites_.push_back(run6_sprite);
    run_sprites_.push_back(run7_sprite);
    run_sprites_.push_back(run8_sprite);*/
    
}

void hero_base::attack()
{
    if (attack_clock.getElapsedTime() >= attack_interval)
    {
        //发动攻击
        sf::Vector2f target_position = Gamemanager::get_instance()->get_attack_target_pos();
        //计算自身与target的距离
        sf::Vector2f direction = target_position - m_position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance <= attack_distance)
        {
            SPDLOG_INFO("Hero attack");
            //计算方向
            const float angle = std::atan2(target_position.y-m_position.y, target_position.x-m_position.x);
            Gamemanager::get_instance()->attack(angle);
            attack_clock.restart();
        }
    }
}

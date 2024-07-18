#include "Enemy.h"
#include <cmath>
#include <iostream>
#include <utility>
#include <spdlog/spdlog.h>

#include "Hero.h"
#include "Animation/AnimationSequence.h"
#include "Animation/SpriteAnimationClip.h"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"

enemy_base::enemy_base(int enemy_type,const sf::Vector2f& position,std::shared_ptr<hero_base> hero_ptr):Object(position),move_direction_(0),
                                                                                               attack_distance_(70), speed(60),
                                                                                               attack_damage_(1), health_(100),
                                                                                               enemy_type_(enemy_type),
                                                                                               attack_target_(
                                                                                                   std::move(hero_ptr)),
                                                                                               animation_actor_(std::make_unique<AnimationActor>()),sprite_container_(std::make_unique<SpriteContainer>())
{
    init();
}

void enemy_base::set_move_speed(float move_speed)
{
    speed=move_speed;
}

float enemy_base::get_move_speed() const
{
    return speed;
}

float enemy_base::get_move_direction() const
{
    return move_direction_;
}


void enemy_base::move(const sf::Time& delta)
{
    move_direction_ = calculate_move_direction();
    const sf::Vector2f temp_vec2(m_position.x+speed*cos(move_direction_)*delta.asSeconds(),m_position.y+speed*sin(move_direction_)*delta.asSeconds());
    setPosition(temp_vec2);
}

void enemy_base::reset()
{
    m_position=sf::Vector2f(0,0);
    move_direction_=0;
    health_=100;
}

void enemy_base::cause_damage_to_hero() const
{
    float hero_health=attack_target_->get_health();
    if(hero_health>0)
        SPDLOG_INFO("Attack target health: {}", attack_target_->get_health());
    attack_target_->cause_damage_to_self(attack_damage_);
}

void enemy_base::cause_damage_to_self(float damage)
{
    health_ -= damage;
}

float enemy_base::calculate_distance()
{
    const float distance=std::sqrt(std::pow(m_position.x-attack_target_->getPosition().x,2)+std::pow(m_position.y-attack_target_->getPosition().y,2));
    return distance;
}

void enemy_base::set_attack_distance(float distance)
{
    attack_distance_=distance;
}

float enemy_base::get_attack_distance() const
{
    return attack_distance_;
}

float enemy_base::calculate_move_direction() const
{
    const float angle = std::atan2(attack_target_->getPosition().y-m_position.y, attack_target_->getPosition().x-m_position.x);
    return angle;
}

void enemy_base::init()
{
    LoadAndSetTextures();

    AnimationSequence* run_sequence = animation_actor_->createAnimationSequenceByName("Run");
    for (auto& sprite : sprite_container_->getAllSprites())
    {
        run_sequence->addClip(std::make_unique<SpriteAnimationClip>(sprite, 0.15f));
    }
    
    animation_actor_->playAnimationByName("Run", true, true);
}

void enemy_base::LoadAndSetTextures()
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

    sprite_container_->addSprite(*run1_sprite);
    sprite_container_->addSprite(*run2_sprite);
    sprite_container_->addSprite(*run3_sprite);
    sprite_container_->addSprite(*run4_sprite);
    sprite_container_->addSprite(*run5_sprite);
    sprite_container_->addSprite(*run6_sprite);
    sprite_container_->addSprite(*run7_sprite);
    sprite_container_->addSprite(*run8_sprite);


    // run_sprites_.push_back(run1_sprite);
    // run_sprites_.push_back(run2_sprite);
    // run_sprites_.push_back(run3_sprite);
    // run_sprites_.push_back(run4_sprite);
    // run_sprites_.push_back(run5_sprite);
    // run_sprites_.push_back(run6_sprite);
    // run_sprites_.push_back(run7_sprite);
    // run_sprites_.push_back(run8_sprite);
}

int enemy_base::get_enemy_type() const
{
    return enemy_type_;
}

void enemy_base::update(const sf::Time& delta)
{
    sprite_container_->setPosition(m_position);
    animation_actor_->update(delta);
    if(calculate_distance()<attack_distance_)
    {
        Attack(delta);
    }else
    {
        move(delta);
    }
}

void enemy_base::render(sf::RenderWindow& window)
{
    animation_actor_->render(window);
}

void enemy_base::handleEvent(const sf::Event& event)
{
    Object::handleEvent(event);
}

void enemy_base::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

bool enemy_base::check_collision(const std::shared_ptr<Bullet_Base> bullet) const
{
    return sprite_container_->getGlobalBounds().intersects(bullet->get_global_bounds());
}

enemy1::enemy1(int enemy_type, const sf::Vector2f& position,std::shared_ptr<hero_base> hero_ptr):enemy_base(enemy_type, position, hero_ptr)
{
}

void enemy1::Attack(const sf::Time& delta)
{
    //do some actions here
    static sf::Time m_attack_interval; // 攻击间隔时间
    static sf::Time m_elapsed_time;    // 已经过去的时
    m_elapsed_time += delta;
    if (m_elapsed_time >= m_attack_interval)
    {
        cause_damage_to_hero();
        //SPDLOG_INFO("Attack target health: {}", attack_target_->get_health());
        m_elapsed_time = sf::Time::Zero;
    }
}

void enemy_base::set_move_direction(float move_direction)
{
    move_direction_=move_direction;
}

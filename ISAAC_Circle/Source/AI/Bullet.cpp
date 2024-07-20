#include "Bullet.h"
#include "Animation/AnimationSequence.h"
#include "Animation/AnimationActor.h"
#include "Animation/SpriteAnimationClip.h"
#include "Tools/SFMLTool.h"
#include "Tools/TextureParser.h"

Bullet_Base::Bullet_Base(const sf::Vector2f& position,float move_direction):Object(position), animation_actor_(std::make_unique<AnimationActor>()),
                                                       move_direction_(move_direction), speed_(200.0f),damage_(10.0f)
{
    init();
}

Bullet_Base::~Bullet_Base()
= default;

void Bullet_Base::render(sf::RenderWindow& window)
{
    animation_actor_->render(window);
}

void Bullet_Base::update(const sf::Time& delta)
{
    Object::update(delta);
    animation_actor_->update(delta);
    move(delta);
    SpriteContainer_.setPosition(m_position);
}

void Bullet_Base::handleEvent(const sf::Event& event)
{
    Object::handleEvent(event);
}

void Bullet_Base::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void Bullet_Base::init()
{
    LoadAndSetTextures();

    AnimationSequence* move_sequence = animation_actor_->createAnimationSequenceByName("Move");

    for (auto& move_sprite : SpriteContainer_.getAllSprites())
    {
        move_sequence->addClip(std::make_unique<SpriteAnimationClip>(move_sprite, 0.15f));
    }
    animation_actor_->playAnimationByName("Move", true, true);
}

void Bullet_Base::LoadAndSetTextures()
{
    auto texture_=new sf::Texture();
    textures_.push_back(texture_);
    auto move_sprite1=new sf::Sprite();
    auto move_sprite2=new sf::Sprite();
    loadAndSetSprite(*move_sprite1, *texture_, "Resource/images/characters/costumes/character_001_isaac.png");
    TextureParser parser("Resource/images/characters/costumes/character_001_isaac.json", *texture_);

    move_sprite1->setTextureRect(parser.GetDataByName("character_001_isaac_0_head"));
    move_sprite1->setPosition(m_position.x, m_position.y);
    move_sprite1->setScale(sf::Vector2f(0.7f, 0.7f));
    AlignedCenterSprite(*move_sprite1);

    move_sprite2->setTexture(*texture_);
    move_sprite2->setTextureRect(parser.GetDataByName("character_001_isaac_1_head"));
    move_sprite2->setPosition(m_position.x, m_position.y);
    move_sprite2->setScale(sf::Vector2f(0.7f, 0.7f));
    AlignedCenterSprite(*move_sprite2);

    SpriteContainer_.addSprite(*move_sprite1);
    SpriteContainer_.addSprite(*move_sprite2);
}

void Bullet_Base::move(const sf::Time& delta)
{
    const sf::Vector2f temp_vec2(m_position.x+speed_*cos(move_direction_)*delta.asSeconds(),m_position.y+speed_*sin(move_direction_)*delta.asSeconds());
    setPosition(temp_vec2);
}

sf::FloatRect Bullet_Base::get_global_bounds() const
{
    return SpriteContainer_.getGlobalBounds();
}

Bullet_Player1::Bullet_Player1(const sf::Vector2f& position,float move_direction):Bullet_Base(position,move_direction)
{
}

Bullet_Player1::~Bullet_Player1()
= default;

void Bullet_Player1::init()
{
}

void Bullet_Player1::LoadAndSetTextures()
{
}

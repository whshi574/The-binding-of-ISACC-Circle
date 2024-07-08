#include "Bullet.h"
#include "Animation/AnimationActor.h"

Bullet_Base::Bullet_Base(const sf::Vector2f& position):Object(position)
{
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
}

void Bullet_Base::handleEvent(const sf::Event& event)
{
    Object::handleEvent(event);
}

Bullet_Player1::Bullet_Player1(const sf::Vector2f& position):Bullet_Base(position)
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

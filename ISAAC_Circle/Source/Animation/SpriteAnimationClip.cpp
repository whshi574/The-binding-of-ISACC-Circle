#include "SpriteAnimationClip.h"
#include <spdlog/spdlog.h>
#include "Tools/SFMLTool.h"

SpriteAnimationClip::SpriteAnimationClip(sf::Sprite* sprite, float time) : AnimationClip(time)
{
    if (sprite == nullptr)
    {
        SPDLOG_WARN("You passed a nullptr to the SpriteAnimationNode constructor. Now you maybe can't use it.");
        return;
    }

    //Create a new sprite and texture with the same texture as the original one
    m_texture = new sf::Texture(*sprite->getTexture());
    m_nowSprite = new sf::Sprite(*sprite);
    m_nowSprite->setTexture(*m_texture);
}

SpriteAnimationClip::~SpriteAnimationClip()
{
    delete m_nowSprite;
    delete m_texture;
}

sf::Sprite* SpriteAnimationClip::getSprite() const
{
    return m_nowSprite;
}

void SpriteAnimationClip::update(sf::Time deltaTime)
{
}

void SpriteAnimationClip::render(sf::RenderWindow& window)
{
    if (m_nowSprite == nullptr)
    {
        return;
    }
    window.draw(*m_nowSprite);
}

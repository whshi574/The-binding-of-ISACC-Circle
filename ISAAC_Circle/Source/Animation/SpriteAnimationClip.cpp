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

    m_nowSprite = new sf::Sprite(*sprite);
}

SpriteAnimationClip::~SpriteAnimationClip()
{
    delete m_nowSprite;
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
        SPDLOG_ERROR("Your SpriteAnimationClip is nullptr. Maybe you sprite in animation cilp is not constant variable. It be freed somewhere when animation is running.");
        return;
    }
    window.draw(*m_nowSprite);
}

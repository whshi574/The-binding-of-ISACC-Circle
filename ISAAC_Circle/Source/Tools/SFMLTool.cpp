#include "SFMLTool.h"
#include <iostream>
#include <spdlog/spdlog.h>

void loadAndSetSprite(sf::Sprite& sprite, sf::Texture& texture, const std::string& filePath)
{
    //Set Game Icon info
    if (texture.loadFromFile(filePath)) {
        sprite.setTexture(texture);
    }
    else {
        // Save error message to log file
        SPDLOG_ERROR("Failed to load texture from file: {}", filePath);
    }
}

void AlignedCenterText(sf::Text& text)
{
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
}

void AlignedCenterSprite(sf::Sprite& sprite)
{
    const sf::FloatRect textBounds = sprite.getLocalBounds();
    sprite.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
}

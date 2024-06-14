#pragma once
#include <SFML/Graphics.hpp>

// Load sprite and align it to center of the screen
void loadAndSetSprite(sf::Sprite& sprite, sf::Texture& texture, const std::string& filePath);

void AlignedCenterText(sf::Text& text);

void AlignedCenterSprite(sf::Sprite& sprite);

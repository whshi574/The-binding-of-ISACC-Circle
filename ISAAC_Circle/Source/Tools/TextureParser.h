#pragma once
#include <string>
#include "SFML/Graphics/Sprite.hpp"
#include "../ThirdParty/nlohmann/json.hpp"

// This class is used to parse a altas texture file and get the sub-texture data from json file and the texture file.
class TextureParser
{
public:
    TextureParser(const std::string jsonFilePath, sf::Sprite& sprite);
    ~TextureParser();
private:
    nlohmann::json* m_jsonData;

    //Unity texture coordinate system is different from SFML's texture coordinate system.
    void ModifyJsonData(sf::Sprite& sprite);
public:
    // Get sub-texture data from json file.
    sf::IntRect GetDataByName(const std::string name);
};

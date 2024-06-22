#pragma once
#include <string>
#include "SFML/Graphics/Sprite.hpp"
#include "../ThirdParty/nlohmann/json.hpp"

// This class is used to parse a altas texture file and get the sub-texture data from json file and the texture file.
class TextureParser
{
public:
    TextureParser(const std::string jsonFilePath, const sf::Texture& source);
    ~TextureParser();
private:
    nlohmann::json* m_jsonData;

    //Unity texture coordinate system is different from SFML's texture coordinate system.
    void ModifyJsonData(const sf::Texture& source);

public:
    void readJsonFile(const std::string jsonFilePath);
public:
    // Get sub-texture data from json file.
    sf::IntRect GetDataByName(const std::string name);

    // Get all sub-texture names from json file. Please provide a empty vector to store the names.
    void GetAllNames(std::vector<std::string>& names);

    // Print all sub-texture names to console quickly.
    void PrintAllNamesToConsole();
};

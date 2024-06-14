#include "TextureParser.h"
#include <fstream>
#include <spdlog/spdlog.h>
#include "GameLog.h"
#include "SFML/Graphics.hpp"


TextureParser::TextureParser(std::string jsonFilePath, sf::Sprite& sprite)
{
    std::ifstream f(jsonFilePath);

    // Check if the file stream is open
    if (!f.is_open()) {
        SPDLOG_ERROR("Open json file failed, please check your texture json file path.");
        LOG_GAME_ERROR("Open json file failed, please check your texture json file path.");
        // Handle the error, perhaps exit the program or throw an exception
        return; // Return an error code indicating failure
    }

    m_jsonData = new nlohmann::json();
    *m_jsonData = nlohmann::json::parse(f);

    ModifyJsonData(sprite);
    
    // Close the file stream, when we're parsing is done
    f.close();
}

TextureParser::~TextureParser()
{
    delete m_jsonData;
}

void TextureParser::ModifyJsonData(sf::Sprite& sprite)
{
    unsigned int spr_x = sprite.getTexture()->getSize().x;
    unsigned int spr_y = sprite.getTexture()->getSize().y;
    
    for (auto& item : (*m_jsonData)["info"])
    {
        unsigned int now_y = item["Y"];
        unsigned int tar_y = spr_y - now_y;
        unsigned int height = item["Height"];
        tar_y = tar_y - height;
        item["Y"] = tar_y;
    }
}

sf::IntRect TextureParser::GetDataByName(const std::string name)
{
    if (m_jsonData == nullptr)
    {
        SPDLOG_ERROR("Json data is null, please check your texture json file path.");
        LOG_GAME_ERROR("Json data is null, please check your texture json file path.");
        return sf::IntRect{0,0,0,0};
    }

    int count = 0;

    //auto& item = (*m_jsonData)["info"][name];
    
    for (auto& item : (*m_jsonData)["info"])
    {
        count++;
        if (item["Name"] == name) {
            SPDLOG_INFO("Find texture data by name: {}", name);
            return sf::IntRect{item["X"], item["Y"], item["Width"], item["Height"]};
        }
    }

    if (count == 0)
    {
        SPDLOG_ERROR("Json data is empty, please check your texture json file content, this parser rules is check [info] data array.");
        LOG_GAME_ERROR("Json data is empty, please check your texture json file content, this parser rules is check [info] data array.");
        return sf::IntRect{0,0,0,0};
    }

    SPDLOG_ERROR("Can't find your data by name: {}, please check your texture json file content or your input name.", name);
    LOG_GAME_ERROR("Can't find your data by name: {}, please check your texture json file content or your input name.", name);
    return sf::IntRect{0,0,0,0};
}

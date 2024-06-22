#include "TextureParser.h"
#include <fstream>
#include <spdlog/spdlog.h>
#include "GameLog.h"
#include "SFML/Graphics.hpp"


TextureParser::TextureParser(std::string jsonFilePath, const sf::Texture& source)
{
    readJsonFile(jsonFilePath);
    ModifyJsonData(source);
}

TextureParser::~TextureParser()
{
    delete m_jsonData;
}

void TextureParser::ModifyJsonData( const sf::Texture& source)
{
    unsigned int spr_x = source.getSize().x;
    unsigned int spr_y = source.getSize().y;
    
    for (auto& item : (*m_jsonData)["info"])
    {
        unsigned int now_y = item["Y"];
        unsigned int tar_y = spr_y - now_y;
        unsigned int height = item["Height"];
        tar_y = tar_y - height;
        item["Y"] = tar_y;
    }
}

void TextureParser::readJsonFile(const std::string jsonFilePath)
{
    std::ifstream f(jsonFilePath);

    // Check if the file stream is open
    if (!f.is_open()) {
        SPDLOG_ERROR("Open json file failed, please check your texture json file path.");
        LOG_GAME_ERROR("Open json file failed, please check your texture json file path.");
        // Handle the error, perhaps exit the program or throw an exception
        return; // Return an error code indicating failure
    }

    if (m_jsonData != nullptr){
        //You are trying to override a json data
        SPDLOG_WARN("You are trying to override a json data.");
        LOG_GAME_WARN("You are trying to override a json data.");
        delete m_jsonData;
    }

    m_jsonData = new nlohmann::json();
    *m_jsonData = nlohmann::json::parse(f);

    // Close the file stream, when we're parsing is done
    f.close();
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

void TextureParser::GetAllNames(std::vector<std::string>& names)
{
    if (m_jsonData == nullptr)
    {
        SPDLOG_ERROR("Json data is null, please check your texture json file path.");
        LOG_GAME_ERROR("Json data is null, please check your texture json file path.");
        return;
    }

    names.clear();

    for (auto& item : (*m_jsonData)["info"])
    {
        names.push_back(item["Name"]);
    }
}

void TextureParser::PrintAllNamesToConsole()
{
    if (m_jsonData == nullptr)
    {
        SPDLOG_ERROR("Json data is null, please check your texture json file path.");
        LOG_GAME_ERROR("Json data is null, please check your texture json file path.");
        return;
    }

    for (auto& item : (*m_jsonData)["info"])
    {
        std::string name = item["Name"];
        SPDLOG_INFO("Sub Texture Name: {}", name);
    }
}

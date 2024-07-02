#include <SFML/Graphics.hpp>
#include "Core/Game.h"
#include "Tools/GameLog.h"

int main()
{
    //Set console log format
    spdlog::set_pattern("%^[%Y-%m-%d %H:%M:%S] [%l] [Thread:%t] [%s] [%!] %v");
    
    
    //Game start message
    LOG_GAME(spdlog::level::info, "----------START----------");
    
    //Initialize the game
    Game game("Isaac : Circle", 1920, 1080, "Resource/images/ui/loadimages/loadimages-024.png");
    game.runLoop();
    
    //Game end message
    LOG_GAME(spdlog::level::info, "-----------END---------");
    
    return 0;
}
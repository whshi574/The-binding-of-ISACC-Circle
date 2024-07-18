#include "LUOJIAWEN_Test.h"

#include <iostream>
#include <spdlog/spdlog.h>

#include "AI/Factory.h"
#include "SFML/System/Time.hpp"
#include "Core/Game.h"
#include "Core/Gamemanager.h"
LUOJIAWEN_Test::LUOJIAWEN_Test(Game* game): World(game),
timeSinceLastCall_create_enemy(sf::Time::Zero),create_enemy_interval(sf::seconds(2.0f))
{
    gamemanager_=Gamemanager::get_instance();
}
LUOJIAWEN_Test::~LUOJIAWEN_Test()
{
    
}

void LUOJIAWEN_Test::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
    
    gamemanager_->update(deltaTime);
    create_enemy();
}

void LUOJIAWEN_Test::RenderTick(sf::RenderWindow& window)
{
    World::RenderTick(window);
    
    gamemanager_->render(window);
}

void LUOJIAWEN_Test::HandleEventsTick(const sf::Event& event)
{
    World::HandleEventsTick(event);
    gamemanager_->handle_event(event);
}

void LUOJIAWEN_Test::create_enemy()
{
    sf::Time elapsed=clock.getElapsedTime();
    //static bool get=false;
    if(elapsed-timeSinceLastCall_create_enemy>create_enemy_interval)
    {
        std::srand(std::time(0));

        // 生成随机的x和y坐标
        float randomX = static_cast<float>(std::rand() % 601); // 0到600之间的随机数
        float randomY = static_cast<float>(std::rand() % 601); // 0到600之间的随机数

        // 使用生成的随机坐标创建敌人
        gamemanager_->CreateEnemy(1, randomX, randomY);
        timeSinceLastCall_create_enemy=elapsed;
    }
}

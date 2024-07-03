#include "LUOJIAWEN_Test.h"

#include <iostream>
#include <spdlog/spdlog.h>

#include "AI/Factory.h"
#include "SFML/System/Time.hpp"
#include "Core/Game.h"
#include "Core/Gamemanager.h"
LUOJIAWEN_Test::LUOJIAWEN_Test(Game* game): World(game),gamemanager_(std::make_unique<Gamemanager>()),
timeSinceLastCall_create_enemy(sf::Time::Zero),create_enemy_interval(sf::seconds(2.0f))
{
    factory_hero* factory_hero_ =new factory_hero();
    hero=factory_hero_->create_object(1,sf::Vector2f(GetGame()->GetWindowWidth()/2,GetGame()->GetWindowHeight()/2));
    delete factory_hero_;
}
LUOJIAWEN_Test::~LUOJIAWEN_Test()
{
    
}

void LUOJIAWEN_Test::UpdateTick(sf::Time deltaTime)
{
    World::UpdateTick(deltaTime);
    hero->update(deltaTime);
    gamemanager_->update(deltaTime);
    create_enemy();
}

void LUOJIAWEN_Test::RenderTick(sf::RenderWindow& window)
{
    World::RenderTick(window);
    hero->render(window);
    gamemanager_->render(window);
}

void LUOJIAWEN_Test::HandleEventsTick(const sf::Event& event)
{
    World::HandleEventsTick(event);
    hero->handleEvent(event);
}

void LUOJIAWEN_Test::create_enemy()
{
    sf::Time elapsed=clock.getElapsedTime();
    if(elapsed-timeSinceLastCall_create_enemy>create_enemy_interval)
    {
        SPDLOG_INFO("LUOJIAWEN_Test::create_enemy");
        std::srand(std::time(0));

        // 生成随机的x和y坐标
        float randomX = static_cast<float>(std::rand() % 601); // 0到600之间的随机数
        float randomY = static_cast<float>(std::rand() % 601); // 0到600之间的随机数

        // 使用生成的随机坐标创建敌人
        gamemanager_->CreateEnemy(1, randomX, randomY);
        timeSinceLastCall_create_enemy=elapsed;
    }
}

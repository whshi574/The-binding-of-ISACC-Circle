#pragma once
#include "SFML/Graphics.hpp"
#include <thread>

class AnimationActor;
class World;

/* Game.h
 * 
 */
class Game
{
public:
    Game();
    Game(const std::string windowTitle, const unsigned int windowWidth, const unsigned int windowHeight);
    Game(const std::string windowTitle, const unsigned int windowWidth, const unsigned int windowHeight, const std::string iconPath);
    ~Game();

public:
    void runLoop();
    void init();
    
private:
    void renderTick(sf::Time deltaTime);
    void updateTick(sf::Time deltaTime);
    void handleEventsTick(sf::Time deltaTime);

private:
    std::thread updateThread;
    std::thread eventsThread;
    
private:
    sf::RenderWindow* m_window;
    std::string m_windowTitle;
    unsigned int m_windowWidth;
    unsigned int m_windowHeight;
    sf::Image* m_icon;
    sf::Clock m_TickClock;
    sf::Time deltaTime;
    sf::Vector2u m_windowResolution;

public:
    sf::RenderWindow* GetWindow() const;
    std::string GetWindowTitle() const;
    unsigned int GetWindowWidth() const;
    unsigned int GetWindowHeight() const;
    sf::Time GetDeltaTime() const;
    sf::Vector2u GetWindowResolution() const;




//------Debug------//
public:
    AnimationActor* m_animationActor;

    bool isSHIWEIHAO_TestWorld;    
    World* SHIWEIHAO_TestWorld;
    World* LUOJIAWEN_TestWorld;
};

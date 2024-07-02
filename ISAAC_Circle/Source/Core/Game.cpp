#include "Game.h"
#include "spdlog/spdlog.h"
#include "Animation\SpriteAnimationClip.h"
#include "Tools\SFMLTool.h"
#include "Tools\GameLog.h"
#include "Tools\TextureParser.h"
#include "Core\World.h"
#include "Test/LUOJIAWEN_Test.h"
#include "Test/SHIWEIHAO_Test.h"
#include "UI/StartMenuWorld.h"

Game::Game():
m_windowTitle("Default Game"),
m_windowWidth(800),
m_windowHeight(600)
{
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowTitle);
    m_windowResolution.x = m_windowWidth;
    m_windowResolution.y = m_windowHeight;
}

Game::Game(const std::string windowTitle, const unsigned windowWidth, const unsigned windowHeight)
{
    m_windowTitle = windowTitle;
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowTitle);
    m_windowResolution.x = m_windowWidth;
    m_windowResolution.y = m_windowHeight;
}

Game::Game(const std::string windowTitle, const unsigned windowWidth, const unsigned windowHeight,
    const std::string iconPath)
{
    m_windowTitle = windowTitle;
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;

    m_icon = new sf::Image();
    
    if (!m_icon->loadFromFile(iconPath))
    {
        SPDLOG_ERROR("Failed to load icon from file");
        LOG_GAME(spdlog::level::err, "Failed to load icon from file");
    }
    
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowTitle);
    m_window->setIcon(m_icon->getSize().x, m_icon->getSize().y, m_icon->getPixelsPtr());
    m_windowResolution.x = m_windowWidth;
    m_windowResolution.y = m_windowHeight;
}

Game::~Game()
{
    delete m_window;

    if (m_icon!= nullptr)
    {
        delete m_icon;
    }


}

void Game::runLoop()
{
    init();
    
    if (m_window == nullptr)
    {
        SPDLOG_ERROR("No Render window is created");
        LOG_GAME(spdlog::level::err, "No Render window is created");
        return;
    }
    
    LOG_GAME(spdlog::level::info, "Game loop started");
    
    while (m_window->isOpen())
    {
        deltaTime = m_TickClock.restart();

        handleEventsTick(deltaTime);
        updateTick(deltaTime);
        renderTick(deltaTime);
    }

    LOG_GAME(spdlog::level::info, "Game loop ended");
}

void Game::init()
{
    //---------------DEBUG CODE----------------
    //LUO JIA WEN change bool to use different world
    SHIWEIHAO_TestWorld = new SHIWEIHAO_Test(this);
    LUOJIAWEN_TestWorld = new LUOJIAWEN_Test(this);
    STARTWORLD = new StartMenuWorld(this);

    SetWindowMode(sf::VideoMode(m_windowWidth, m_windowHeight), false);
    //---------------END DEBUG CODE------------
}


void Game::renderTick(sf::Time deltaTime)
{
    m_window->clear();
    //---------------DEBUG CODE----------------
    if (isSHIWEIHAO_TestWorld)
    {
        STARTWORLD->RenderTick(*m_window);
    }else
    {
        LUOJIAWEN_TestWorld->RenderTick(*m_window);
    }
    //-------------END DEBUG CODE--------------
    m_window->display();
}

void Game::updateTick(sf::Time deltaTime)
{
    if (isSHIWEIHAO_TestWorld)
    {
        STARTWORLD->UpdateTick(deltaTime);
    }else
    {
        LUOJIAWEN_TestWorld->UpdateTick(deltaTime);
    }

}

void Game::handleEventsTick(sf::Time deltaTime)
{
    sf::Event event;

    while (m_window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window->close();
            break;
        default:
            break;
        }
    }

    if (isSHIWEIHAO_TestWorld)
    {
        STARTWORLD->HandleEventsTick(event);
    }else
    {
        LUOJIAWEN_TestWorld->HandleEventsTick(event);
    }

}

sf::RenderWindow* Game::GetWindow() const
{
    return m_window;
}

std::string Game::GetWindowTitle() const
{
    return m_windowTitle;
}

unsigned Game::GetWindowWidth() const
{
    return m_windowWidth;
}

unsigned Game::GetWindowHeight() const
{
    return m_windowHeight;
}

sf::Time Game::GetDeltaTime() const
{
    return deltaTime;
}

sf::Vector2u Game::GetWindowResolution() const
{
    return m_windowResolution;
}

void Game::SetWindowMode(sf::VideoMode mode, bool isWindowed)
{
    if (!isWindowed)
    {
        m_window->create(mode, m_windowTitle, sf::Style::None);
    }else
    {
        m_window->create(mode, m_windowTitle);
    }
}
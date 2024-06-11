#include "Game.h"
#include "spdlog/spdlog.h"
#include "GameLog.h"

Game::Game():
m_windowTitle("Default Game"),
m_windowWidth(800),
m_windowHeight(600)
{
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowTitle);

    auto logger = spdlog::get("Game_logger");
    
    if (logger)
    {
        logger->info("Game object created");
    }
}

Game::Game(const std::string windowTitle, const unsigned windowWidth, const unsigned windowHeight)
{
    m_windowTitle = windowTitle;
    m_windowWidth = windowWidth;
    m_windowHeight = windowHeight;
    
    m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), m_windowTitle);
    
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
    if (m_window == nullptr)
    {
        SPDLOG_ERROR("No Render window is created");
        return;
    }
    
    while (m_window->isOpen())
    {
        deltaTime = m_TickClock.restart();

        handleEventsTick(deltaTime);
        updateTick(deltaTime);
        renderTick(deltaTime);
    }
}

void Game::renderTick(sf::Time deltaTime)
{
    m_window->clear();
    m_window->display();
}

void Game::updateTick(sf::Time deltaTime)
{
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
}

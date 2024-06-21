#include "Game.h"
#include "spdlog/spdlog.h"
#include "Animation\AnimationActor.h"
#include "Animation\AnimationSequence.h"
#include "Animation\SpriteAnimationClip.h"
#include "Tools\SFMLTool.h"
#include "Tools\GameLog.h"
#include "Tools\TextureParser.h"
#include "Core\World.h"

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

    //----------------DEBUG CODE----------------
    
    m_animationActor = new AnimationActor(sf::Vector2f(m_windowWidth / 2, m_windowHeight / 2));
    AnimationSequence* sequence = m_animationActor->createAnimationSequence();
    
    sf::Sprite sprite_bg;
    sf::Texture texture_bg;
    loadAndSetSprite(sprite_bg, texture_bg, "Resource/images/cutscenes/intro_bg.png");
    sprite_bg.setPosition(sf::Vector2f(m_windowWidth / 2, m_windowHeight / 2));
    sprite_bg.setScale(sf::Vector2f(3.f, 3.f));
    AlignedCenterSprite(sprite_bg);
        
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Sprite sprite1;
    
    loadAndSetSprite(sprite, texture, "Resource/images/cutscenes/intro2.png");
    
    TextureParser textureParser("Resource/images/cutscenes/intro2.json", sprite);

    std::vector<std::string> subTextureNames;
    textureParser.PrintAllNamesToConsole();
    
    sprite.setTextureRect(textureParser.GetDataByName("intro2_0"));
    AlignedCenterSprite(sprite);
    sprite.setScale(sf::Vector2f(2.f, 2.f));
    sprite.setPosition(sf::Vector2f(m_windowWidth / 2, m_windowHeight / 2));
    
    //loadAndSetSprite(sprite1, texture, "Resource/images/cutscenes/intro1.png");
    sprite1.setTexture(texture);
    sprite1.setTextureRect(textureParser.GetDataByName("intro2_1"));
    AlignedCenterSprite(sprite1);
    sprite1.setScale(sf::Vector2f(2.f, 2.f));
    sprite1.setPosition(sf::Vector2f(m_windowWidth / 2, m_windowHeight / 2));
    
    sequence->addClip(std::make_unique<SpriteAnimationClip>(&sprite, 0.1f));
    sequence->addClip(std::make_unique<SpriteAnimationClip>(&sprite1, 0.1f));
    m_animationActor->playAnimation(true);
    
    //---------------END DEBUG CODE-------------
    
    while (m_window->isOpen())
    {
        deltaTime = m_TickClock.restart();

        handleEventsTick(deltaTime);
        updateTick(deltaTime);
        m_window->clear();
        m_window->draw(sprite_bg);
        renderTick(deltaTime);
    }

    LOG_GAME(spdlog::level::info, "Game loop ended");
}

void Game::init()
{
    //---------------DEBUG CODE----------------
    //LUO JIA WEN change bool to use different world
    isSHIWEIHAO_TestWorld = true;
    SHIWEIHAO_TestWorld = new World();
    LUOJIAWEN_TestWorld = new World();
    //---------------END DEBUG CODE------------
}


void Game::renderTick(sf::Time deltaTime)
{
    //m_window->clear();
    //Debug code - need to remove
    if (isSHIWEIHAO_TestWorld)
    {
        SHIWEIHAO_TestWorld->RenderTick(deltaTime);
    }else
    {
        LUOJIAWEN_TestWorld->RenderTick(deltaTime);
    }

    m_animationActor->render(*m_window);
    m_window->display();
}

void Game::updateTick(sf::Time deltaTime)
{
    m_animationActor->update(deltaTime);
    if (isSHIWEIHAO_TestWorld)
    {
        SHIWEIHAO_TestWorld->UpdateTick(deltaTime);
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
        SHIWEIHAO_TestWorld->HandleEventsTick(deltaTime);
    }else
    {
        LUOJIAWEN_TestWorld->HandleEventsTick(deltaTime);
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

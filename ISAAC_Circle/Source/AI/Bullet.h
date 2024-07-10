#pragma once
#include "Core/Object.h"
#include "Core/Component/SpriteContainer.h"

class AnimationActor;

class Bullet_Base:public Object
{
    public:
        Bullet_Base(const sf::Vector2f& position);
        ~Bullet_Base() override;

        //重载父类
        void render(sf::RenderWindow& window) override;
        void update(const sf::Time& delta) override;
        void handleEvent(const sf::Event& event) override;

        
    protected:
        //关于子弹动画
        std::unique_ptr<AnimationActor> animation_actor_;
        std::vector<sf::Texture*>   textures_;
        SpriteContainer SpriteContainer_;

        //关于子弹移动
        float move_direction_;
        float speed_;
        float damage_;
        
    public:
        //子弹基类专属需要子类重载的, 用于初始化子弹的动画
        virtual void init();
        virtual void LoadAndSetTextures();
};

class Bullet_Player1:public Bullet_Base
{
    public:
        Bullet_Player1(const sf::Vector2f& position);
        ~Bullet_Player1() override;
    
        void init() override;
        void LoadAndSetTextures() override;


};
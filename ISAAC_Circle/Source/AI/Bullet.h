#pragma once
#include "Core/Object.h"
#include "Core/Component/SpriteContainer.h"

class AnimationActor;

class Bullet_Base:public Object
{
    public:
        Bullet_Base(const sf::Vector2f& position,float move_direction);
        ~Bullet_Base() override;

        //重载父类
        void render(sf::RenderWindow& window) override;
        void update(const sf::Time& delta) override;
        void handleEvent(const sf::Event& event) override;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        
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

        //用来使子弹移动的函数
        void move(const sf::Time& delta);

        //碰撞相关
        sf::FloatRect get_global_bounds() const;
};

class Bullet_Player1:public Bullet_Base
{
    public:
        Bullet_Player1(const sf::Vector2f& position,float move_direction);
        ~Bullet_Player1() override;
    
        void init() override;
        void LoadAndSetTextures() override;


};
#pragma once
#include <vector>
#include "..\Core\Object.h"
#include "Animation/AnimationActor.h"
#include "Core/Component/SpriteContainer.h"

class hero_base: public Object
{
public:
    explicit hero_base(const sf::Vector2f& position);
    ~hero_base() override=default;

    void cause_damage_to_self(float damage);
    void heal_self(float amount);

    //register observer
    void register_observer(class Observer_Base* observer);

    //notify all observers
    void notify_observers() const;

    float get_health() const;
    //Actor override
    void update(const sf::Time& delta) override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    virtual void init();

    virtual void LoadAndSetTextures();

    //关于攻击的函数
    void attack();
    


    
protected:
    //store observers, only use in Hero class,so don't need to use shared_ptr
    std::vector<class Observer_Base*> observers;

    std::unique_ptr<AnimationActor> animation_actor_;

    std::vector<sf::Texture*>   textures_;
    SpriteContainer runSpriteContainer;
    
    sf::Vector2f velocity_;
    
    float speed;
    
    float health;
    float max_health;

    //关于攻击
    sf::Time attack_interval;
    sf::Clock attack_clock;
    float attack_distance;
    
};

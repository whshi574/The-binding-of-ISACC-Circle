#pragma once
#include <memory>

#include "Core/Actor.h"
#include "SFML/Graphics/Glsl.hpp"

constexpr float PI = 3.14159265358979323846f;
class hero_base;
class enemy_base:public Actor
{
public:
    explicit enemy_base(std::shared_ptr<hero_base> attack_target,const sf::Vector2f& position);
    
    ~enemy_base() override =default;
    
    
    void set_move_speed(float move_speed);
    float get_move_speed() const;
    sf::Glsl::Vec2 get_move_direction() const;
    void set_move_direction(const sf::Glsl::Vec2& vec2);
    
    /**
     * @brief enemy moveFunction
     * 
     * According to the move_direction to calculate the next position
     */
    void move();

        /**
     * @brief enemy Attack Function
     * 
        * Do attack action,yuancheng or jinzhan, so it needs to set to pure virtual 
     */
    virtual void Attack()=0;
    
    void cause_damage_to_hero();

    void cause_damage_to_self(float damage);

    float calculate_distance();
    //Actor override
    void update(const sf::Time& delta) override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event) override;
    
private:
    //Control the Enemy Move Direction
    sf::Glsl::Vec2 move_direction_;
    
    //move speed
    float speed;
    
    //self Damage
    float attack_damage_;
    
    //attack target
    std::shared_ptr<hero_base> attack_target_;
    
    //health
    float health_;
};
class enemy1 : public enemy_base
{
public:
    enemy1(std::shared_ptr<hero_base> attack_target,const sf::Vector2f& position);
    ~enemy1() override =default;
    void Attack() override;
};
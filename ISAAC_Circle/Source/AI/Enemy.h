#pragma once
#include <memory>

#include "..\Core\Object.h"
#include "Animation/AnimationActor.h"
#include "SFML/Graphics/Glsl.hpp"

constexpr float PI = 3.14159265358979323846f;
class hero_base;
class enemy_base:public Object
{
public:
    explicit enemy_base(const sf::Vector2f& position);
    
    ~enemy_base() override =default;
    
    
    void set_move_speed(float move_speed);
    float get_move_speed() const;
    sf::Vector2f get_move_direction() const;
    void set_move_direction(const sf::Vector2f& vec2);
    
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

    void reset();
    
    void cause_damage_to_hero() const;

    void cause_damage_to_self(float damage);

    float calculate_distance();

    void set_attack_distance(float distance);
    float get_attack_distance() const;
    float calculate_move_direction();
    
    virtual void init();

    virtual void LoadAndSetTextures();
    
    //Actor override
    void update(const sf::Time& delta) override;
    void render(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
private:
    //Control the Enemy Move Direction
    sf::Vector2f move_direction_;

    //Attack distance
    float attack_distance_;
    
    //move speed
    float speed;
    
    //self Damage
    float attack_damage_;
    
    //health
    float health_;
    
    std::unique_ptr<AnimationActor> animation_actor_;
    std::vector<sf::Texture*>   textures_;
    std::vector<sf::Sprite*> run_sprites_;
};
class enemy1 : public enemy_base
{
public:
    enemy1(const sf::Vector2f& position);
    ~enemy1() override =default;
    void Attack() override;
};
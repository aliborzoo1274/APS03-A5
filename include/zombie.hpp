#pragma once

#include "global.hpp"
#include "settings.hpp"

class Zombie
{
public:
    Zombie(string type, Vector2f pos);
    void render(RenderWindow &window);
    void update();
    Vector2f get_pos() {return pos;}
    void is_being_damaged(float hit);
    FloatRect get_rect();
    float get_health() {return health;}
    void freeze();
    float get_damage() {return damage;}
    float get_hit_rate() {return hit_rate;}
    Time get_eating_time() {return eating_clock.getElapsedTime();}
    void took_bite() {eating_clock.restart();}
    void is_eating_plant();
    void ate_plant() {is_eating = false;}
private:
    Settings game_settings = settings();
    Clock frozen_clock, eating_clock;
    string type;
    float damage;
    float health;
    float hit_rate;
    float speed;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    bool is_frozen = false;
    bool is_eating = false;
};
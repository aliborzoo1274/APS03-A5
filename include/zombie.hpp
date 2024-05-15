#pragma once

#include "global.hpp"
#include "settings.hpp"

class Zombie
{
public:
    Zombie(Vector2f pos);
    //~Zombie();
    void render(RenderWindow &window);
    void update();
    void damage(float hit);
    FloatRect get_rect();
    float get_health() {return health;}
    void freeze();
private:
    Settings game_settings = settings();
    Clock clock;
    float speed = game_settings.Zombie[3];
    float health = game_settings.Zombie[1];
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    bool is_frozen = false;
};
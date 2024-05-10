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
private: 
    Settings game_settings = settings();
    Clock clock;
    const float speed = game_settings.Zombie[3];
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
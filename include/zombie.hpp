#pragma once

#include "global.hpp"

class Zombie
{
public:
    Zombie(Vector2f pos);
    //~Zombie();
    void render(RenderWindow &window);
    void update();
private: 
    Clock clock;
    const float speed = 0.1;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
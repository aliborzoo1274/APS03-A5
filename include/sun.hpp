#pragma once

#include "global.hpp"

class Sun
{
public:
    Sun(Vector2f pos, float speed);
    void render(RenderWindow &window);
    void update();
    bool is_in_mouse_pos(Vector2i pos);
private: 
    float speed;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
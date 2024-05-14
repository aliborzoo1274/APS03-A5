#pragma once
#include "global.hpp"

class Pea
{
public:
    Pea(Vector2f pos);
    //~Pea();
    void render(RenderWindow &window);
    void update();
    bool is_out();
    FloatRect get_rect();
private:
    const float speed = PROJECTILES_SPEED;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
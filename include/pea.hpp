#pragma once
#include "global.hpp"
#include "settings.hpp"

class Pea
{
public:
    Pea(Vector2f pos);
    void render(RenderWindow &window);
    void update();
    bool is_out();
    FloatRect get_rect();
    float get_damage() {return damage;}
private:
    Settings game_settings = settings();
    const float speed = game_settings.Peashooter[4];
    const float damage = game_settings.Peashooter[0];
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
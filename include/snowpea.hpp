#pragma once
#include "global.hpp"
#include "settings.hpp"

class Snowpea
{
public:
    Snowpea(Vector2f pos);
    void render(RenderWindow &window);
    void update();
    bool is_out();
    FloatRect get_rect();
    float get_damage() {return damage;}
private:
    Settings game_settings = settings();
    const float speed = game_settings.SnowPeashooter[4];
    const float damage = game_settings.SnowPeashooter[0];
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
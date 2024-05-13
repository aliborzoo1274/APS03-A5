#pragma once

#include "global.hpp"

class Plant
{
public:
    Plant(string plant_name, Vector2i pos, vector<float> settings);
    void set_pos(Vector2i pos);
    void render(RenderWindow &window);
private:
    //Clock clock;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
    float damage, health, cooldown;
    float hitrate, speed, price;
};
#pragma once

#include "global.hpp"

class Plant
{
public:
    Plant(vector<float> settings);
    virtual void set_pos(Vector2i pos) = 0;
    virtual void render(RenderWindow &window) = 0;
private:
    //Clock clock;
    float damage, health, cooldown;
    float hitrate, speed, price;
};
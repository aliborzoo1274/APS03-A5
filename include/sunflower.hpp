#pragma once

#include "global.hpp"
#include "plant.hpp"
#include "sun.hpp"

class Sunflower : public Plant
{
public:
    Sunflower(string plant_name, Vector2i pos, vector<float> settings);
    void update();
    //~Sunflower();
    Vector2f make_sun();
private:
    Clock clock;
};
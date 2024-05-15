#pragma once

#include "global.hpp"
#include "plant.hpp"

class Wallnut : public Plant
{
public:
    Wallnut(string plant_name, Vector2i pos, vector<float> settings);
    void update();
};
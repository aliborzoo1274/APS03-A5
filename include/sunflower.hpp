#pragma once

#include "global.hpp"
#include "plant.hpp"

class Sunflower : public Plant
{
public:
    Sunflower(string plant_name, Vector2i pos, vector<float> settings);
    //~Sunflower();
};
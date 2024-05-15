#pragma once

#include "global.hpp"
#include "plant.hpp"

class Snowpeashooter : public Plant
{
public:
    Snowpeashooter(string plant_name, Vector2i pos, vector<float> settings);
    void update();
    Vector2f get_snowpea_pos();
    FloatRect zombie_available();
};
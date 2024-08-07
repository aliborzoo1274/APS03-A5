#pragma once

#include "global.hpp"
#include "plant.hpp"

class Peashooter : public Plant
{
public:
    Peashooter(string plant_name, Vector2i pos, vector<float> settings);
    void update();
    Vector2f get_pea_pos();
    FloatRect zombie_available();
};
#include "sunflower.hpp"

Sunflower::Sunflower(string plant_name, Vector2i pos, vector<float> settings)
          : Plant(plant_name, pos, settings){}

//Sunflower::~Sunflower(){}

void Sunflower::update() {}

Vector2f Sunflower::make_sun()
{
    if (clock.getElapsedTime().asSeconds() >= SUNFLOWER_SUN_MAKE_TIME)
    {
        clock.restart();
        return pos;
    }
    else return {0, 0};
}
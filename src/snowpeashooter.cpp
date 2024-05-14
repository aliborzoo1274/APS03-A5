#include "snowpeashooter.hpp"

Snowpeashooter::Snowpeashooter(string plant_name, Vector2i pos, vector<float> settings)
               : Plant(plant_name, pos, settings){}

//Snowpeashooter::~Snowpeashooter(){}

void Snowpeashooter::update() {}

Vector2f Snowpeashooter::get_snowpea_pos()
{
    return {pos.x + 25.f, pos.y - 35.f};
}
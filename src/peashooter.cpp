#include "peashooter.hpp"

Peashooter::Peashooter(string plant_name, Vector2i pos, vector<float> settings)
           : Plant(plant_name, pos, settings){}

//Peashooter::~Peashooter(){}

void Peashooter::update() {}

Vector2f Peashooter::get_pea_pos()
{
    return {pos.x + 25.f, pos.y - 35.f};
}
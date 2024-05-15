#include "snowpeashooter.hpp"

Snowpeashooter::Snowpeashooter(string plant_name, Vector2i pos, vector<float> settings)
               : Plant(plant_name, pos, settings){}

void Snowpeashooter::update() {}

Vector2f Snowpeashooter::get_snowpea_pos()
{
    return {pos.x + 25.f, pos.y - 35.f};
}

FloatRect Snowpeashooter::zombie_available()
{
    float width = WIDTH;
    float height = 70.f;
    float left = pos.x + 25.f;
    float top = pos.y - 30.f;
    FloatRect direction(left, top, width, height);
    return direction;
}
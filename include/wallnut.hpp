#pragma once

#include "global.hpp"
#include "plant.hpp"

class Wallnut : public Plant
{
public:
    Wallnut(Vector2i pos, vector<float> settings);
    void set_pos(Vector2i pos);
    void render(RenderWindow &window);
    //~Wallnut();
private:
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
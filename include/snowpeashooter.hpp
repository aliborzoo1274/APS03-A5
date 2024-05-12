#pragma once

#include "global.hpp"
#include "plant.hpp"

class Snowpeashooter : public Plant
{
public:
    Snowpeashooter(Vector2i pos, vector<float> settings);
    void set_pos(Vector2i pos);
    void render(RenderWindow &window);
    //~Snowpeashooter();
private:
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
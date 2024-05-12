#pragma once

#include "global.hpp"
#include "plant.hpp"

class Peashooter : public Plant
{
public:
    Peashooter(Vector2i pos, vector<float> settings);
    void set_pos(Vector2i pos);
    void render(RenderWindow &window);
    //~Peashooter();
private:
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
#pragma once

#include "global.hpp"
#include "plant.hpp"

class Sunflower : public Plant
{
public:
    Sunflower(Vector2i pos, vector<float> settings);
    void set_pos(Vector2i pos);
    void render(RenderWindow &window);
    //~Sunflower();
private:
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
#pragma once

#include "global.hpp"
#include "tile.hpp"

class Plant
{
public:
    Plant(string plant_name, Vector2i pos, vector<float> settings);
    void set_pos(Vector2i pos);
    virtual void update() = 0;
    void render(RenderWindow &window);
    Tile* get_tile() {return tile;}
private:
    //Clock clock;
    Texture texture;
    Sprite sprite;
    float damage, health, cooldown;
    float hitrate, speed, price;
    Tile* tile;
};
#pragma once

#include "global.hpp"

class Titan
{
public:
    Titan(Vector2f pos);
    //~Titan();
    void render(RenderWindow &window);
    void update();
private: 
    Clock clock;
    const float speed = 0.075;
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
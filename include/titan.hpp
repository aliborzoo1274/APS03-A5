#pragma once

#include "global.hpp"
#include "settings.hpp"

class Titan
{
public:
    Titan(Vector2f pos);
    //~Titan();
    void render(RenderWindow &window);
    void update();
private:
    Settings game_settings = settings();
    Clock clock;
    const float speed = game_settings.Titan[3];
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
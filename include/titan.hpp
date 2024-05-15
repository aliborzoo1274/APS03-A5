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
    void damage(float hit);
private:
    Settings game_settings = settings();
    Clock clock;
    float speed = game_settings.Titan[3];
    float health = game_settings.Titan[1];
    Texture texture;
    Sprite sprite;
    Vector2f pos;
};
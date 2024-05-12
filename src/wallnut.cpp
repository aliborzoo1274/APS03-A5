#include "wallnut.hpp"

Wallnut::Wallnut(Vector2i pos, vector<float> settings)
           : Plant(settings)
{
    if (!texture.loadFromFile(PICS_PATH + "wall-nut.png"))
        error("failed to load wallnut texture");
    sprite.setTexture(texture);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

//Wallnut::~Wallnut(){}

void Wallnut::set_pos(Vector2i pos)
{
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

void Wallnut::render(RenderWindow &window)
{
    window.draw(sprite);
}
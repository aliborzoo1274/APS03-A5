#include "sunflower.hpp"

Sunflower::Sunflower(Vector2i pos, vector<float> settings)
           : Plant(settings)
{
    if (!texture.loadFromFile(PICS_PATH + "sunflower.png"))
        error("failed to load sunflower texture");
    sprite.setTexture(texture);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

//Sunflower::~Sunflower(){}

void Sunflower::set_pos(Vector2i pos)
{
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

void Sunflower::render(RenderWindow &window)
{
    window.draw(sprite);
}
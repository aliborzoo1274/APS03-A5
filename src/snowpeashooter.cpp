#include "snowpeashooter.hpp"

Snowpeashooter::Snowpeashooter(Vector2i pos, vector<float> settings)
           : Plant(settings)
{
    if (!texture.loadFromFile(PICS_PATH + "snowpeashooter.png"))
        error("failed to load snowpeashooter texture");
    sprite.setTexture(texture);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

//Snowpeashooter::~Snowpeashooter(){}

void Snowpeashooter::set_pos(Vector2i pos)
{
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

void Snowpeashooter::render(RenderWindow &window)
{
    window.draw(sprite);
}
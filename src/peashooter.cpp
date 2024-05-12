#include "peashooter.hpp"

Peashooter::Peashooter(Vector2i pos, vector<float> settings)
           : Plant(settings)
{
    if (!texture.loadFromFile(PICS_PATH + "peashooter.png"))
        error("failed to load peashooter texture");
    sprite.setTexture(texture);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    sprite.setScale(0.6f, 0.6f);
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

//Peashooter::~Peashooter(){}

void Peashooter::set_pos(Vector2i pos)
{
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);
}

void Peashooter::render(RenderWindow &window)
{
    window.draw(sprite);
}
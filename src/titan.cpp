#include "titan.hpp"

Titan::Titan(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "titan.png"))
        error("failed to load zombie texture");
    sprite.setTexture(texture);
    sprite.setScale(0.13f, 0.13f);
}

//Titan::~Titan(){}

void Titan::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Titan::update()
{
    pos.x -= speed;
    sprite.setPosition(pos);
}
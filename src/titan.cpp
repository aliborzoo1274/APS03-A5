#include "titan.hpp"

Titan::Titan(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "titan.png"))
        error("failed to load titan texture");
    sprite.setTexture(texture);
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

void Titan::damage(float hit)
{
    health -= hit;
}
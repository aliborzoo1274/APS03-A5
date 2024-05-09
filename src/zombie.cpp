#include "zombie.hpp"

Zombie::Zombie(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "zombie.png"))
        error("failed to load zombie texture");
    sprite.setTexture(texture);
    sprite.setScale(0.06f, 0.06f);
}

//Zombie::~Zombie(){}

void Zombie::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Zombie::update()
{
    pos.x -= speed;
    sprite.setPosition(pos);
}
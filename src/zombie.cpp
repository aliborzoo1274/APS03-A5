#include "zombie.hpp"

Zombie::Zombie(Vector2f p)
{
    pos = p;
}

//Zombie::~Zombie(){}

void Zombie::render(RenderWindow &window)
{
    string zombie_type = "zombie";
    if (is_frozen) zombie_type += "_frozen";
    if (!texture.loadFromFile(PICS_PATH + zombie_type + ".png"))
        error("failed to load " + zombie_type + " texture");
    sprite.setTexture(texture);
    window.draw(sprite);
}

void Zombie::update()
{
    pos.x -= speed;
    sprite.setPosition(pos);
    if(is_frozen && clock.getElapsedTime().asSeconds() > 5)
    {
        speed *= 2;
        is_frozen = false;
    }
}

FloatRect Zombie::get_rect()
{
    return sprite.getGlobalBounds();
}

void Zombie::damage(float hit)
{
    health -= hit;
}

void Zombie::freeze()
{
    if (!is_frozen)
        speed /= 2;
    clock.restart();
    is_frozen = true;
}
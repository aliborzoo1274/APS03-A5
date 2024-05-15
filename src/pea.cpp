#include "pea.hpp"

Pea::Pea(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "pea.png"))
        error("failed to load pea texture");
    sprite.setTexture(texture);
    sprite.setScale(0.13, 0.13);
}

void Pea::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Pea::update()
{
    pos.x += speed;
    sprite.setPosition(pos);
}

bool Pea::is_out()
{
    return sprite.getPosition().x > WIDTH + 50;
}

FloatRect Pea::get_rect()
{
    return sprite.getGlobalBounds();
}
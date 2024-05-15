#include "snowpea.hpp"

Snowpea::Snowpea(Vector2f p)
{
    pos = p;
    if (!texture.loadFromFile(PICS_PATH + "snowpea.png"))
        error("failed to load snowpea texture");
    sprite.setTexture(texture);
    sprite.setScale(0.13, 0.13);
}

void Snowpea::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Snowpea::update()
{
    pos.x += speed;
    sprite.setPosition(pos);
}

bool Snowpea::is_out()
{
    return sprite.getPosition().x > WIDTH + 50;
}

FloatRect Snowpea::get_rect()
{
    return sprite.getGlobalBounds();
}
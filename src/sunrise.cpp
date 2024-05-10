#include "sunrise.hpp"

Sun::Sun(Vector2f p, float s)
{
    pos = p;
    speed = s;
    if (!texture.loadFromFile(PICS_PATH + "sun.png"))
        error("failed to load sun texture");
    sprite.setTexture(texture);
    sprite.setScale(0.23f, 0.23f);
}

//Sun::~Sun(){}

void Sun::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Sun::update()
{
    pos.y += speed;
    sprite.setPosition(pos);
}

bool Sun::is_in_mouse_pos(Vector2i mouse_pos)
{
    if (((pos.x + (50 * sprite.getScale().x)) < mouse_pos.x) &&
        ((pos.x + (310 * sprite.getScale().x)) > mouse_pos.x) &&
        ((pos.y + (50 * sprite.getScale().y)) < mouse_pos.y) &&
        ((pos.y + (310 * sprite.getScale().y)) > mouse_pos.y))
            return true;
        return false;
}
#include "sun.hpp"

Sun::Sun(Vector2f p, float s)
{
    pos = p;
    speed = s;
    if (!texture.loadFromFile(PICS_PATH + "sun.png"))
        error("failed to load sun texture");
    sprite.setTexture(texture);
}

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
    if (((pos.x + 15) < mouse_pos.x) &&
        ((pos.x - 15 + sprite.getGlobalBounds().width) > mouse_pos.x) &&
        ((pos.y + 15) < mouse_pos.y) &&
        ((pos.y - 15 + sprite.getGlobalBounds().height) > mouse_pos.y))
            return true;
        return false;
}
#include "zombie.hpp"

Zombie::Zombie(string t, Vector2f p)
{
    type = t;
    pos = p;
    if (type == "zombie")
    {
        damage = game_settings.Zombie[0];
        health = game_settings.Zombie[1];
        hit_rate = game_settings.Zombie[2];
        speed = game_settings.Zombie[3];
    }
    else
    {
        damage = game_settings.Titan[0];
        health = game_settings.Titan[1];
        hit_rate = game_settings.Titan[2];
        speed = game_settings.Titan[3];
    }
}

void Zombie::render(RenderWindow &window)
{
    string zombie_type = type;
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
    if (type == "zombie")
    {
        if (!is_eating && !is_frozen) speed = game_settings.Zombie[3];
        if (!is_eating && is_frozen) speed = game_settings.Zombie[3] / 2;
    }
    else
    {
        if (!is_eating && !is_frozen) speed = game_settings.Titan[3];
        if (!is_eating && is_frozen) speed = game_settings.Titan[3] / 2;
    }
    if(is_frozen && frozen_clock.getElapsedTime().asSeconds() > 5)
    {
        speed *= 2;
        hit_rate *= 2;
        is_frozen = false;
    }
}

FloatRect Zombie::get_rect()
{
    float width, height, left, top;
    if (type == "zombie")
    {
        width = sprite.getGlobalBounds().width / 4.f;
        height = sprite.getGlobalBounds().height / 2.f;
        left = sprite.getGlobalBounds().left + (width / 2);
        top = sprite.getGlobalBounds().top + (height);
    }
    else
    {
        width = sprite.getGlobalBounds().width / 4.f;
        height = sprite.getGlobalBounds().height / 3.5f;
        left = sprite.getGlobalBounds().left + (width / 2);
        top = sprite.getGlobalBounds().top + (height * 7 / 3);
    }
    FloatRect bounds(left, top, width, height);
    return bounds;
}

void Zombie::is_being_damaged(float hit)
{
    health -= hit;
}

void Zombie::freeze()
{
    if (!is_frozen)
    {
        speed /= 2;
        hit_rate /= 2;
    }
    frozen_clock.restart();
    is_frozen = true;
}

void Zombie::is_eating_plant()
{
    speed = 0;
    is_eating = true;
}
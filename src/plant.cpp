#include "plant.hpp"

Plant::Plant(string plant_name, Vector2i pos, vector<float> settings)
{
    if (!texture.loadFromFile(PICS_PATH + plant_name + ".png"))
        error("failed to load " + plant_name + " texture");
    sprite.setTexture(texture);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    Vector2f mouse_pos = Vector2f(pos);
    sprite.setPosition(mouse_pos);

    damage = settings[0];
    health = settings[1];
    cooldown = settings[2];
    hitrate = settings[3];
    speed = settings[4];
    price = settings[5];
}

void Plant::set_pos(Vector2i pos)
{
    //Vector2f mouse_pos = Vector2f(pos);
    // give pos
    // in what tile
    // that tile will be full
    // sprite.setPosition(mouse_pos);
    tile = tile->which_tile(pos);
    sprite.setPosition(tile->get_center_of_tile());
}

void Plant::render(RenderWindow &window)
{
    window.draw(sprite);
}
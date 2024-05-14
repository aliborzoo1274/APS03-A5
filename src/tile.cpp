#include "tile.hpp"

Tile::Tile(int x, int y, Vector2f min, Vector2f max)
{
    i = x;
    j = y;
    this->min.x = min.x;
    this->min.y = min.y;
    this->max.x = max.x;
    this->max.y = max.y;
}

Tile* Tile::which_tile(Vector2i mouse_pos)
{
    Tile* tile = nullptr;
    Vector2f pos;
    pos.x = top_left_corner_of_ground.x;
    pos.y = top_left_corner_of_ground.y;
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= 9; y++)
        {
            if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + tile_width) &&
            mouse_pos.y > pos.y && mouse_pos.y < (pos.y + tile_height))
            {
                tile = new Tile(x, y, {pos.x, pos.y}, {(pos.x + tile_width), (pos.y + tile_height)});
                return tile;
            }
            pos.x += tile_width;
        }
        pos.x = top_left_corner_of_ground.x;
        pos.y += tile_height;
    }
}

 Vector2f Tile::get_center_of_tile()
 {
    Vector2f center_of_tile;
    center_of_tile.x = (max.x + min.x) / 2;
    center_of_tile.y = (max.y + min.y) / 2;
    return center_of_tile;
 }
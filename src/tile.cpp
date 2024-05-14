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
    pos.x = TOP_LEFT_CORNER_OF_GROUND.x;
    pos.y = TOP_LEFT_CORNER_OF_GROUND.y;
    for (int x = 1; x <= 5; x++)
    {
        for (int y = 1; y <= 9; y++)
        {
            if (mouse_pos.x > pos.x && mouse_pos.x < (pos.x + TILE_WIDTH) &&
            mouse_pos.y > pos.y && mouse_pos.y < (pos.y + TILE_HEIGHT))
            {
                tile = new Tile(x, y, {pos.x, pos.y}, {(pos.x + TILE_WIDTH), (pos.y + TILE_HEIGHT)});
                return tile;
            }
            pos.x += TILE_WIDTH;
        }
        pos.x = TOP_LEFT_CORNER_OF_GROUND.x;
        pos.y += TILE_HEIGHT;
    }
}

 Vector2f Tile::get_center_of_tile()
 {
    Vector2f center_of_tile;
    center_of_tile.x = (max.x + min.x) / 2;
    center_of_tile.y = (max.y + min.y) / 2;
    return center_of_tile;
 }
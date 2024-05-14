#include "global.hpp"

class Tile
{
public:
    Tile(int x, int y, Vector2f min, Vector2f max);
    Tile* which_tile(Vector2i pos);
    Vector2f get_center_of_tile();
    bool full_of_plant = false;
    bool full_of_zombie = false;
private:
    int i, j;
    Vector2f min, max;
};
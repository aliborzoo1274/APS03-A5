#pragma once

#include "global.hpp"
#include "settings.hpp"
#include "plant.hpp"
#include "peashooter.hpp"
#include "snowpeashooter.hpp"
#include "sunflower.hpp"
#include "wallnut.hpp"

class Board
{
public:
    void render(RenderWindow &window);
    void update();
    bool is_in_mouse_pos(Vector2i pos);
    Plant* what_is_in_mouse_pos(Vector2i pos);
private:
    Settings game_settings = settings();
    //Clock clock;
    Texture board_tx, sunfl_tx, peash_tx, snpea_tx, w_tx;
    Sprite board_sp, sunfl_sp, peash_sp, snpea_sp, w_sp;
};
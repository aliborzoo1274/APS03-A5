#pragma once

#include "global.hpp"
#include "settings.hpp"
#include "score.hpp"
#include "plant.hpp"
#include "peashooter.hpp"
#include "snowpeashooter.hpp"
#include "sunflower.hpp"
#include "wallnut.hpp"

class Board
{
public:
    void render_board(RenderWindow &window);
    void render_card(RenderWindow &window, Texture &texture,
                      Sprite &sprite, string card_name, pair<float, float> card_pos);
    void render_card_price(RenderWindow &window, int price_value, pair<float, float> text_pos);
    void update();
    void increase_score();
    bool is_in_mouse_pos(Vector2i pos);
    Plant* what_is_in_mouse_pos(Vector2i pos);
private:
    Settings game_settings = settings();
    Score score;
    int first_method_call_fixer = 0;
    Clock sunfl_card_clock, peash_card_clock, snpea_card_clock, w_card_clock;
    Texture board_tx, sunfl_tx, peash_tx, snpea_tx, w_tx;
    Sprite board_sp, sunfl_sp, peash_sp, snpea_sp, w_sp;
    string sunfl_card_type = "sunflowercard";
    string peash_card_type = "peashootercard";
    string snpea_card_type = "snowpeashootercard";
    string w_card_type = "wallnutcard";
};
#pragma once

#include "global.hpp"

class Score
{
public:
    void render(RenderWindow &window);
    int get_score() {return score_value;}
    void increase();
    void decrease(float plant_price);
private:
    int score_value = 50;
    Text score_text;
};
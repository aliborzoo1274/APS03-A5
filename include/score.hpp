#pragma once

#include "global.hpp"

class Score
{
public:
    void render(RenderWindow &window);
    void update();
private:
    int score_value = 50;
    Text score_text;
};
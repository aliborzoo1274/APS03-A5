#include "score.hpp"

void Score::render(RenderWindow &window)
{
    Font font;
    if (!font.loadFromFile(FONTS_PATH + "Digital-Serial-ExtraBold Regular.ttf"))
        error("failed to load Digital-Serial-ExtraBold Regular font");
    score_text.setFont(font);
    score_text.setCharacterSize(20);
    score_text.setFillColor(Color::Black);
    score_text.setPosition(30.f, 80.f);
    score_text.setString(to_string(score_value));
    window.draw(score_text);
}

void Score::increase()
{
    score_value += SCORE_INCREASE;
}

void Score::decrease(float plant_price)
{
    score_value -= plant_price;
}
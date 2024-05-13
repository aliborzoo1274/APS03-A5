#include "board.hpp"

void Board::render_board(RenderWindow &window)
{
    if (!board_tx.loadFromFile(PICS_PATH + "board.png"))
        error("failed to load board texture");
    board_sp.setTexture(board_tx);
    board_sp.setPosition(0.f, 0.f);
    window.draw(board_sp);
    score.render(window);
    render_card(window, sunfl_tx, sunfl_sp, sunfl_card_type, {90.f, 13.f});
    render_card(window, peash_tx, peash_sp, peash_card_type, {140.f, 13.f});
    render_card(window, snpea_tx, snpea_sp, snpea_card_type, {188.f, 13.f});
    render_card(window, w_tx, w_sp, w_card_type, {234.f, 14.f});
    render_card_price(window, game_settings.Sunflower[5], {100.f, 60.f});
    render_card_price(window, game_settings.Peashooter[5], {150.f, 60.f});
    render_card_price(window, game_settings.SnowPeashooter[5], {198.f, 60.f});
    render_card_price(window, game_settings.Wallnut[5], {244.f, 61.f});
}

void Board::render_card(RenderWindow &window, Texture &texture,
                      Sprite &sprite, string card_name, pair<float, float> card_pos)
{
    if (!texture.loadFromFile(PICS_PATH + card_name + ".png"))
        error("failed to load " + card_name + " texture");
    sprite.setTexture(texture);
    sprite.setPosition(card_pos.first, card_pos.second);
    window.draw(sprite);
}

void Board::render_card_price(RenderWindow &window, int price_value, pair<float, float> text_pos)
{
    Text price_text;
    Font font;
    if (!font.loadFromFile(FONTS_PATH + "jorvik.ttf"))
        error("failed to load jorvik font");
    price_text.setFont(font);
    price_text.setCharacterSize(15);
    price_text.setFillColor(Color::Black);
    price_text.setPosition(text_pos.first, text_pos.second);
    price_text.setString(to_string(price_value));
    window.draw(price_text);
}

void Board::increase_score()
{
    score.increase();
}

void Board::update()
{
    if (score.get_score() < game_settings.Peashooter[5] || peash_card_clock.getElapsedTime().asSeconds() < game_settings.Peashooter[2])
        peash_card_type = "peashootercard_useless";
    else peash_card_type = "peashootercard";

    if (score.get_score() < game_settings.SnowPeashooter[5] || snpea_card_clock.getElapsedTime().asSeconds() < game_settings.SnowPeashooter[2])
        snpea_card_type = "snowpeashootercard_useless";
    else snpea_card_type = "snowpeashootercard";

    if (score.get_score() < game_settings.Sunflower[5] || sunfl_card_clock.getElapsedTime().asSeconds() < game_settings.Sunflower[2])
        sunfl_card_type = "sunflowercard_useless";
    else sunfl_card_type = "sunflowercard";

    if (score.get_score() < game_settings.Wallnut[5] || w_card_clock.getElapsedTime().asSeconds() < game_settings.Wallnut[2])
        w_card_type = "wallnutcard_useless";
    else w_card_type = "wallnutcard";
}

bool Board::is_in_mouse_pos(Vector2i mouse_pos)
{
    if (mouse_pos.x > 90 && mouse_pos.x < 284 &&
        mouse_pos.y > 13 && mouse_pos.y < 80)
        return true;
    return false;
}

Plant* Board::what_is_in_mouse_pos(Vector2i mouse_pos)
{
    if(mouse_pos.x >  peash_sp.getGlobalBounds().left && mouse_pos.x < (peash_sp.getGlobalBounds().left + peash_sp.getGlobalBounds().width) &&
        mouse_pos.y > peash_sp.getGlobalBounds().top && mouse_pos.y < (peash_sp.getGlobalBounds().height + peash_sp.getGlobalBounds().top))
    {
        if(peash_card_type == "peashootercard_useless")
            return nullptr;
        Peashooter* peashooter = new Peashooter("peashooter", mouse_pos, game_settings.Peashooter);
        if (first_method_call_fixer % 2)
        {
            score.decrease(game_settings.Peashooter[5]);
            peash_card_clock.restart();
        }
        else delete peashooter;
        first_method_call_fixer++;
        return peashooter;
    }
    else if(mouse_pos.x >  snpea_sp.getGlobalBounds().left && mouse_pos.x < (snpea_sp.getGlobalBounds().left + snpea_sp.getGlobalBounds().width) &&
            mouse_pos.y > snpea_sp.getGlobalBounds().top && mouse_pos.y < (snpea_sp.getGlobalBounds().height + snpea_sp.getGlobalBounds().top))
    {
        if(snpea_card_type == "snowpeashootercard_useless")
            return nullptr;
        Snowpeashooter* snowpeashooter = new Snowpeashooter("snowpeashooter", mouse_pos, game_settings.SnowPeashooter);
        if (first_method_call_fixer % 2)
        {
            score.decrease(game_settings.SnowPeashooter[5]);
            snpea_card_clock.restart();
        }
        else delete snowpeashooter;
        first_method_call_fixer++;
        return snowpeashooter;
    }
    else if(mouse_pos.x >  sunfl_sp.getGlobalBounds().left && mouse_pos.x < (sunfl_sp.getGlobalBounds().left + sunfl_sp.getGlobalBounds().width) &&
            mouse_pos.y > sunfl_sp.getGlobalBounds().top && mouse_pos.y < (sunfl_sp.getGlobalBounds().height + sunfl_sp.getGlobalBounds().top))
    {
        if(sunfl_card_type == "sunflowercard_useless")
            return nullptr;
        Sunflower* sunflower = new Sunflower("sunflower", mouse_pos, game_settings.Sunflower);
        if (first_method_call_fixer % 2)
        {
            score.decrease(game_settings.Sunflower[5]);
            sunfl_card_clock.restart();
        }
        else delete sunflower;
        first_method_call_fixer++;
        return sunflower;
    }
    else if(mouse_pos.x >  w_sp.getGlobalBounds().left && mouse_pos.x < (w_sp.getGlobalBounds().left + w_sp.getGlobalBounds().width) &&
            mouse_pos.y > w_sp.getGlobalBounds().top && mouse_pos.y < (w_sp.getGlobalBounds().height + w_sp.getGlobalBounds().top))
    {
        if(w_card_type == "wallnutcard_useless")
            return nullptr;
        Wallnut* wallnut = new Wallnut("wall-nut", mouse_pos, game_settings.Wallnut);
        if (first_method_call_fixer % 2)
        {
            score.decrease(game_settings.Wallnut[5]);
            w_card_clock.restart();
        }
        else delete wallnut;
        first_method_call_fixer++;
        return wallnut;
    }
}
#include "board.hpp"

void Board::render(RenderWindow &window)
{
    if (!board_tx.loadFromFile(PICS_PATH + "board.png"))
        error("failed to load board texture");
    board_sp.setTexture(board_tx);
    board_sp.setPosition(0.f, 0.f);
    window.draw(board_sp);

    if (!sunfl_tx.loadFromFile(PICS_PATH + "sunflowercard.png"))
        error("failed to load sunflowercard texture");
    sunfl_sp.setTexture(sunfl_tx);
    sunfl_sp.setPosition(90.f, 13.f);
    window.draw(sunfl_sp);

    if (!peash_tx.loadFromFile(PICS_PATH + "peashootercard.png"))
        error("failed to load peashootercard texture");
    peash_sp.setTexture(peash_tx);
    peash_sp.setPosition(140.f, 13.f);
    window.draw(peash_sp);

    if (!snpea_tx.loadFromFile(PICS_PATH + "snowpeashootercard.png"))
        error("failed to load snowpeashootercard texture");
    snpea_sp.setTexture(snpea_tx);
    snpea_sp.setPosition(188.f, 13.f);
    window.draw(snpea_sp);

    if (!w_tx.loadFromFile(PICS_PATH + "wallnutcard.png"))
        error("failed to load wallnutcard texture");
    w_sp.setTexture(w_tx);
    w_sp.setPosition(234.f, 14.f);
    window.draw(w_sp);
}

void Board::update()
{
    //sprite.setPosition(pos);
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
    //cout << peash_sp.getGlobalBounds().left << ' ' << peash_sp.getGlobalBounds().width << endl;
    if(mouse_pos.x >  peash_sp.getGlobalBounds().left && mouse_pos.x < (peash_sp.getGlobalBounds().left + peash_sp.getGlobalBounds().width) &&
        mouse_pos.y > peash_sp.getGlobalBounds().top && mouse_pos.y < (peash_sp.getGlobalBounds().height + peash_sp.getGlobalBounds().top))
    {
        Peashooter* peashooter = new Peashooter(mouse_pos, game_settings.Peashooter);
        return peashooter;
    }
    else if(mouse_pos.x >  snpea_sp.getGlobalBounds().left && mouse_pos.x < (snpea_sp.getGlobalBounds().left + snpea_sp.getGlobalBounds().width) &&
            mouse_pos.y > snpea_sp.getGlobalBounds().top && mouse_pos.y < (snpea_sp.getGlobalBounds().height + snpea_sp.getGlobalBounds().top))
    {
        Snowpeashooter* snowpeashooter = new Snowpeashooter(mouse_pos, game_settings.SnowPeashooter);
        return snowpeashooter;
    }
    else if(mouse_pos.x >  sunfl_sp.getGlobalBounds().left && mouse_pos.x < (sunfl_sp.getGlobalBounds().left + sunfl_sp.getGlobalBounds().width) &&
            mouse_pos.y > sunfl_sp.getGlobalBounds().top && mouse_pos.y < (sunfl_sp.getGlobalBounds().height + sunfl_sp.getGlobalBounds().top))
    {
        Sunflower* sunflower = new Sunflower(mouse_pos, game_settings.Sunflower);
        return sunflower;
    }
    else if(mouse_pos.x >  w_sp.getGlobalBounds().left && mouse_pos.x < (w_sp.getGlobalBounds().left + w_sp.getGlobalBounds().width) &&
            mouse_pos.y > w_sp.getGlobalBounds().top && mouse_pos.y < (w_sp.getGlobalBounds().height + w_sp.getGlobalBounds().top))
    {
        Wallnut* wallnut = new Wallnut(mouse_pos, game_settings.Wallnut);
        return wallnut;
    }
}
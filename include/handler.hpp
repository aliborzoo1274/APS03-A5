#pragma once

#include "global.hpp"
#include "settings.hpp"
//#include "player.hpp"
//#include "projectile.hpp"
#include "zombie.hpp"
#include "titan.hpp"
#include "sunrise.hpp"
#include "board.hpp"
#include "plant.hpp"
#include "peashooter.hpp"

class Handler
{
public:
    //Handler (Player* player);
    //~Handler();
    Handler():
        rng(random_device{}()) {}
    void update();
    void render(RenderWindow &window);
    void handle_mouse_press(Vector2i pos);
    void handle_pressing_sun(Vector2i pos);
    void handle_pressing_plant(Vector2i pos);
private:
    Settings game_settings = settings();
    mt19937 rng;
    Clock clock, zombie_clock, titan_clock, sun_clock;
    Board board;
    bool mouse_clicked = true;
    //Player* player;
    //vector <Projectile*> projectiles;
    vector <Zombie*> zombies;
    vector <Titan*> titans;
    vector<Sun*> suns;
    vector<Plant*> plants;
    vector<Tile*> tiles;
    //void add_projectile();
    //void delete_out_of_bounds();
    void add_zombie();
    void add_titan();
    void add_sun(Vector2f pos);
    //void handle_collision();
};
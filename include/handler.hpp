#pragma once

#include "global.hpp"
#include "settings.hpp"
//#include "player.hpp"
//#include "projectile.hpp"
#include "zombie.hpp"
#include "titan.hpp"
#include "sun.hpp"
#include "board.hpp"
#include "plant.hpp"
#include "peashooter.hpp"
#include "snowpeashooter.hpp"
#include "sunflower.hpp"
#include "wallnut.hpp"
#include "pea.hpp"
#include "snowpea.hpp"

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
    Clock pea_clock, snowpea_clock, zombie_clock, titan_clock, sun_clock;
    Board board;
    bool mouse_clicked = true;
    //Player* player;
    vector <Zombie*> zombies;
    vector <Titan*> titans;
    vector<Sun*> suns;
    vector<Plant*> plants;
    vector<Tile*> tiles;
    vector<Pea*> peas;
    vector<Snowpea*> snowpeas;
    void add_pea();
    void add_snowpea();
    void delete_out_of_bounds();
    void add_zombie();
    void add_titan();
    void add_sun(Vector2f pos);
    void handle_collision();
    void handle_collision_of_zombie_and_projectile();
    void handle_collision_of_zombie_and_plant();
};
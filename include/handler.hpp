#pragma once

#include "global.hpp"
//#include "player.hpp"
//#include "projectile.hpp"
#include "zombie.hpp"
#include "titan.hpp"

class Handler
{
public:
    //Handler (Player* player);
    //~Handler();
    Handler():
        rng(random_device{}()) {}
    void update();
    void render(RenderWindow &window);
private:
    mt19937 rng;
    Clock clock, zombie_clock, titan_clock;
    //Player* player;
    //vector <Projectile*> projectiles;
    vector <Zombie*> zombies;
    vector <Titan*> titans;
    //void add_projectile();
    //void delete_out_of_bounds();
    void add_zombie();
    void add_titan();
    //void handle_collision();
};
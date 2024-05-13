#include "handler.hpp"

// Handler::Handler (Player* p){
//     player = p;
// }

// Handler::~Handler(){
//     for(auto p : projectiles){
//         delete p;
//     }
//     for(auto z : zombies){
//         delete z;
//     }
// }

void Handler::update()
{
    // Time elapsed = clock.getElapsedTime();
    // if(elapsed.asMilliseconds() >= 600)
    // {
    //     clock.restart();
    //     add_projectile();
    // }
    Time zelapsed = zombie_clock.getElapsedTime();
    if(zelapsed.asSeconds() >= 4)
    {
        zombie_clock.restart();
        add_zombie();
    }
    Time telapsed = titan_clock.getElapsedTime();
    if(telapsed.asSeconds() >= 10)
    {
        titan_clock.restart();
        add_titan();
    }
    Time selapsed = sun_clock.getElapsedTime();
    if(selapsed.asSeconds() >= game_settings.Sun[1])
    {
        sun_clock.restart();
        add_sun(Vector2f(0, 0));
    }
    // for(auto p : projectiles)
    //     p->update();
    for(auto z : zombies)
        z->update();
    for(auto t : titans)
        t->update();
    for(auto s : suns)
        s->update();
    board.update();
    //delete_out_of_bounds();
    //handle_collision();
}

// void Handler::delete_out_of_bounds()
// {
//     vector <Projectile*> trash;
//     for(auto p : projectiles){
//         if(p->is_out()){
//             trash.push_back(p);
//         }
//     }
//     projectiles.erase(remove_if(projectiles.begin(), projectiles.end(), 
//         [](auto p){ return p->is_out(); }), projectiles.end());
//     for (auto p : trash){
//         delete p;
//     }
// }

void Handler::render(RenderWindow &window)
{
    // for(auto p : projectiles)
    //     p->render(window);
    board.render_board(window);
    for(auto p : plants)
        p->render(window);
    for(auto t : titans)
        t->render(window);
    for(auto z : zombies)
        z->render(window);
    for(auto s : suns)
        s->render(window);
}

// void Handler::add_projectile()
// {
//     Projectile* p = new Projectile(player->get_projectile_pos());
//     projectiles.push_back(p);
// }

void Handler::add_zombie()
{
    uniform_int_distribution<int> dist(0, 4);
    int random_number = dist(rng);
    Zombie* z = new Zombie(Vector2f(WIDTH, random_number * 100 + 30));
    zombies.push_back(z);
}

void Handler::add_titan()
{
    uniform_int_distribution<int> dist(0, 4);
    int random_number = dist(rng);
    Titan* t = new Titan(Vector2f(WIDTH, random_number * 100 - 44));
    titans.push_back(t);
}

void Handler::add_sun(Vector2f pos)
{
    if (pos.x == 0)
    {
        uniform_int_distribution<int> dist(1, 8);
        int random_number = dist(rng);
        Sun* s = new Sun(Vector2f(random_number * 100, 0), game_settings.Sun[0]);
        suns.push_back(s);
    }
    else
    {
        Sun* s = new Sun(pos, 0);
        suns.push_back(s);
    }
}

// void Handler::handle_collision(){
//     vector <Projectile*> trashp;
//     vector <Zombie*> trashz;
//     for(auto p : projectiles)
//     {
//         for(auto z : zombies)
//         {
//             FloatRect z_rect = z->get_rect();
//             FloatRect p_rect = p->get_rect();
//             if(z_rect.intersects(p_rect)){
//                 trashp.push_back(p);
//                 trashz.push_back(z);
//             }
//         }   
//     }
//     for(auto p : trashp)
//     {
//         projectiles.erase(remove(projectiles.begin(), projectiles.end(), p), projectiles.end());   
//         delete p;
//     }
//     for(auto z : trashz)
//     {
//         zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());   
//         delete z;
//     }
// }

void Handler::handle_mouse_press(Vector2i pos)
{
    handle_pressing_sun(pos);
    handle_pressing_plant(pos);
}

void Handler::handle_pressing_sun(Vector2i pos)
{
    vector <Sun*> trashs;
    for (auto s : suns)
    {
        if (s->is_in_mouse_pos(pos))
        {
            trashs.push_back(s);
            board.increase_score();
        }
    }
    for(auto s : trashs)
    {
        suns.erase(remove(suns.begin(), suns.end(), s), suns.end());
        delete s;
    }
}

void Handler::handle_pressing_plant(Vector2i pos)
{
    if (board.is_in_mouse_pos(pos))
    {
        if(mouse_clicked && board.what_is_in_mouse_pos(pos) != nullptr)
        {
            plants.push_back(board.what_is_in_mouse_pos(pos));
            mouse_clicked = false;
        }
    }
    else if (!mouse_clicked)
    {
        plants[plants.size() - 1]->set_pos(pos);
        mouse_clicked = true;
    }
}
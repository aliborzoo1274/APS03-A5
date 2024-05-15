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
    int num_of_new_attackers;
    float elapsed_time = game_clock.getElapsedTime().asSeconds();
    if (elapsed_time < game_total_time)
    {
        int round_num = floor(elapsed_time / time_of_each_round);
        num_of_new_attackers = (round_num * num_of_added_attackers) +
                                num_of_attackers_in_first_round;
    }
    else
    {

    }
    Time pelapsed = pea_clock.getElapsedTime();
    if(pelapsed.asSeconds() >= game_settings.Peashooter[3])
    {
        pea_clock.restart();
        add_pea();
    }
    Time snpelapsed = snowpea_clock.getElapsedTime();
    if(snpelapsed.asSeconds() >= game_settings.SnowPeashooter[3])
    {
        snowpea_clock.restart();
        add_snowpea();
    }
    Time zelapsed = zombie_clock.getElapsedTime();
    if(zelapsed.asSeconds() >= (time_of_each_round / num_of_new_attackers))
    {
        zombie_clock.restart();
        num_of_total_zombies++;
        add_zombie();
    }
    // Time telapsed = titan_clock.getElapsedTime();
    // if(telapsed.asSeconds() >= 5)
    // {
    //     titan_clock.restart();
    //     add_titan();
    // }
    Time selapsed = sun_clock.getElapsedTime();
    if(selapsed.asSeconds() >= game_settings.Sun[1])
    {
        sun_clock.restart();
        add_sun(Vector2f(0, 0));
    }
    for(auto p : peas)
        p->update();
    for(auto s : snowpeas)
        s->update();
    for(auto z : zombies)
        z->update();
    // for(auto t : titans)
    //     t->update();
    for(auto s : suns)
        s->update();
    board.update();
    // for(auto p : plants)
    //     p->update();
    for(auto p : plants)
    {
        Sunflower* sunflower = dynamic_cast<Sunflower*>(p);
        if (sunflower != nullptr)
        {
            Vector2f sun_pos = sunflower->make_sun();
            if(sun_pos.x != 0)
                add_sun(sun_pos);
        }
    }
    delete_out_of_bounds();
    handle_collision();
}

void Handler::delete_out_of_bounds()
{
    vector <Pea*> p_trash;
    for(auto p : peas)
    {
        if(p->is_out())
            p_trash.push_back(p);
    }
    peas.erase(remove_if(peas.begin(), peas.end(), 
        [](auto p){ return p->is_out(); }), peas.end());
    for (auto p : p_trash)
        delete p;

    vector <Snowpea*> s_trash;
    for(auto s : snowpeas)
    {
        if(s->is_out())
            s_trash.push_back(s);
    }
    snowpeas.erase(remove_if(snowpeas.begin(), snowpeas.end(), 
        [](auto s){ return s->is_out(); }), snowpeas.end());
    for (auto s : s_trash)
        delete s;
}

void Handler::render(RenderWindow &window)
{
    board.render_board(window);
    for(auto p : plants)
        p->render(window);
    for(auto p : peas)
        p->render(window);
    for(auto s : snowpeas)
        s->render(window);
    // for(auto t : titans)
    //     t->render(window);
    for(auto z : zombies)
        z->render(window);
    for(auto s : suns)
        s->render(window);
}

void Handler::add_pea()
{
    for(auto p : plants)
    {
        Peashooter* peashooter = dynamic_cast<Peashooter*>(p);
        if (peashooter != nullptr)
        {
            Pea* pea = new Pea(peashooter->get_pea_pos());
            peas.push_back(pea);
        }
    }
}

void Handler::add_snowpea()
{
    for(auto p : plants)
    {
        Snowpeashooter* snowpeashooter = dynamic_cast<Snowpeashooter*>(p);
        if (snowpeashooter != nullptr)
        {
            Snowpea* snowpea = new Snowpea(snowpeashooter->get_snowpea_pos());
            snowpeas.push_back(snowpea);
        }
    }
}

void Handler::add_zombie()
{
    string type;
    int location;
    uniform_int_distribution<int> type_dist(0, 9);
    int random_number_for_type = type_dist(rng);
    uniform_int_distribution<int> dist(0, 4);
    int random_number = dist(rng);
    if (random_number_for_type)
    {
        type = "zombie";
        location = random_number * 100 + 30;
    }
    else
    {
        type = "titan";
        location = random_number * 100 - 44;
    }
    Zombie* z = new Zombie(type ,Vector2f(WIDTH, location));
    zombies.push_back(z);
}

// void Handler::add_titan()
// {
//     uniform_int_distribution<int> dist(0, 4);
//     int random_number = dist(rng);
//     Titan* t = new Titan(Vector2f(WIDTH, random_number * 100 - 44));
//     titans.push_back(t);
// }

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

void Handler::handle_collision()
{
    handle_collision_of_zombie_and_projectile();
    handle_collision_of_zombie_and_plant();
}

void Handler::handle_collision_of_zombie_and_projectile()
{
    vector<Pea*> trashp;
    vector<Snowpea*> trash_snp;
    vector<Zombie*> trashz;
    for(auto p : peas)
    {
        for(auto z : zombies)
        {
            FloatRect z_rect = z->get_rect();
            FloatRect p_rect = p->get_rect();
            if(z_rect.intersects(p_rect))
            {
                trashp.push_back(p);
                z->is_being_damaged(p->get_damage());
                if(z->get_health() <= 0)
                    trashz.push_back(z);
            }
        }   
    }
    for(auto s : snowpeas)
    {
        for(auto z : zombies)
        {
            FloatRect z_rect = z->get_rect();
            FloatRect s_rect = s->get_rect();
            if(z_rect.intersects(s_rect))
            {
                trash_snp.push_back(s);
                z->freeze();
                z->is_being_damaged(s->get_damage());
                if(z->get_health() <= 0)
                    trashz.push_back(z);
            }
        }   
    }
    set<Zombie*> unique_trashz(trashz.begin(), trashz.end());
    for(auto z : unique_trashz)
    {
        zombies.erase(remove(zombies.begin(), zombies.end(), z), zombies.end());
        num_of_dead_zombies++; 
        delete z;
    }
    set<Pea*> unique_trashp(trashp.begin(), trashp.end());
    for(auto p : unique_trashp)
    {
        peas.erase(remove(peas.begin(), peas.end(), p), peas.end());   
        delete p;
    }
    set<Snowpea*> unique_trash_snp(trash_snp.begin(), trash_snp.end());
    for(auto s : unique_trash_snp)
    {
        snowpeas.erase(remove(snowpeas.begin(), snowpeas.end(), s), snowpeas.end());   
        delete s;
    }
}

void Handler::handle_collision_of_zombie_and_plant()
{
    vector<Plant*> trashp;
    for(auto p : plants)
    {
        for(auto z : zombies)
        {
            FloatRect z_rect = z->get_rect();
            FloatRect p_rect = p->get_rect();
            if(z_rect.intersects(p_rect))
            {
                z->is_eating_plant();
                if(z->get_eating_time().asSeconds() > z->get_hit_rate())
                {
                    p->is_being_eaten(z->get_damage());
                    z->took_bite();
                }
                if(p->get_health() <= 0)
                {
                    trashp.push_back(p);
                    z->ate_plant();
                }
            }
        }   
    }
    set<Plant*> unique_trashp(trashp.begin(), trashp.end());
    for(auto p : unique_trashp)
    {
        for (int i = 0; i < tiles.size(); i++)
        {
            if (tiles[i] = p->get_tile())
            {
                Tile* released_tile = tiles[i];
                tiles.erase(tiles.begin() + i);
                delete released_tile;
            }
        }
        plants.erase(remove(plants.begin(), plants.end(), p), plants.end());   
        delete p;
    }
}

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
        Tile* tile;
        tile = tile->which_tile(pos);
        if (pos.x < TOP_LEFT_CORNER_OF_GROUND.x ||
            pos.x > (TOP_LEFT_CORNER_OF_GROUND.x + 9 * TILE_WIDTH) ||
            pos.y < TOP_LEFT_CORNER_OF_GROUND.y ||
            pos.y > (TOP_LEFT_CORNER_OF_GROUND.y + 5 * TILE_HEIGHT))
                return;
        for (auto t : tiles)
        {
            if (t->get_center_of_tile().x == tile->get_center_of_tile().x &&
                t->get_center_of_tile().y == tile->get_center_of_tile().y)
                    return;
        }
        plants[plants.size() - 1]->set_position(pos);
        tiles.push_back(plants[plants.size() - 1]->get_tile());
        //tiles[tiles.size() - 1]->full_of_plant = true;
        mouse_clicked = true;
    }
}
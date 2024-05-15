#pragma once

#include "global.hpp"

class Handler;

enum State
{
  IN_GAME,
  VICTORY_SCREEN,
  GAMEOVER_SCREEN,
};

class Game
{
public:
    Game(int width, int height);
    void run();
    ~Game();
    RenderWindow window;
private:
    State state;
    Texture backgroundTexture, bt;
    Sprite backgroundSprite, bs;
    Handler* handler;
    Music main_music;
    Font font;
    Text text;
    void update();
    void render();
    void handle_events();
    void handle_mouse_press(Event ev);
};
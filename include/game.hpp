#include "global.hpp"

enum State
{
  IN_GAME,
  VICTORY_SCREEN,
  GAMEOVER_SCREEN,
  EXIT
};

class Game
{
public:
    Game(int width, int height);
    void run();
    //~Game();
    RenderWindow window;
private:
    State state;
    Texture backgroundTexture;
    Sprite backgroundSprite;
    //Music music;
    void render();
    void handle_events();
    void handle_mouse_press(Event ev);
    void handle_mouse_release(Event ev);
};
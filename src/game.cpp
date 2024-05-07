#include "game.hpp"

Game::Game(int width, int height)
{
  window.create(VideoMode(width, height), "Plants vs. Zombies");
  window.setFramerateLimit(FRAME_RATE);
  state = IN_GAME;
  //player = new Player(100, 100);
  if (!backgroundTexture.loadFromFile(PICS_PATH + "bg.png"))
    error("failed to load image");
  backgroundSprite.setTexture(backgroundTexture);



  // if (!music.openFromFile(AUDIO_PATH + "pvz.ogg"))
  // {
  //  error("failed to load music");
  // }
  // music.setLoop(true);
  // music.play();
  //handler = new Handler(player);
}

void Game::run()
{
  while (window.isOpen() and state != EXIT)
  {
    //update();
    render();
    handle_events();
  }
  exit(0);
}

void Game::render()
{
  window.clear();
  switch (state)
  {
  case (IN_GAME):
    window.draw(backgroundSprite);
    // player->render(window);
    // handler->render(window);
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
  window.display();
}

void Game::handle_events()
{
  Event event;
  while (window.pollEvent(event))
  {
    switch (event.type)
    {
    case (Event::Closed):
      window.close();
      state = EXIT;
      break;
    case (Event::MouseButtonPressed):
      handle_mouse_press(event);
      break;
    case (Event::MouseButtonReleased):
      handle_mouse_release(event);
      break;
    default:
      break;
    }
  }
}

void Game::handle_mouse_press(Event ev)
{
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state) {
  case (IN_GAME):
    //player->handle_mouse_press(pos);
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}

void Game::handle_mouse_release(Event ev) {
  if (ev.mouseButton.button == Mouse::Right)
    return;
  Vector2i pos = {ev.mouseButton.x, ev.mouseButton.y};
  switch (state) {
  case (IN_GAME):
    //player->handle_mouse_release(pos);
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}
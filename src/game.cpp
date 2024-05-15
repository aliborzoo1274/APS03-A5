#include "game.hpp"
#include "handler.hpp"

Game::Game(int width, int height)
{
  window.create(VideoMode(width, height), "Plants vs. Zombies", Style::Close);
  window.setFramerateLimit(FRAME_RATE);
  state = IN_GAME;
  if (!backgroundTexture.loadFromFile(PICS_PATH + "background.png"))
    error("failed to load background image");
  backgroundSprite.setTexture(backgroundTexture);
  if (!main_music.openFromFile(AUDIO_PATH + "main_music.ogg"))
   error("failed to load main_music");
  main_music.setLoop(true);
  main_music.play();
  handler = new Handler();
}

Game::~Game()
{
  delete handler;
}

void Game::run()
{
  while (window.isOpen())
  {
    update();
    render();
    handle_events();
  }
  exit(0);
}

void Game::update()
{
  switch (state)
  {
  case (IN_GAME):
    state = handler->update();
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}

void Game::render()
{
  window.clear();
  switch (state)
  {
  case (IN_GAME):
    window.draw(backgroundSprite);
    handler->render(window);
    break;
  case (VICTORY_SCREEN):
    if (!font.loadFromFile(FONTS_PATH + "Digital-Serial-ExtraBold Regular.ttf"))
        error("failed to load Digital-Serial-ExtraBold Regular font");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color::White);
    text.setPosition(120.f, 120.f);
    text.setString("\t\t\t\t\tVICTORY!\n\nTHERE IS NOT ZOMBIE ON YOUR LAWN!");
    window.draw(text);
    break;
  case (GAMEOVER_SCREEN):
    if (!font.loadFromFile(FONTS_PATH + "jorvik.ttf"))
        error("failed to load jorvik font");
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(Color::White);
    text.setPosition(200.f, 200.f);
    text.setString("THE ZOMBIES ATE YOUR BRAINS!");
    window.draw(text);
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
      break;
    case (Event::MouseButtonPressed):
      handle_mouse_press(event);
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
  switch (state)
  {
  case (IN_GAME):
    handler->handle_mouse_press(pos);
    break;
  case (VICTORY_SCREEN):
    break;
  case (GAMEOVER_SCREEN):
    break;
  }
}
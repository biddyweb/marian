#include <iostream>

#include "Engine.h"
#include "Game.h"

int main()
{
  Engine *e = new Engine("Marian", 640, 640);
  Game *game = new Game;

  e->mainLoop(game);

  delete e;
  delete game;

  return 0;
}

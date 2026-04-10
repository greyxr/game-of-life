#include "Game.hpp"


int main()
{
  printf("Starting game...\n");
  Game * game = new Game();
  if (game->run() == 0){
    printf("Ending game...\n");
    return 0;
  }
  else {
    printf("Error. Ending game...\n");
    return -1;
  }

}

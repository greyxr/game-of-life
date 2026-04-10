#pragma once
#include "Run.hpp"
#include "Screen.hpp"
#include "Setup.hpp"
#include "Start.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game : ScreenClass {
public:
  enum SCREEN { START, SETUP, RUN };

  StartClass *startScreen = nullptr;
  SetupClass *setupScreen = nullptr;
  RunClass *runScreen = nullptr;
  sf::RenderWindow gameWindow{sf::VideoMode({800, 800}), "SFML works!"};
  SCREEN gameState = START;
  void changeState(SCREEN newState);
  void drawMenu();
  int run();
  void render(sf::RenderWindow &window);
};

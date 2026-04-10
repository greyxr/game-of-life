#include "Game.hpp"
#include "Run.hpp"
#include "Screen.hpp"
#include "Setup.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

  void Game::changeState(SCREEN newState){
    gameState = newState;
  }
void Game::drawMenu(){
  // Draw first box
  sf::Text text = getText("Test string\n");
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::Red);
  text.setPosition({12.f, 10.f});

  sf::RectangleShape firstBox({110.f,30.f});
  firstBox.setPosition({10.f, 10.f});
  firstBox.setFillColor(sf::Color::Green);
  firstBox.setOutlineThickness(5.f);
  firstBox.setOutlineColor(sf::Color::Cyan);
  gameWindow.draw(firstBox);
  gameWindow.draw(text);

  // Draw second box
  sf::Text text2 = getText("Test string\n");
  text2.setCharacterSize(24);
  text2.setFillColor(sf::Color::Red);
  text2.setPosition({142.f, 10.f});


  sf::RectangleShape secondBox({110.f,30.f});
  secondBox.setPosition({140.f, 10.f});
  secondBox.setFillColor(sf::Color::Green);
  secondBox.setOutlineThickness(5.f);
  secondBox.setOutlineColor(sf::Color::Cyan);
  gameWindow.draw(secondBox);
  gameWindow.draw(text2);
}
  int Game::run() {
    //
    // Set up game objects
    startScreen = new StartClass();
    setupScreen = new SetupClass();
    runScreen = new RunClass();
    if(!ScreenClass::font.openFromFile("oswald.ttf")){
      printf("Failed to open font.\n");
      return -1;
    }

    // Main game loop
    while (gameWindow.isOpen()) {
      while (const std::optional event = gameWindow.pollEvent()) {
        if (event->is<sf::Event::Closed>())
          gameWindow.close();
      }
      render(gameWindow);
    }
    return 0;
  }

void Game::render(sf::RenderWindow& window){
      gameWindow.clear();
      switch (gameState) {
      case START:
        startScreen->render(gameWindow);
        break;
      case SETUP:
        setupScreen->render(gameWindow);
        break;
      case RUN:
        runScreen->render(gameWindow);
        break;
      default:
        printf("Else case\n");
      }

      drawMenu();

      gameWindow.display();
}

class StateButton {
  enum SCREEN { START, SETUP, RUN };
  SCREEN state;
  StateButton(SCREEN state){
    this->state = state;
  }
};

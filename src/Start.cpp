#include "Start.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

void StartClass::render(sf::RenderWindow &window) {
  sf::CircleShape shape(400.f);
  shape.setFillColor(sf::Color::Green);
  window.draw(shape);
}

#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/String.hpp>

class ScreenClass{
  public:
    static sf::Font font;
    sf::Text getText(sf::String str){
      sf::Text text(font);
      text.setString(str);
      return text;
    }
    virtual void render(sf::RenderWindow& window) = 0;
    virtual ~ScreenClass() = default;
};

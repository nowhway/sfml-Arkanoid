#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
struct GameObject {
  virtual ~GameObject() = default;

  virtual sf::Vector2f GetPosition() = 0;
  virtual void Update(float deltaTime) = 0;
  virtual void Draw(sf::RenderWindow &window) = 0;
};

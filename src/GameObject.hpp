#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
struct GameObject {
  virtual ~GameObject() = default;

  virtual void Update(float deltaTime) = 0;
  virtual void Draw(sf::RenderWindow &window) = 0;
};

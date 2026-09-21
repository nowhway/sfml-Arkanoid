#pragma once

#include "GameObject.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class Ball : public GameObject {
private:
  sf::Sprite sprite;

public:
  Ball(const sf::Texture &texture);
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
};

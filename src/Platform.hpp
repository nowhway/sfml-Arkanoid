#pragma once
#include "GameObject.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Platform : public GameObject {
private:
  sf::Sprite sprite;

  float moveSpeed;

public:
  Platform(const sf::Texture &texture, float moveSpeed,
           sf::Vector2f scaleVector);

  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
};

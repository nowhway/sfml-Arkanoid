#pragma once

#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
class Ball : public GameObject, public ICollide {
private:
  sf::Sprite sprite;

public:
  Ball(const sf::Texture &texture, CircleCollider circleCollider);
  sf::Vector2f GetPosition() override;
  Collider *GetCollider() override;
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
};

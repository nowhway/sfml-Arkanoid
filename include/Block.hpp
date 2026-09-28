#pragma once

#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
class Block : GameObject, ICollide {

public:
  void Update(float deltaTime) override;
  Collider *GetCollider() override;
  sf::Vector2f GetPosition() override;
  void Draw(sf::RenderWindow &window) override;
};

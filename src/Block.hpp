#pragma once

#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <memory>
class Block : GameObject, ICollide {
private:
  std::unique_ptr<Collider> collider;

public:
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
}

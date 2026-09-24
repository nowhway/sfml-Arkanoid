#pragma once
#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>

class Platform : public GameObject, ICollide {
private:
  sf::Sprite sprite;
  std::unique_ptr<Collider> collider;
  float moveSpeed;

public:
  Platform(const sf::Texture &texture, float moveSpeed,
           sf::Vector2f scaleVector);
  std::unique_ptr<Collider> GetCollider() override;
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
};

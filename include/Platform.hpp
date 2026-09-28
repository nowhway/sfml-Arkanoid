#pragma once
#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Platform : public GameObject, public ICollide {
private:
  sf::Sprite sprite;
  float moveSpeed;

public:
  Platform(const sf::Texture &texture, float moveSpeed,
           sf::Vector2f scaleVector, RectangleCollider rectCollider);
  Collider *GetCollider() override;
  sf::Vector2f GetPosition() override;
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
};

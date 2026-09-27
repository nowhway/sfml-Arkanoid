#pragma once

#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
class Ball : public GameObject, ICollide{
private:
  sf::Sprite sprite;
  std::unique_ptr<Collider> collider;
public:
  Ball(const sf::Texture &texture,CircleCollider& rectCollider);
  std::unique_ptr<Collider>* GetCollider() override;
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow &window) override;
};

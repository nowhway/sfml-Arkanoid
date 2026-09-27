#include "Ball.hpp"
#include "Collider.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>

Ball::Ball(const sf::Texture &texture, CircleCollider& collider) : sprite(texture) {
  this->collider = std::make_unique<CircleCollider>(collider.GetRadius(),collider.GetOffset());
}

void Ball::Update(float deltaTime) {}

std::unique_ptr<Collider>* Ball::GetCollider() {
  return &collider;
}

void Ball::Draw(sf::RenderWindow &window) { window.draw(sprite); }

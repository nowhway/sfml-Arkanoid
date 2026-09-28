#include "Ball.hpp"
#include "Collider.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>

Ball::Ball(const sf::Texture &texture, CircleCollider collider)
    : sprite(texture) {
  this->collider = std::make_unique<CircleCollider>(collider);
}

void Ball::Update(float deltaTime) {}

sf::Vector2f Ball::GetPosition() { return sprite.getPosition(); }
Collider *Ball::GetCollider() { return collider.get(); }

void Ball::Draw(sf::RenderWindow &window) { window.draw(sprite); }

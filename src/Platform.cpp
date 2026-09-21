#include "Platform.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Platform::Platform(const sf::Texture &texture, float moveSpeed,
                   sf::Vector2f scaleVector)
    : sprite(texture) {
  sprite.setPosition({300, 350});
  sprite.scale(scaleVector);
  this->moveSpeed = moveSpeed;
}

void Platform::Update(float deltaTime) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    sprite.move({moveSpeed * deltaTime, 0.0f});
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    sprite.move({-moveSpeed * deltaTime, 0.0f});

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Add)) {
    sprite.scale({1.1f, 1.1f});
    auto current = sprite.getScale();
    std::cout << "current scale (x: " << current.x << " , y: " << current.y
              << ")" << "\n";
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Subtract)) {
    sprite.scale({0.9f, 0.9f});
    auto current = sprite.getScale();
    std::cout << "current scale (x: " << current.x << " , y: " << current.y
              << ")" << "\n";
  }
}

void Platform::Draw(sf::RenderWindow &window) { window.draw(sprite); }

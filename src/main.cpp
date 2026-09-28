#include "Ball.hpp"
#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include "Physics.hpp"
#include "Platform.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Exception.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

void HandleWindowEvents(sf::RenderWindow &window);
void UpdateScene(sf::RenderWindow &window);
std::vector<GameObject *> activeGameObjects;
sf::Time deltaTime;

int main() {
  // building platform sprite
  const sf::Texture texture_platform("assets/textures/platform.png");
  std::unique_ptr<GameObject> platform_ptr = std::make_unique<Platform>(
      texture_platform, 100.0f, (sf::Vector2f){3.0f, 3.0f},
      RectangleCollider({}, {}));

  const sf::Texture texture_ball("assets/textures/kula.png");
  std::unique_ptr<GameObject> ball_ptr =
      std::make_unique<Ball>(texture_ball, CircleCollider({}, {}));

  sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!");

  Physics Physics(sf::milliseconds(10));
  // sf::CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);
  sf::Clock deltaClock;
  activeGameObjects.push_back(ball_ptr.get());
  activeGameObjects.push_back(platform_ptr.get());
  window.setFramerateLimit(60);

  while (window.isOpen()) {
    deltaTime = deltaClock.restart();
    HandleWindowEvents(window);
    window.clear();
    UpdateScene(window);
    window.display();
  }
}

void UpdateScene(sf::RenderWindow &window) {
  for (auto &sceneObject : activeGameObjects) {
    sceneObject->Draw(window);
    sceneObject->Update(deltaTime.asSeconds());
    if (ICollide *collidable = dynamic_cast<ICollide *>(sceneObject)) {
      Physics::Debug::DrawCollider(collidable, window, sf::Color::Red);
    }
  }
}

void HandleWindowEvents(sf::RenderWindow &window) {
  while (const std::optional event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      window.close();
  }
}

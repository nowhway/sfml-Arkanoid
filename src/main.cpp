#include "Ball.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Exception.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

void HandleWindowEvents(sf::RenderWindow &window);
void UpdateScene(sf::RenderWindow &window);
std::vector<std::unique_ptr<GameObject>> activeGameObjects;
sf::Time deltaTime;

int main() {
  // building platform sprite

  const sf::Texture texture_platform("assets/textures/platform.png");
  std::unique_ptr<GameObject> platform_ptr = std::make_unique<Platform>(
      texture_platform, 100.0f, (sf::Vector2f){3.0f, 3.0f});

  const sf::Texture texture_ball("assets/textures/kula.png");
  std::unique_ptr<GameObject> ball_ptr = std::make_unique<Ball>(texture_ball);

  sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!");
  // sf::CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);

  sf::Clock deltaClock;
  activeGameObjects.push_back(std::move(ball_ptr));
  activeGameObjects.push_back(std::move(platform_ptr));
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
  }
}

void HandleWindowEvents(sf::RenderWindow &window) {
  while (const std::optional event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      window.close();
  }
}

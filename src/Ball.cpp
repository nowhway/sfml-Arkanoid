#include "Ball.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

Ball::Ball(const sf::Texture &texture) : sprite(texture) {}

void Ball::Update(float deltaTime) {}

void Ball::Draw(sf::RenderWindow &window) { window.draw(sprite); }

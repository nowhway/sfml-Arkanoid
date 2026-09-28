#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
enum class ColliderType { RECT, CIRC };
class Collider {
public:
  ColliderType type;
  virtual ~Collider() = default;

protected:
  Collider(ColliderType t) : type(t) {}
};

class CircleCollider : public Collider {
private:
  double radius;
  sf::Vector2f offset;

public:
  CircleCollider(double r, sf::Vector2f offset)
      : Collider(ColliderType::CIRC), radius(r), offset(offset) {}
  double GetRadius() { return radius; }
  sf::Vector2f GetOffset() { return offset; }
  void SetOffset(sf::Vector2f vec) { offset = vec; }
  void SetRadius(double r) { radius = r; }
};

class RectangleCollider : public Collider {
private:
  sf::Vector2f offset;
  sf::Vector2f bounds;

public:
  RectangleCollider(sf::Vector2f bounds, sf::Vector2f offset)
      : Collider(ColliderType::RECT), offset(offset), bounds(bounds) {}
  sf::Vector2f GetBounds() { return bounds; }
  sf::Vector2f GetOffset() { return offset; }
  void SetBounds(sf::Vector2f vec) { bounds = vec; }
  void SetOffset(sf::Vector2f vec) { offset = vec; }
};

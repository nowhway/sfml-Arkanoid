#pragma once

#include "ICollide.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
class Physics {
public:
  enum class CollisionType { BOUNCE, STOP };

private:
  struct MovePacket {
    ICollide *obj;
    sf::Vector2f displacement;
    sf::Time moveTime;
    CollisionType type;
  };

private:
  std::vector<MovePacket> moveQueries;
  sf::Time refreshRate;
  sf::Time accumulator;

private:
  void tick();
  void InsertMovePacket(MovePacket packet);
  bool CircVsRect(Collider *A);

public:
  std::vector<ICollide *> objectPool;

public:
  Physics(sf::Time refreshRate);
  void ComputeMove(ICollide *ptr, sf::Vector2f vec, CollisionType type);
  void PhysicsStep(sf::Time step);
  class Debug {
  public:
    static void DrawCollider(ICollide *object_ptr, sf::RenderWindow &window,
                             sf::Color color);
  };
};

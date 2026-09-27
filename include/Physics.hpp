#pragma once

#include "ICollide.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>
class Physics {
private:
  struct MovePacket {
    std::unique_ptr<ICollide> *obj;
    sf::Vector2f displacement;
    sf::Time moveTime;
  };

private:
  std::vector<MovePacket> moveQueries;
  sf::Time refreshRate;
  sf::Time accumulator;

private:
  void tick();
  void InsertMovePacket(MovePacket packet);

public:
  Physics(sf::Time refreshRate);
  void ComputeMove(std::unique_ptr<ICollide> *ptr, sf::Vector2f vec);
  void PhysicsStep(sf::Time step);
  class Debug {
    void DrawCollider(std::unique_ptr<ICollide> *object_ptr,
                      sf::RenderWindow &window, sf::Color color);
  };
};

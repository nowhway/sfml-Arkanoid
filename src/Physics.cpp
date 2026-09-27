#include "Physics.hpp"
#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
Physics::Physics(sf::Time refreshRate) : refreshRate(refreshRate) {}

void Physics::PhysicsStep(sf::Time step) {
  for (auto &packet : moveQueries) {
    packet.moveTime += step;
  }

  while (step.asSeconds() > 0) {
    if (step >= refreshRate) {
      step -= refreshRate;
      tick();
    } else if (step + accumulator >= refreshRate) {
      accumulator += step;
      step = sf::Time();
      accumulator -= refreshRate;
    }
  }
  moveQueries.clear();
}

void Physics::ComputeMove(std::unique_ptr<ICollide> *ptr, sf::Vector2f vec) {
  MovePacket packet = {ptr, vec, sf::Time()};

  InsertMovePacket(packet);
}

void Physics::InsertMovePacket(MovePacket movePacket) {
  for (auto &packet : moveQueries) {
    if (packet.obj == movePacket.obj) {
      packet.displacement += movePacket.displacement;
      return;
    }
  }
  moveQueries.push_back(movePacket);
}

void Physics::Debug::DrawCollider(std::unique_ptr<ICollide> *object_ptr,
                                  sf::RenderWindow &window, sf::Color color) {

  ICollide *ICollide_ptr = (*object_ptr).get();
  GameObject *obj_ptr = dynamic_cast<GameObject *>(ICollide_ptr);
  Collider *col_ptr = ICollide_ptr->GetCollider()->get();

  if (CircleCollider *col = dynamic_cast<CircleCollider *>(col_ptr)) {
    sf::CircleShape circle{(float)col->GetRadius()};
    circle.setOutlineColor(color);
    circle.setPosition(col->GetOffset() + obj_ptr->getPosition());
    window.draw(circle);
  }

  if (RectangleCollider *col = dynamic_cast<RectangleCollider *>(col_ptr)) {
    sf::RectangleShape rect{col->GetBounds()};
    rect.setPosition(col->GetOffset() + obj_ptr->getPosition());
    rect.setOutlineColor(color);
    window.draw(rect);
  }
}

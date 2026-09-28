#include "Physics.hpp"
#include "Collider.hpp"
#include "GameObject.hpp"
#include "ICollide.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <algorithm>
#include <iostream>
Physics::Physics(sf::Time refreshRate)
    : refreshRate(refreshRate), accumulator() {}

void Physics::PhysicsStep(sf::Time step) {
  for (auto &packet : moveQueries) {
    packet.moveTime += step;
  }

  while (step.asSeconds() > 0) {
    if (step >= refreshRate) {
      step -= refreshRate;
    } else if (step + accumulator >= refreshRate) {
      accumulator += step;
      step = sf::Time();
      accumulator -= refreshRate;
    }
    tick();
  }
  moveQueries.clear();
}

void Physics::ComputeMove(ICollide *ptr, sf::Vector2f vec, CollisionType type) {
  MovePacket packet = {ptr, vec, sf::Time(), type};

  InsertMovePacket(packet);
}

void Physics::tick() {
  for (auto &packet : moveQueries) {

    for (auto &hit : objectPool) {
      if (hit == packet.obj)
        continue;
      ColliderType packetType = packet.obj->GetCollider()->type;
      ColliderType hitType = hit->GetCollider()->type;

      bool didIntersect;
      switch (packetType) {
      case ColliderType::CIRC: {
        if (hitType == ColliderType::RECT)
          didIntersect =
      }
      case ColliderType::RECT:
        break;
      }
    }
  }
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

void Physics::Debug::DrawCollider(ICollide *object_ptr,
                                  sf::RenderWindow &window, sf::Color color) {

  GameObject *gameobject = dynamic_cast<GameObject *>(object_ptr);
  Collider *col_ptr = object_ptr->GetCollider();

  if (CircleCollider *col = dynamic_cast<CircleCollider *>(col_ptr)) {
    sf::CircleShape circle{(float)col->GetRadius()};
    circle.setOutlineColor(color);
    circle.setPosition(col->GetOffset() + gameobject->GetPosition());
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(2.0f);
    window.draw(circle);
  }
  std::cout << "something drawn" << std::endl;
  if (RectangleCollider *col = dynamic_cast<RectangleCollider *>(col_ptr)) {
    sf::RectangleShape rect{col->GetBounds()};
    rect.setPosition(col->GetOffset() + gameobject->GetPosition());
    rect.setOutlineColor(color);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(2.0f);
    window.draw(rect);
  }
}

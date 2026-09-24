#pragma once
#include "Collider.hpp"
#include <memory>
class ICollide {
public:
  virtual ~ICollide() = default;
  virtual std::unique_ptr<Collider> GetCollider() = 0;
};

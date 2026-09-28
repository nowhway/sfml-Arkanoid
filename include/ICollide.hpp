#pragma once
#include "Collider.hpp"
#include <memory>
class ICollide {
protected:
  std::unique_ptr<Collider> collider;

public:
  virtual ~ICollide() = default;
  virtual Collider *GetCollider() = 0;
};

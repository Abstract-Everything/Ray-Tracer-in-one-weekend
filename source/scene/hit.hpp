#pragma once

#include "point.hpp"
#include "direction.hpp"

namespace scene
{

class Material;

struct Hit
{
  bool valid = false;
  float distance = 0;
  geo::Point position = geo::zero;
  geo::Direction normal = geo::up;

  Material *material;
};

}

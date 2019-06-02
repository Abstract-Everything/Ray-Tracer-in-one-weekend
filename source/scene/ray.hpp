#pragma once

#include <limits>

#include "vector.hpp"
#include "point.hpp"
#include "direction.hpp"

namespace scene
{

struct Ray
{
  const float epsilon = 1e-3;

  float min = epsilon;
  float max = std::numeric_limits<float>::max();
  geo::Point position = geo::zero;
  geo::Direction direction = geo::up;

  Ray () {}

  Ray (
    geo::Point const &p_position,
    geo::Direction const &p_direction
  ) : position(p_position), direction(p_direction) {}

  Ray& operator= (Ray const &ray)
  {
    min = ray.min;
    max = ray.max;
    position = ray.position;
    direction = ray.direction;
    return *this;
  }

  geo::Point offset(float distance) const
  { return position + direction * distance; }
};

}

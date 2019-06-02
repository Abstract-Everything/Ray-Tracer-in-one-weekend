#pragma once

#include "vector.hpp"
#include "point.hpp"
#include "direction.hpp"

namespace scene
{

class Orthonormal_Basis
{
public:
  geo::Direction right = geo::right;
  geo::Direction up = geo::up;
  geo::Direction forward = geo::forward;

  Orthonormal_Basis()
  { }

  Orthonormal_Basis(
      geo::Direction const &towards,
      geo::Direction const &world_up = geo::up)
  {
    forward = towards;
    right = cross(world_up, forward);
    up = cross(forward, right);

    assert(length(geo::Vector(right)) > 0.9f &&
           "Basis forward and up should not be parallel.");
  }

  Orthonormal_Basis(
      geo::Point const &origin,
      geo::Point const &target,
      geo::Direction const &world_up = geo::up)
  {
    forward = target - origin;
    right = cross(world_up, forward );
    up = cross(forward, right);

    assert(length(geo::Vector(right)) > 0.9f &&
           "Basis forward and up should not be parallel.");
  }
};

}

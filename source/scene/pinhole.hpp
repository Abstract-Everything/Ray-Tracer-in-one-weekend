#pragma once

#include "camera.hpp"

#include "vector.hpp"
#include "point.hpp"
#include "direction.hpp"

namespace scene
{

class Pinhole : public Camera
{
public:
  Pinhole(geo::Point const &position)
    : Camera(position) {};

  Pinhole(geo::Point const &position, geo::Direction const &direction)
    : Camera(position, direction) {};

  virtual Ray get_ray(float x, float y, std::array<float, 3> random) const override;
};

}

#pragma once

#include "constants.hpp"
#include "camera.hpp"

#include "vector.hpp"
#include "point.hpp"
#include "direction.hpp"

namespace scene
{

class Lens : public Camera
{
public:
  Lens(geo::Point const &position, float aperture, float distance)
    : Camera(position, distance), lens_radius(aperture / 2.0f) {}

  Lens(geo::Point const &position, geo::Direction const &direction, float aperture, float distance)
    : Camera(position, direction, distance), lens_radius(aperture / 2.0f) {}

  virtual Ray get_ray(float x, float y, std::array<float, 3> random) const override;

private:
  const float lens_radius = 1.0f;
};

}

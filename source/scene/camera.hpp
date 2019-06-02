#pragma once

#include <array>

#include "constants.hpp"
#include "vector.hpp"
#include "point.hpp"
#include "direction.hpp"
#include "orthonormal_basis.hpp"
#include "ray.hpp"

namespace scene
{

class Camera
{
public:
  Camera(geo::Point const &position, float distance);
  Camera(geo::Point const &position, geo::Direction const &direction, float distance);

  Camera(geo::Point const &position)
    : Camera(position, 1.0f) { }
  Camera(geo::Point const &position, geo::Direction const &direction)
  : Camera(position, direction, 1.0f) { }

  virtual Ray get_ray(float x, float y, std::array<float, 3> random) const = 0;

protected:
  geo::Point origin = geo::zero;
  Orthonormal_Basis basis;
  geo::Vector frame_corner;
  geo::Vector frame_right_axis;
  geo::Vector frame_up_axis;

private:
  const float fov = math::pi / 4.0f;
  const float aspect = 9.0f / 16.0f;
  const float frame_distance = 1.0f;
  void set_frame();
};

}

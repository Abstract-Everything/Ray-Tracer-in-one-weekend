#include "pinhole.hpp"

scene::Ray scene::Pinhole::get_ray(float x, float y, std::array<float, 3> /* random */) const
{
  return Ray (
      origin,
      frame_corner +
      frame_right_axis * x +
      frame_up_axis * y
    );
}

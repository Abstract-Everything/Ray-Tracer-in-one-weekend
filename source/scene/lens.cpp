#include "lens.hpp"

namespace
{

std::array<float, 2> sample_unit_circle(float distance, float rotation)
{
  float radius = std::sqrt(distance);
  float theta = 2.0f * math::pi * rotation - math::pi;
  float x = radius * std::cos(theta);
  float y = radius * std::sin(theta);
  return {x, y};
}

} // namespace

scene::Ray scene::Lens::get_ray(float x, float y, std::array<float, 3> random) const
{
  auto [x_offset, y_offset] = sample_unit_circle(random[0], random[1]);
  geo::Vector offset = (basis.right * x_offset + basis.up * y_offset) * lens_radius;
  return Ray (
      origin + offset,
      frame_corner +
      frame_right_axis * x +
      frame_up_axis * y -
      offset
    );
}

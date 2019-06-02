#include "camera.hpp"

scene::Camera::Camera(geo::Point const &position, float distance)
  : frame_distance(distance)
{
  origin = position;
  set_frame();
}

scene::Camera::Camera(geo::Point const &position, geo::Direction const &direction, float distance)
  :frame_distance(distance)
{
  origin = position;
  basis = Orthonormal_Basis(direction);
  set_frame();
}

void scene::Camera::set_frame()
{
  float frame_width = 2.0f * std::tan(fov * 0.5f) * frame_distance;
  float frame_height = frame_width * aspect;

  frame_right_axis = basis.right * frame_width;
  frame_up_axis = basis.up * frame_height;
  frame_corner = basis.forward * frame_distance -
                 frame_right_axis * 0.5f -
                 frame_up_axis * 0.5f;
}

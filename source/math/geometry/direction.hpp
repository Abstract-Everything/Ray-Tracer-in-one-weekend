#pragma once 

#include <cassert>
#include <cmath>

namespace geo
{

class Direction
{

public:
  float x, y, z;

  Direction(float p_x, float p_y, float p_z)
  {
    assert(!(std::abs(p_x) + std::abs(p_y) + std::abs(p_z) == 0) &&
           "The components of a direction should not all be zero");

    float distance = 1.0f / std::sqrt(dot(p_x, p_y, p_z));
    x = p_x * distance;
    y = p_y * distance;
    z = p_z * distance;
  }

  Direction(float p_x, float p_y, float p_z, float length)
  {
    length = 1.0f / length;
    x = p_x * length;
    y = p_y * length;
    z = p_z * length;

    assert(std::fabs(dot(x, y, z) - 1.0f) <= 1e-5 &&
           "The direction is not normalized with the given length");
  }

private:
  inline float dot(float x, float y, float z)
  {
    return x * x + y * y + z * z;
  }
};

const Direction right = Direction(1, 0, 0);
const Direction left = Direction(-1, 0, 0);
const Direction up = Direction(0, 1, 0);
const Direction down = Direction(0, -1, 0);
const Direction forward = Direction(0, 0, 1);
const Direction back = Direction(0, 0, -1);
} // namespace 3D


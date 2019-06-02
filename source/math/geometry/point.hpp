#pragma once

namespace geo
{

class Point
{
public:
  float x = 0;
  float y = 0;
  float z = 0;

  Point(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {}
};

const Point zero = Point(0, 0, 0);
}

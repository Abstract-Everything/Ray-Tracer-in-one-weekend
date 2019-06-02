#pragma once

#include "constants.hpp"
#include "shape.hpp"

#include "vector.hpp"
#include "point.hpp"
#include "ray.hpp"

namespace scene
{

class Sphere : public Shape
{
public:
  Sphere(geo::Point const &p_position, float p_radius);
  bool check_hit(Ray const &ray, Hit &hit) const override;

  static geo::Vector sample_unit_volume(std::pair<float, float> const &random);

private:
  float radius;
  geo::Point origin = geo::zero;

  bool select_shortest(Ray const &ray, float &chosen, float shortest, float furthest) const;
};

}

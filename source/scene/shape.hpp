#pragma once

#include "ray.hpp"
#include "hit.hpp"

namespace scene
{

class Shape
{
public:
  virtual ~Shape() {};
  virtual bool check_hit(Ray const &ray, Hit &hit) const = 0;
};

}

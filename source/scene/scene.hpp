#pragma once

#include <memory>
#include <vector>

#include "primitive.hpp"
#include "ray.hpp"

namespace scene
{

class Scene
{
public:
  Scene(std::vector<Primitive> &p_primitives);
  bool check_hit(Ray const &ray, Hit &hit) const;

private:
  std::vector<Primitive> primitives;
};

}

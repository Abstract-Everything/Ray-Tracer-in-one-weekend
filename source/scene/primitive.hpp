#pragma once

#include <memory>

#include "shape.hpp"
#include "material.hpp"

#include "ray.hpp"
#include "hit.hpp"

namespace scene
{

class Primitive
{
public:
  std::unique_ptr<Shape> shape;
  std::unique_ptr<Material> material;

  template<typename S, typename M>
  Primitive(S const &p_shape, M const &p_material)
  {
    shape = std::make_unique<S>(std::move(p_shape));
    material = std::make_unique<M>(std::move(p_material));
  }

  template<typename S>
  Primitive (
      S const &p_shape,
      std::unique_ptr<scene::Material> &p_material
  ) {
    shape = std::make_unique<S>(std::move(p_shape));
    material = std::move(p_material);
  }

  bool check_hit(Ray const &ray, Hit &hit) const
  {
    return shape->check_hit(ray, hit);
  }
};

}

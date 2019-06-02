#include "scene.hpp"

scene::Scene::Scene(std::vector<Primitive> &p_primitives)
{
  primitives = std::move(p_primitives);
}

bool scene::Scene::check_hit(Ray const &ray, Hit &hit) const
{
  hit.valid = false;
  scene::Hit latest;
  for (auto const& primitive : primitives)
  {
    if (primitive.check_hit(ray, latest))
    {
      if (!hit.valid || hit.distance > latest.distance)
      {
        hit = latest;
        hit.material = primitive.material.get();
      }
    }
  }

  return hit.valid;
}

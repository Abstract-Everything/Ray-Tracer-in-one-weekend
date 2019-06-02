#pragma once

#include "ray.hpp"
#include "hit.hpp"
#include "colour.hpp"

namespace scene
{

class Material
{
public:
  virtual ~Material() {};
  virtual bool scatter(Ray const &outgoing, Hit const &hit, img::Colour &attenuation, Ray &incoming) const = 0;
};

}

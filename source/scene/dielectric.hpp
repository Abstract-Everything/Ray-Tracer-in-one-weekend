#pragma once

#include "random.hpp"

#include "material.hpp"

#include "ray.hpp"
#include "hit.hpp"
#include "colour.hpp"

namespace scene
{

class Dielectric : public Material
{
public:
  Dielectric(float p_eta);
  bool scatter(Ray const &outgoing, Hit const &hit, img::Colour &attenuation, Ray &incoming) const override;

private:
  float eta;
};

}

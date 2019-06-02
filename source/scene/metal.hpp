#pragma once

#include "random.hpp"

#include "material.hpp"

#include "colour.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include "sphere.hpp"

namespace scene
{

class Metal : public Material
{
public:
  Metal(img::Colour const &p_albedo, float p_roughness);
  bool scatter(Ray const &outgoing, Hit const &hit, img::Colour &attenuation, Ray &incoming) const override;

private:
  float roughness;
  img::Colour albedo;
};

}

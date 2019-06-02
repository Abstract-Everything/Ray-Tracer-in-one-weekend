#pragma once

#include "random.hpp"

#include "material.hpp"

#include "colour.hpp"
#include "ray.hpp"
#include "hit.hpp"
#include "sphere.hpp"

namespace scene
{

class Lambertian : public Material
{
public:
  Lambertian(img::Colour const &p_albedo);
  bool scatter(Ray const &outgoing, Hit const &hit, img::Colour &attenuation, Ray &incoming) const override;

private:
  img::Colour albedo;
};

}

#include "metal.hpp"

scene::Metal::Metal(img::Colour const &p_albedo, float p_roughness)
  :  roughness(p_roughness), albedo(p_albedo)
{
  assert(0.0f <= roughness && roughness <= 1.0f &&    //NOLINT
         "Expected roughness to be normalized");      //NOLINT
}

bool scene::Metal::scatter(
    Ray const & outgoing,
    Hit const &hit,
    img::Colour &attenuation,
    Ray &incoming) const
{
  std::pair<float, float> random = {rng::next(), rng::next()};
  geo::Vector offset = roughness * scene::Sphere::sample_unit_volume(random);
  geo::Direction reflected = reflect(outgoing.direction, hit.normal) + offset;
  incoming = scene::Ray(hit.position, reflected);
  attenuation = albedo;
  return dot(incoming.direction, hit.normal) > 0;
}

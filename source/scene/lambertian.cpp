#include "lambertian.hpp"

scene::Lambertian::Lambertian(img::Colour const &p_albedo) : albedo(p_albedo) {}

bool scene::Lambertian::scatter(
    Ray const & /* outgoing */,
    Hit const &hit,
    img::Colour &attenuation,
    Ray &incoming) const
{
  auto random = std::pair{rng::next(), rng::next()};
  geo::Direction sample_direction = geo::Vector(hit.normal) + scene::Sphere::sample_unit_volume(random);
  incoming = scene::Ray(hit.position, sample_direction);
  attenuation = albedo;
  return true;
}

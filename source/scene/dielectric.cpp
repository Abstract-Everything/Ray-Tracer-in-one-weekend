#include "dielectric.hpp"

namespace
{
  float schlick_approximation(float cos_theta, float eta)
  {
    float r = (eta - 1) / (eta + 1);
    r = r * r;

    return r + (1 - r) * std::pow(1.0f - cos_theta, 5);
  }
} // namespace

scene::Dielectric::Dielectric(float p_eta) : eta(p_eta)
{ }

bool scene::Dielectric::scatter(
    Ray const &outgoing,
    Hit const &hit,
    img::Colour &attenuation,
    Ray &incoming) const
{
  auto normal = hit.normal;
  float eta_ratio = eta;
  float cos_theta = dot(-outgoing.direction, normal);
  if (cos_theta < 0)
  {
    normal = -normal;
    eta_ratio = 1.0f / eta;
    cos_theta *= -eta;
  }

  attenuation = img::Colour(1.0f, 1.0f, 1.0f);
  incoming.position = hit.position;
  float reflect_chance = can_refract(outgoing.direction, normal, eta_ratio) ?
                         schlick_approximation(cos_theta, eta) : 1.0f;

  incoming.direction = rng::next() < reflect_chance ?
                       reflect(outgoing.direction, normal) :
                       refract(outgoing.direction, normal, eta_ratio);

  return true;
}

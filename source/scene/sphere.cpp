#include "sphere.hpp"

scene::Sphere::Sphere(geo::Point const &p_position, float p_radius)
{
  origin = p_position;
  radius = p_radius;
}

bool scene::Sphere::check_hit(Ray const &ray, scene::Hit &hit) const
{
  auto towards_origin = ray.position - origin;
  float b = dot(towards_origin, ray.direction);
  float c = dot(towards_origin, towards_origin) - radius * radius;
  float discriminant = b * b - c;
  if (discriminant < 0)
  {
    return false;
  }

  auto offset = std::sqrt(discriminant);
  if (!select_shortest(ray, hit.distance, -b - offset, -b + offset))
  {
    return false;
  }

  hit.position = ray.offset(hit.distance);
  hit.normal = normalize(hit.position - origin);
  return hit.valid = true;
}

bool scene::Sphere::select_shortest(
    Ray const &ray,
    float &chosen,
    float shortest,
    float furthest
) const {
  chosen = 0.0f;
  if (shortest > ray.min && shortest < ray.max)
  {
    chosen = shortest;
  }
  else if (furthest > ray.min && shortest < ray.max)
  {
    chosen = furthest;
  }

  return chosen != 0.0f;
}

geo::Vector scene::Sphere::sample_unit_volume(std::pair<float, float> const &random)
{
  float height = 2.0f * random.first - 1.0f;
  float radius = std::sqrt(1 - height * height);
  float theta = random.second * math::pi * 2.0f;
  float right = radius * std::cos(theta);
  float forward = radius * std::sin(theta);

  return geo::up * height +
         geo::right * right +
         geo::forward * forward;
}

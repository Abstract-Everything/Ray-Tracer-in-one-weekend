#include <iostream>

#include "camera.hpp"
#include "colour.hpp"
#include "dielectric.hpp"
#include "frame.hpp"
#include "hit.hpp"
#include "lambertian.hpp"
#include "lens.hpp"
#include "metal.hpp"
#include "pinhole.hpp"
#include "point.hpp"
#include "ppm.hpp"
#include "random.hpp"
#include "scene.hpp"
#include "shape.hpp"
#include "sphere.hpp"

img::Frame gamma_correct(img::Frame const &frame)
{
  img::Frame gamma_corrected = frame;
  for (auto &pixel : gamma_corrected.buffer)
  {
    pixel = sqrt(pixel);
  }

  return gamma_corrected;
}

img::Colour background(scene::Ray const &ray)
{
  float lerp = 0.5f * (ray.direction.y + 1.0f);
  return lerp * img::white + (1.0f - lerp) * img::Colour(0.1f, 0.3f, 0.7f);
}

img::Colour render_scene(scene::Scene const &scene, scene::Ray const &ray, unsigned int bounces)
{
  const unsigned int bounces_max = 50;
  if (bounces > bounces_max)
  {
    return img::black;
  }

  scene::Hit hit;
  if (scene.check_hit(ray, hit))
  {
    scene::Ray incoming;
    img::Colour attenuation = img::black;
    return (hit.material->scatter(ray, hit, attenuation, incoming)) ?
           attenuation * render_scene(scene, incoming, bounces + 1) :
           img::black;
  }

  return background(ray);
}

std::unique_ptr<scene::Material> choose_random_material()
{
  auto albedo = img::Colour(rng::next(), rng::next(), rng::next());

  float choice = rng::next();
  if (choice < 0.20f)
  {
    albedo = 0.5f * (1.0f + albedo);
    return std::make_unique<scene::Metal>(albedo, 0.5f * rng::next());
  }

  if (choice < 0.90f)
  {
    return std::make_unique<scene::Lambertian>(albedo);
  }

  return std::make_unique<scene::Dielectric>(1.0f / 1.5f);
}

scene::Scene generate_random_scene()
{
  std::vector<scene::Primitive> primitives;

  const scene::Sphere floor_shape(geo::Point(0.0f, -5000.0f, 0.0f), 5000.0f);
  const scene::Lambertian floor_material(img::Colour(0.8f, 0.8f, 0.0f));
  primitives.emplace_back(floor_shape, floor_material);

  for (float y = -10; y < 10;)
  {
    float largest_radus = 0;
    for (float x = -10; x < 10;)
    {
      float radius = rng::next();
      largest_radus = radius > largest_radus ? radius : largest_radus;

      const float x_offset = radius + 2.0f * radius * rng::next();
      const float y_offset = radius + 2.0f * radius * rng::next();
      geo::Point centre(x + x_offset, radius, y + y_offset);
      x += 4.0f * radius;

      scene::Sphere sphere(centre, radius);
      std::unique_ptr<scene::Material> material = choose_random_material();
      primitives.emplace_back(sphere, material);
    }

    y += 4.0 * largest_radus;
  }

  return scene::Scene(primitives);
}

int main()
{
  const size_t no_samples = 5 * 5;

  img::Frame frame(1280, 720);
  scene::Scene scene = generate_random_scene();

  geo::Point position(0.0f, 4.0f, -15.0f);
  // scene::Pinhole camera(position, - geo::Vector(position));
  scene::Lens camera(position, - geo::Vector(position), 0.2f, length(geo::Vector(position)));
  
  for (size_t i = 0; i < frame.height; ++i)
  {
    for (size_t j = 0; j < frame.width; ++j)
    {
      img::Colour pixel = img::black;
      for (size_t sample = 0; sample < no_samples; ++sample)
      {
        std::array<float, 3> random = {rng::next(), rng::next(), rng::next()};
        float x = static_cast<float>(j + rng::next()) / static_cast<float>(frame.width);
        float y = static_cast<float>(i + rng::next()) / static_cast<float>(frame.height);
        auto ray = camera.get_ray(x, y, random);
        pixel += render_scene(scene, ray, 0);
      }

      pixel /= static_cast<float>(no_samples);
      frame.buffer[i * frame.width + j] = pixel;
    }
  }

  std::cout << img::ppm::convert(gamma_correct(frame));
}

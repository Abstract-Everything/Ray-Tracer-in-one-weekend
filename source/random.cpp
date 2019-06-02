#include "random.hpp"

float rng::next()
{
  thread_local static std::random_device device;
  thread_local static std::default_random_engine engine{std::random_device()()};
  thread_local static std::uniform_real_distribution<float> distribution(0, 1);
  return distribution(engine);
}


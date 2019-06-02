#pragma once

#include <vector>

#include "colour.hpp"

namespace img
{

class Frame
{
public:
  Frame(size_t p_width, size_t p_height);
  Frame(size_t p_width, size_t p_height, std::vector<float> const &p_buffer);

  size_t width;
  size_t height;
  std::vector<Colour> buffer;
};

}

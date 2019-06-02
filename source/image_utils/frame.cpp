#include "frame.hpp"

img::Frame::Frame(size_t p_width, size_t p_height)
      : width(p_width), height(p_height)
{
  buffer.resize(width * height, img::black);
}

img::Frame::Frame(
    size_t p_width,
    size_t p_height,
    std::vector<float> const &p_buffer
  ) : width(p_width), height(p_height)
{
  assert(p_buffer.size() == width * height * 3 &&                 //NOLINT
         "Buffer width and height do not match with its size");   //NOLINT

  for (size_t i = 0; i < p_buffer.size(); i += 3)
  {
    buffer.emplace_back(p_buffer[i + 0], p_buffer[i + 1], p_buffer[i + 2]);
  }
}

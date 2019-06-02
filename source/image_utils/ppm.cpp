#include "ppm.hpp"

std::string img::ppm::convert(img::Frame const &frame, size_t white_value)
{
  std::stringstream ppm;
  ppm << "P3\n"
      << frame.width << " " << frame.height << "\n"
      << white_value << "\n";

  for (size_t i = frame.height; i > 0; --i)
  {
    for (size_t j = 0; j < frame.width; ++j)
    {
      auto pixel = frame.buffer[(i - 1) * frame.width + j];
      auto output = white_value * pixel;
      ppm << std::to_string(static_cast<uint8_t>(output.r)) << " "
        << std::to_string(static_cast<uint8_t>(output.g)) << " "
        << std::to_string(static_cast<uint8_t>(output.b)) << "\n";
    }
  }


  return ppm.str();
}

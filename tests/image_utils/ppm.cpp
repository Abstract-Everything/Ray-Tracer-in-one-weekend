#include <catch2/catch.hpp>
#include <iostream>
#include "frame.hpp"
#include "ppm.hpp"

#ifdef _MSC_VER
# define width static_cast<size_t>(2)
# define height static_cast<size_t>(2)
#else
  const size_t width = 2;
  const size_t height = 2;
#endif

TEST_CASE("Converting frame to ppm", "[image][ppm]")
{
  auto buffer_values = GENERATE(take(1, chunk(width * height * 3, random(0.0f, 1.0f))));

  img::Frame frame(width, height, buffer_values);
  std::string ppm_result = 
      "P3\n" +
      std::to_string(width) + " " + std::to_string(height) + "\n" +
      std::to_string(255) + "\n" +

      std::to_string(static_cast<uint8_t>(buffer_values[ 6] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[ 7] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[ 8] * 255)) + "\n" +

      std::to_string(static_cast<uint8_t>(buffer_values[ 9] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[10] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[11] * 255)) + "\n" +
                                                                  
      std::to_string(static_cast<uint8_t>(buffer_values[ 0] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[ 1] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[ 2] * 255)) + "\n" +

      std::to_string(static_cast<uint8_t>(buffer_values[ 3] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[ 4] * 255)) + " "  +
      std::to_string(static_cast<uint8_t>(buffer_values[ 5] * 255)) + "\n";
                                                                  
  REQUIRE(img::ppm::convert(frame) == ppm_result);
}

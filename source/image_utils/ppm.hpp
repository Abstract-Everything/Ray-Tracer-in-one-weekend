#pragma once

#include <sstream>
#include <string>

#include "frame.hpp"

namespace img
{
namespace ppm
{

std::string convert(img::Frame const &frame, size_t white_value = 255);

}
}

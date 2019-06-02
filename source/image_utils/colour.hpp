#pragma once

#include <cassert>
#include <cmath>

namespace img
{

class Colour
{

public:
  float r = 0;
  float g = 0;
  float b = 0;

  Colour(float p_r, float p_g, float p_b) : r(p_r), g(p_g), b(p_b)
  {
    assert(r >= 0 && g >= 0 && b >= 0 &&
           "Colour components should be positive.");
  }

  inline Colour& operator/=(float scalar);
  inline Colour& operator+=(Colour const &from);
};

const Colour white = Colour(1.0f, 1.0f, 1.0f);
const Colour black = Colour(0.0f, 0.0f, 0.0f);

// Scalar operations
inline img::Colour operator+(img::Colour const &colour, float scalar)
{
  return img::Colour(
      colour.r + scalar,
      colour.g + scalar,
      colour.b + scalar
    );
}

inline img::Colour operator+(float scalar, img::Colour const &colour)
{
  return colour + scalar;
}

inline img::Colour operator*(img::Colour const &colour, float scalar)
{
  return img::Colour(
      colour.r * scalar,
      colour.g * scalar,
      colour.b * scalar
    );
}

inline img::Colour operator*(float scalar, img::Colour const &colour)
{
  return colour * scalar;
}

inline img::Colour operator/(img::Colour const &colour, float scalar)
{
  return colour * (1 / scalar);
}

inline Colour &Colour::operator/=(float scalar)
{
  *this = *this / scalar;
  return *this;
}

// Colour operations
inline img::Colour operator+(img::Colour const &left, img::Colour const &right)
{
  return img::Colour(
      left.r + right.r,
      left.g + right.g,
      left.b + right.b
    );
}

inline img::Colour operator*(img::Colour const &left, img::Colour const &right)
{
  return img::Colour(
      left.r * right.r,
      left.g * right.g,
      left.b * right.b
    );
}

inline Colour &Colour::operator+=(Colour const &from)
{
  *this = *this + from;
  return *this;
}

inline Colour sqrt(Colour const &colour)
{
  return Colour(
      std::sqrt(colour.r),
      std::sqrt(colour.g),
      std::sqrt(colour.b)
    );
}

} // namespace img

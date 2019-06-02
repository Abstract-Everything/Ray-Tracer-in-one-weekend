#pragma once

#include <istream>
#include <ostream>
#include <cmath>

#include "point.hpp"
#include "direction.hpp"

namespace geo
{

class Vector
{
public:
  float x;
  float y;
  float z;

  Vector() : x(0), y(0), z(0) {}
  Vector(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {}
  explicit Vector(Point const &Point) : x(Point.x), y(Point.y), z(Point.z) {}
  explicit Vector(Direction const &Direction)
      : x(Direction.x), y(Direction.y), z(Direction.z) {}

  operator Point() { return Point(x, y, z); }
  operator Direction() { return Direction(x, y, z); }
};

// Scalar operations
inline Vector operator+(Vector const &vector, float const scalar)
{
  return Vector(vector.x + scalar, vector.y + scalar, vector.z + scalar);
}

inline Vector operator+(float const scalar, Vector const &vector)
{
  return vector + scalar;
}

inline Vector operator-(Vector const &vector, float const scalar)
{
  return vector + (-scalar);
}

inline Vector operator*(Vector const &vector, float const scalar)
{
  return Vector(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

inline Vector operator*(float const scalar, Vector const &vector)
{
  return vector * scalar;
}

inline Vector operator/(Vector const &vector, float const scalar)
{
  return vector * (1 / scalar);
}
 // Vector operations
inline Vector operator+(Vector const &left, Vector const &right)
{
  return Vector(left.x + right.x, left.y + right.y, left.z + right.z);
}

inline Vector operator-(Vector const &vector)
{
  return Vector(-vector.x, -vector.y, -vector.z);
}

inline Vector operator-(Vector const &left, Vector const &right)
{
  return left + (-right);
}

inline Vector cross(Vector const &left, Vector const &right)
{
  return Vector(
    left.y * right.z - left.z * right.y,
  -(left.x * right.z - left.z * right.x),
    left.x * right.y - left.y * right.x
  );
}

inline float dot(Vector const &left, Vector const &right)
{
  return left.x * right.x + left.y * right.y + left.z * right.z;
}

inline float dot(Direction const &direction, Vector const &vector)
{
  return dot(Vector(direction), vector);
}

inline float dot(Vector const &vector, Direction const &direction)
{
  return dot(direction, vector);
}

inline float dot(Direction const &left, Direction const &right)
{
  return dot(Vector(left), Vector(right));
}

inline float length_squared(Vector const &vector)
{
  return dot(vector, vector);
}

inline float length(Vector const &vector)
{
  return std::sqrt(length_squared(vector));
}

inline Direction normalize(Vector const &vector)
{
  return Direction(vector.x, vector.y, vector.z, length(vector));
}

inline Direction normalize(Vector const &vector, float length)
{
  return Direction(vector.x, vector.y, vector.z, length);
}

// Miscellaneous
inline std::istream& operator>>(std::istream &is, Vector &vector)
{
  is >> vector.x >> vector.y >> vector.z;
  return is;
}

inline std::ostream& operator<<(std::ostream &os, Vector const &vector)
{
  os << "[ " << vector.x << ", " << vector.y << ", " << vector.z << " ]";
  return os;
}


// Point operations
inline Point operator+(Point const &point, Vector const &vector)
{
  return Vector(point) + vector;
}

inline Point operator+(Vector const &vector, Point const &Point)
{
  return Point + vector;
}

inline Point operator-(Point const &Point, Vector const &vector)
{
  return Vector(Point) - vector;
}

inline Vector operator-(Point const &left, Point const &right)
{
  return Vector(left) - Vector(right);
}


// Direction operations
inline Vector operator*(Direction const &direction, float const scalar)
{
  return Vector(direction) * scalar;
}

inline Direction operator-(Direction const &direction)
{
  return Direction(
      -direction.x,
      -direction.y,
      -direction.z,
      1.0f
    );
}

inline Vector operator*(float const scalar, Direction const &direction)
{
  return Vector(direction) * scalar;
}

inline Direction cross(Direction const &left, Direction const &right)
{
  return cross(Vector(left), Vector(right));
}

inline Vector reflect(Direction const &direction, Direction const &normal = up)
{
  return Vector(direction) - 2.0f * dot(direction, normal) * Vector(normal);
}

inline bool can_refract(Direction const &incident, Direction const &normal, float eta)
{
  float cos_theta = dot(Vector(-incident), normal);
  float discriminant = 1.0f - eta * eta * (1.0f - cos_theta * cos_theta);
  return discriminant > 0;
}


inline Vector refract(Direction const &incident, Direction const &normal, float eta)
{
  assert(can_refract(incident, normal, eta) && "Ray cannot be refracted.");

  float cos_theta = dot(-incident, normal);
  Vector horizontal = (Vector(incident) + normal * cos_theta) * eta;
  Vector vertical = normal * std::sqrt(1 - dot(horizontal, horizontal));
  return (horizontal - vertical);
}

} // namespace geometry

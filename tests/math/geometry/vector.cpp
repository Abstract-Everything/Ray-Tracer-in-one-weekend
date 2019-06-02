#include <catch2/catch.hpp>
#include "vector.hpp"

TEST_CASE("vector constructor and arithmetic operations", "[math][vector]")
{
  float scalar = GENERATE(take(1, random(-1.0f, 1.0f)));
  float x = GENERATE(take(1, random(-1.0f, 1.0f)));
  float y = GENERATE(take(1, random(-1.0f, 1.0f)));
  float z = GENERATE(take(1, random(-1.0f, 1.0f)));

  float u = GENERATE(take(1, random(-1.0f, 1.0f)));
  float v = GENERATE(take(1, random(-1.0f, 1.0f)));
  float w = GENERATE(take(1, random(-1.0f, 1.0f)));

  geo::Vector vector(x, y, z);
  geo::Vector vector_second(u, v, w);

  SECTION("vector empty constructor should initalize components as zero")
  {
    geo::Vector vector_zero;
    REQUIRE(vector_zero.x == 0);
    REQUIRE(vector_zero.y == 0);
    REQUIRE(vector_zero.z == 0);
  }

  SECTION("vector empty constructor should initalize with given components")
  {
    REQUIRE(vector.x == x);
    REQUIRE(vector.y == y);
    REQUIRE(vector.z == z);
  }

  SECTION("addition of vector and a scalar")
  {
    geo::Vector result = vector + scalar;
    REQUIRE(result.x == x + scalar);
    REQUIRE(result.y == y + scalar);
    REQUIRE(result.z == z + scalar);
  }

  SECTION("addition of scalar and a vector")
  {
    geo::Vector result = scalar + vector;
    REQUIRE(result.x == x + scalar);
    REQUIRE(result.y == y + scalar);
    REQUIRE(result.z == z + scalar);
  }

  SECTION("subraction of a scalar from a vector")
  {
    geo::Vector result = vector - scalar;
    REQUIRE(result.x == x - scalar);
    REQUIRE(result.y == y - scalar);
    REQUIRE(result.z == z - scalar);
  }

  SECTION("multiplication of a vector with a scalar")
  {
    geo::Vector result = vector * scalar;
    REQUIRE(result.x == x * scalar);
    REQUIRE(result.y == y * scalar);
    REQUIRE(result.z == z * scalar);
  }

  SECTION("multiplication of a scalar with a vector")
  {
    geo::Vector result = scalar * vector;
    REQUIRE(result.x == x * scalar);
    REQUIRE(result.y == y * scalar);
    REQUIRE(result.z == z * scalar);
  }

  SECTION("dividing a scalar from a vector")
  {
    geo::Vector result = vector / scalar;
    REQUIRE(result.x == x / scalar);
    REQUIRE(result.y == y / scalar);
    REQUIRE(result.z == z / scalar);
  }

  SECTION("addition of two vectors")
  {
    geo::Vector result = vector + vector_second;
    REQUIRE(result.x == x + u);
    REQUIRE(result.y == y + v);
    REQUIRE(result.z == z + w);
  }

  SECTION("unary negative of a vector")
  {
    geo::Vector result = -vector;
    REQUIRE(result.x == -x);
    REQUIRE(result.y == -y);
    REQUIRE(result.z == -z);
  }

  SECTION("subtraction of two vectors")
  {
    geo::Vector result = vector - vector_second;
    REQUIRE(result.x == x - u);
    REQUIRE(result.y == y - v);
    REQUIRE(result.z == z - w);
  }

  SECTION("dot product of two vectors")
  {
    float result = dot(vector, vector_second);
    REQUIRE(result == x * u + y * v + z * w);
  }

  SECTION("length_squared of a vector")
  {
    float result = length_squared(vector);
    REQUIRE(result == x * x + y * y + z * z);
  }

  SECTION("length of a vector")
  {
    float result = length(vector);
    REQUIRE(result == std::sqrt(x * x + y * y + z * z));
  }

  SECTION("normalization of a vector")
  {
    geo::Vector result = geo::Vector(normalize(vector));
    REQUIRE(length(result) - 1.0f <= std::numeric_limits<float>::epsilon());
  }
}

#include <catch2/catch.hpp>
#include "vector.hpp"
#include "direction.hpp"

TEST_CASE("direction constructor and operations", "[math][direction]")
{
  const float epsilon = std::numeric_limits<float>::epsilon();

  float x = GENERATE(take(1, random(-1.0f, 1.0f)));
  float y = GENERATE(take(1, random(-1.0f, 1.0f)));
  float z = GENERATE(take(1, random(-1.0f, 1.0f)));
  geo::Vector vector(x, y, z);

  SECTION("implicit cast from vector_3 to direction_3")
  {
    geo::Direction direction = vector;
    float distance = length(geo::Vector(direction));
    REQUIRE(distance - 1.0f <= epsilon);
  }

  // TODO: Check for compile errors to make sure that operators are in face deleted
  // https://stackoverflow.com/questions/49079196/sfinae-to-assert-that-code-does-not-compile/49079614#49079614
}

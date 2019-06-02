cmake_minimum_required (VERSION 3.10)
project (Ray_Tracer VERSION 0.0.1
                    DESCRIPTION "An implementation of Ray tracer in one weekend by Peter Shirley"
                    LANGUAGES CXX)
include (CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include ("${CMAKE_SOURCE_DIR}/cmake/clang_tidy.cmake")

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to release")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
    STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

if(MSVC)
  add_compile_options("/W4" "$<$<CONFIG:RELEASE>:/O2>")
else()
  add_compile_options("-Wall" "-Wextra" "-Werror" "$<$<CONFIG:RELEASE>:-O3>")
endif()

add_subdirectory(source)

if (BUILD_TESTING)
  enable_testing()
  include ("${CMAKE_SOURCE_DIR}/cmake/catch.cmake")
  add_subdirectory(tests)
endif()

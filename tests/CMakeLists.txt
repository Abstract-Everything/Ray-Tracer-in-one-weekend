add_catch_test(Vector_Tests
  SRC "${CMAKE_CURRENT_LIST_DIR}/math/geometry/vector"
  INC "${CMAKE_SOURCE_DIR}/source/math/geometry")

add_catch_test(Direction_Tests
  SRC "${CMAKE_CURRENT_LIST_DIR}/math/geometry/direction"
  INC "${CMAKE_SOURCE_DIR}/source/math/geometry")

add_catch_test(Point_Tests
  SRC "${CMAKE_CURRENT_LIST_DIR}/math/geometry/point"
  INC "${CMAKE_SOURCE_DIR}/source/math/geometry")

add_catch_test(PPM_Tests
  SRC "${CMAKE_CURRENT_LIST_DIR}/image_utils/ppm"
      "${CMAKE_SOURCE_DIR}/source/image_utils/frame"
      "${CMAKE_SOURCE_DIR}/source/image_utils/ppm"

  INC "${CMAKE_SOURCE_DIR}/source/image_utils")

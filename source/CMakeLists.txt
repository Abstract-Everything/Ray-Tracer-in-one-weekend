add_executable(Ray_Tracer 
  "${CMAKE_CURRENT_LIST_DIR}/main"
  "${CMAKE_CURRENT_LIST_DIR}/random"

  "${CMAKE_CURRENT_LIST_DIR}/scene/scene"
  "${CMAKE_CURRENT_LIST_DIR}/scene/camera"
  "${CMAKE_CURRENT_LIST_DIR}/scene/pinhole"
  "${CMAKE_CURRENT_LIST_DIR}/scene/lens"

  "${CMAKE_CURRENT_LIST_DIR}/scene/sphere"

  "${CMAKE_CURRENT_LIST_DIR}/scene/lambertian"
  "${CMAKE_CURRENT_LIST_DIR}/scene/metal"
  "${CMAKE_CURRENT_LIST_DIR}/scene/dielectric"

  "${CMAKE_CURRENT_LIST_DIR}/image_utils/frame"
  "${CMAKE_CURRENT_LIST_DIR}/image_utils/ppm"
)

target_include_directories(Ray_Tracer PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/"
  "${CMAKE_CURRENT_LIST_DIR}/scene"
  "${CMAKE_CURRENT_LIST_DIR}/math/"
  "${CMAKE_CURRENT_LIST_DIR}/math/geometry"
  "${CMAKE_CURRENT_LIST_DIR}/image_utils/"
)

target_compile_features(Ray_Tracer PRIVATE cxx_std_17)
set_target_properties(Ray_Tracer
  PROPERTIES CXX_EXTENSIONS OFF
             CXX_STANDARD_REQUIRED ON
             RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(CLANG_TIDY)
  set_target_properties(Ray_Tracer
    PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY}")
endif()

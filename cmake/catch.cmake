set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch2)
add_library(Catch2::Catch IMPORTED INTERFACE)
set_property(TARGET Catch2::Catch
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")

function(add_catch_test TEST_NAME)
  cmake_parse_arguments(PARSED_ARGS "" "" "SRC;INC" ${ARGN})
  
  add_executable(${TEST_NAME}
    "${CMAKE_SOURCE_DIR}/tests/main" ${PARSED_ARGS_SRC})
  target_include_directories(${TEST_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/extern" ${PARSED_ARGS_INC})

  target_compile_features(${TEST_NAME} PRIVATE cxx_std_17)
  target_link_libraries(${TEST_NAME} Catch2::Catch)
  set_target_properties(${TEST_NAME} PROPERTIES FOLDER tests)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction(add_catch_test)

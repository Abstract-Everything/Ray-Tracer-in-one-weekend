find_program(
  CLANG_TIDY_PATH
  NAMES "clang-tidy"
  DOC "Path to clang-tidy executable")

if (CLANG_TIDY_PATH)
  message(STATUS "Found clang-tidy")
  set(CLANG_TIDY "${CLANG_TIDY_PATH}"
    "-checks= *,-fuchsia-default-arguments")
else()
  message(STATUS "clang-tidy not found.")
endif()


cmake_minimum_required (VERSION 3.9.1)
project (justDoIt)
message("Using CMake version ${CMAKE_VERSION}")

# The version number.
set (justDoIt_VERSION_MAJOR 1)
set (justDoIt_VERSION_MINOR 0)


# should we use our own math functions?
option (USE_MYMATH
    "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# add the binary tree to the search path for include files
# so that we will find config.h
include_directories("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable(justDoIt src/main.cpp)
target_link_libraries (justDoIt  ${EXTRA_LIBS})

message("Processing CMakeLists.txt")

# Testing
enable_testing()
add_test(No_arguments justDoIt )
add_test(Zero justDoIt 0)
add_test(One justDoIt 1)
add_test(Square_No justDoIt 36)
add_test(Non_square_No justDoIt 37)
add_test(Large_number justDoIt 99999999999999999)

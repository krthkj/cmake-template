cmake_minimum_required (VERSION 2.6)
project (justDoIt)

# The version number.
set (justDoIt_VERSION_MAJOR 1)
set (justDoIt_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# add the binary tree to the search path for include files
# so that we will find config.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(justDoIt src/main.cpp)

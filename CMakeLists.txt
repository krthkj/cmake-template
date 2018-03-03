cmake_minimum_required (VERSION 3.5)
project (justDoIt)

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
include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory (MathFunctions)

# add the executable
add_executable(justDoIt src/main.cpp)
target_link_libraries (justDoIt  MathFunctions )
# target_link_libraries (justDoIt  ${EXTRA_LIBS})

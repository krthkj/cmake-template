cmake_minimum_required (VERSION 3.9.1)
project (justDoIt)
message("Using CMake version ${CMAKE_VERSION}")
include(CTest)

# The version number.
set (justDoIt_VERSION_MAJOR 1)
set (justDoIt_VERSION_MINOR 0)

# does this system provide the log and exp functions?
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)
check_function_exists( printf HAVE_PRINTF )
check_function_exists( memset HAVE_MEMSET )

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

# add the install targets
install (TARGETS justDoIt DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)

## TESTING
# does the usage message work?
add_test (ItRunsUsage justDoIt)
set_tests_properties (ItRunsUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")


#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (itRunsComp${arg} justDoIt ${arg})
  set_tests_properties (itRunsComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)

# do a bunch of result based tests
do_test (0 "0 is 0")
do_test (1 "1 is 1")
do_test (2 "2 is 1.41421")
do_test (3 "3 is 1.73205")
do_test (4 "4 is 2")
do_test (9 "9 is 3")
do_test (5 "5 is 2.236")
do_test (7 "7 is 2.645")
do_test (25 "25 is 5")
do_test (-25 "-25 is -nan")
do_test (0.0001 "0.0001 is 0.01")

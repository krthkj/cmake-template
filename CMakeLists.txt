cmake_minimum_required (VERSION 3.9.1)
project (justDoIt)
message("Using CMake version ${CMAKE_VERSION}")
include(CTest)
set (CTEST_PROJECT_NAME "justDoIt")

# The version number.
set (justDoIt_VERSION_MAJOR 1)
set (justDoIt_VERSION_MINOR 0)

# does this system provide the log and exp functions?
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
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
add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries (${PROJECT_NAME} stdc++fs)
target_link_libraries (${PROJECT_NAME} ${EXTRA_LIBS})

message("Processing CMakeLists.txt")

# add the install targets
install (TARGETS ${PROJECT_NAME} DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)

## TESTING
# does the usage message work?
add_test (ItRunsUsage ${PROJECT_NAME})
set_tests_properties (ItRunsUsage
    PROPERTIES
    PASS_REGULAR_EXPRESSION "Usage:.*number")


#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (itRunsComp${arg} ${PROJECT_NAME} ${arg})
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


# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set (CPACK_PACKAGE_VERSION_MAJOR "${justDoIt_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${justDoIt_VERSION_MINOR}")
include (CPack)

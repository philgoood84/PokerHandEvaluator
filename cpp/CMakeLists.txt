cmake_minimum_required(VERSION 2.8.2)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Use C++ 11 Standard to compile
set(CMAKE_CXX_STANDARD 11)

# Now simply link against gtest or gtest_main as needed. Eg
include_directories(include)
add_library(pheval SHARED
  src/dptables.c
  src/evaluator5.c
  src/evaluator6.c
  src/evaluator7.c
  src/evaluator8.c
  src/evaluator9.c
  src/hash.c
  src/hashtable.c
  src/hashtable5.c
  src/hashtable6.c
  src/hashtable7.c
  src/hashtable8.c
  src/hashtable9.c
)
target_compile_options(pheval PUBLIC -Ofast)
add_executable(unit_tests
  test/unit_tests.cc
  test/kev/fast_eval.c
  test/kev/kev_eval.c
)
target_compile_options(unit_tests PUBLIC -Ofast)
target_link_libraries(unit_tests gtest_main pheval)
add_test(NAME unit_tests COMMAND unit_tests)

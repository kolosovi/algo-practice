cmake_minimum_required(VERSION 3.10)

project(algo-practice)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/bf66935e07825318ae519675d73d0f3e313b3ec6.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

# How to automate:
# for each directory problems/<problem set>/<problem name>/cpp:
#   for each *.cpp file which is not *_test.cpp:
#     add library
#   for each *_test.cpp file:
#     add executable
#     link it with gtest_main and every library from the previous step
#     call gtest_discover_tests
# For now I do the same manually.

add_executable(
  myself-implement-unique-ptr-test
  problems/myself/implement-unique-ptr/cpp/unique_ptr_test.cpp
)
target_link_libraries(
  myself-implement-unique-ptr-test
  gtest_main
)

add_executable(
  myself-implement-shared-ptr-test
  problems/myself/implement-shared-ptr/cpp/shared_ptr_test.cpp
)
target_link_libraries(
  myself-implement-shared-ptr-test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(myself-implement-unique-ptr-test)
gtest_discover_tests(myself-implement-shared-ptr-test)

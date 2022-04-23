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

add_executable(
  myself-implement-unique-ptr-test
  problems/myself/implement-unique-ptr/cpp/unique_ptr_test.cpp
)
target_link_libraries(
  myself-implement-unique-ptr-test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(myself-implement-unique-ptr-test)

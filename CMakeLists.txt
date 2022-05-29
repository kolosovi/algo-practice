cmake_minimum_required(VERSION 3.10)

project(algo-practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=undefined")

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

add_library(
  myself-implement-spinlock-spinlock-lib
  STATIC
  problems/myself/implement-spinlock/cpp/spinlock.cpp
)
add_executable(
  myself-implement-spinlock-test
  problems/myself/implement-spinlock/cpp/spinlock_test.cpp
)
target_link_libraries(
  myself-implement-spinlock-test
  myself-implement-spinlock-spinlock-lib
  gtest_main
)

add_executable(
  leetcode-minimum-area-rectangle-test
  problems/leetcode/minimum-area-rectangle/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-minimum-area-rectangle-test
  gtest_main
)

add_executable(
  myself-bounding-box-test
  problems/myself/bounding-box/cpp/solution_test.cpp
)
target_link_libraries(
  myself-bounding-box-test
  gtest_main
)

add_executable(
  myself-bounding-box-generate-permutation-tests
  problems/myself/bounding-box/cpp/generate_permutation_tests.cpp
)

add_executable(
  leetcode-lru-cache-test
  problems/leetcode/lru-cache/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-lru-cache-test
  gtest_main
)

add_executable(
  leetcode-most-stones-removed-with-same-row-or-column-test
  problems/leetcode/most-stones-removed-with-same-row-or-column/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-most-stones-removed-with-same-row-or-column-test
  gtest_main
)

add_executable(
  leetcode-evaluate-division-test
  problems/leetcode/evaluate-division/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-evaluate-division-test
  gtest_main
)

add_executable(
  leetcode-gas-station-test
  problems/leetcode/gas-station/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-gas-station-test
  gtest_main
)

add_executable(
  leetcode-missing-ranges-test
  problems/leetcode/missing-ranges/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-missing-ranges-test
  gtest_main
)

add_executable(
  leetcode-plus-one-test
  problems/leetcode/plus-one/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-plus-one-test
  gtest_main
)

add_executable(
  leetcode-kth-largest-element-in-an-array-test
  problems/leetcode/kth-largest-element-in-an-array/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-kth-largest-element-in-an-array-test
  gtest_main
)

add_executable(
  leetcode-insert-delete-getrandom-o1-test
  problems/leetcode/insert-delete-getrandom-o1/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-insert-delete-getrandom-o1-test
  gtest_main
)

add_executable(
  leetcode-minimum-cost-to-hire-k-workers-test
  problems/leetcode/minimum-cost-to-hire-k-workers/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-minimum-cost-to-hire-k-workers-test
  gtest_main
)

add_executable(
  leetcode-maximum-product-of-word-lengths
  problems/leetcode/maximum-product-of-word-lengths/cpp/solution_test.cpp
)
target_link_libraries(
  leetcode-maximum-product-of-word-lengths
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(myself-implement-unique-ptr-test)
gtest_discover_tests(myself-implement-shared-ptr-test)

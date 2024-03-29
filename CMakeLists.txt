cmake_minimum_required(VERSION 3.10)

project(algo-practice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=undefined -fsanitize=address -march=native -O2")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/bf66935e07825318ae519675d73d0f3e313b3ec6.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

include_directories(lib/include)

add_library(testutil STATIC lib/src/testutil/file.cpp)

add_executable(gen-cses-main "${CMAKE_SOURCE_DIR}/lib/src/gen_cses_main.cpp")

add_executable(kebab "${CMAKE_SOURCE_DIR}/lib/src/kebab.cpp")

set(problems_root "${CMAKE_SOURCE_DIR}/problems/")
file(GLOB problem_dirs ${problems_root}*/*/cpp)
foreach(a_problem_dir ${problem_dirs})
    file(GLOB cpp_files ${a_problem_dir}/*.cpp)
    set(library_targets "")
    foreach(a_library_file ${cpp_files})
        if(${a_library_file} MATCHES "_test.cpp$")
            continue()
        endif()
        if(${a_library_file} MATCHES "main.cpp$")
            continue()
        endif()
        if(${a_library_file} MATCHES "/solution.cpp$")
            continue()
        endif()
        set(library_target ${a_library_file})
        string(REPLACE "${problems_root}" "" library_target "${library_target}")
        string(REPLACE "/cpp/" "-" library_target "${library_target}")
        string(REPLACE ".cpp" "-lib" library_target "${library_target}")
        string(REPLACE "/" "-" library_target "${library_target}")
        string(REPLACE "_" "-" library_target "${library_target}")
        add_library(${library_target} STATIC ${a_library_file})
        list(APPEND library_targets ${library_target})
    endforeach(a_library_file ${cpp_files})
    foreach(a_test_file ${cpp_files})
        if(NOT ${a_test_file} MATCHES "_test.cpp$")
            continue()
        endif()
        set(test_target ${a_test_file})
        string(REPLACE "${problems_root}" "" test_target "${test_target}")
        string(REPLACE "/cpp/" "-" test_target "${test_target}")
        string(REPLACE ".cpp" "" test_target "${test_target}")
        string(REPLACE "/" "-" test_target "${test_target}")
        string(REPLACE "_" "-" test_target "${test_target}")
        add_executable(${test_target} ${a_test_file})
        target_link_libraries(${test_target} testutil gmock gmock_main)
        foreach(a_library_target ${library_targets})
            target_link_libraries(${test_target} ${a_library_target})
        endforeach(a_library_target ${library_targets})
        gtest_discover_tests(${test_target})
        # For judges that use stdin to pass inputs also generate main file
        # XXX: this assumes that solution is contained in a "solution.hpp" file
        # which is not enforced anywhere.
        if(${a_test_file} MATCHES "/laaks/.*/cpp"
                OR ${a_test_file} MATCHES "/snippets/.*/cpp"
                OR ${a_test_file} MATCHES "/cppzerocostconf23/.*/cpp")
            add_custom_command(
              OUTPUT ${a_problem_dir}/main.cpp
              DEPENDS ${test_target} gen-cses-main
              COMMAND ${CMAKE_BINARY_DIR}/gen-cses-main ${a_problem_dir}/solution.hpp > ${a_problem_dir}/main.cpp
            )
            add_executable(${test_target}-cses-main ${a_problem_dir}/main.cpp)
        endif()
    endforeach(a_test_file ${cpp_files})
endforeach(a_problem_dir ${problem_dirs})

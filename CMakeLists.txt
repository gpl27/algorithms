cmake_minimum_required(VERSION 3.12)
project(Algorithms C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -DDEBUG")

# Add the source files
set(SOURCE_FILES
    src/sort.c
)

# Add the test files
set(TEST_FILES
    tests/run_tests.c
    tests/test.c
    tests/sort.test.c
)

# Create the executable for the tests
add_executable(run_tests ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(run_tests m)

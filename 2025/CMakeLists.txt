cmake_minimum_required(VERSION 3.16)
project(aoc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SRC_FILES src/*.cpp)

add_executable(run_day ${SRC_FILES})

target_compile_options(run_day PRIVATE
    -Wall -Wextra -Wpedantic
)

target_compile_definitions(run_day PRIVATE
    AOC_INPUT_DIR="${CMAKE_SOURCE_DIR}/input"
)


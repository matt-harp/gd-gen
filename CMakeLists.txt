cmake_minimum_required(VERSION 3.20)
project(gd-gen)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(generator ${SOURCES})

if(MSVC)
    target_compile_options(generator PRIVATE /std:c++20)
else()
    target_compile_options(generator PRIVATE -std=c++20)
endif()

set_target_properties(generator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
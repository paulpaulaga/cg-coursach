cmake_minimum_required(VERSION 3.17)
project(test_code)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wpedantic")

file(GLOB sources "*.h"
                "*.cpp")

add_executable(test_code ${sources})
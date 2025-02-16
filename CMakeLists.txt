cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL_LEVEL)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory(CalculatorCore)
add_subdirectory(Calculator)
add_subdirectory(CalculatorTests)
cmake_minimum_required(VERSION 3.10)
project(CalculatorTests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL_LEVEL)

add_executable(${PROJECT_NAME}
	CalculatorTest.cpp
)
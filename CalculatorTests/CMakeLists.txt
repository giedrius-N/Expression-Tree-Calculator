cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0135 NEW)
project(CalculatorTests)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL_LEVEL)

set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/gtest)
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
)
# Ensures gtest uses the same shared runtime library as the project
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}
	CalculatorTest.cpp
    Tests/BasicOperationsTest.cpp
    Tests/UnaryOperationsTest.cpp
    Tests/VariableSubstitutionTest.cpp
    Tests/InvalidExpressionsTest.cpp
    Tests/ComplexExpressionsTest.cpp
    Tests/CalculatorTestFixture.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    gtest_main
    CalculatorCore
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

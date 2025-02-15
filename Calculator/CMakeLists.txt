cmake_minimum_required(VERSION 3.10)
project(CalculatorCore)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL_LEVEL)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/Calculator.cpp
	include/Calculator.h
	src/Tokenizer.cpp
	include/Tokenizer.h
	src/Token.cpp
	include/Token.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/Calculator/include
)

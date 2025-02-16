cmake_minimum_required(VERSION 3.10)
project(CalculatorCore)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL_LEVEL)

add_definitions( -DCALCULATORCORE_EXPORT )

add_library(${PROJECT_NAME} SHARED
	# Core
	include/CalculatorCoreAPI.h
	src/Calculator.cpp
	include/Calculator.h
	include/Types.h
	# Tokenizer
	src/Tokenizer.cpp
	include/Tokenizer.h
	src/Token.cpp
	include/Token.h
	# Nodes
	include/Node.h
	src/NumberNode.cpp
	include/NumberNode.h
	src/OperatorNode.cpp
	include/OperatorNode.h
	# Parsing
	src/ExpressionParser.cpp
	include/ExpressionParser.h
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/CalculatorCore/include
)

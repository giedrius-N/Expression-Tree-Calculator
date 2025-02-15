cmake_minimum_required(VERSION 3.10)
project(CalculatorCore)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_PARALLEL_LEVEL)

add_executable(${PROJECT_NAME}
	# Core
	src/main.cpp
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

target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/Calculator/include
)

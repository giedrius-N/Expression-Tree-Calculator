
# Simple Expression Tree Calculator in C++

A lightweight C++ command-line calculator that evaluates mathematical expressions using an expression tree.

---

## Project Structure

* **Calculator** – Executable code for running the Calculator application, which uses the `CalculatorCore` library for its functionality.
* **CalculatorCore** – A shared library that implements all the core functionality of the calculator.
* **CalculatorTests** – Creates a testing executable with 50+ unique tests.

```
│   .gitignore
│   CMakeLists.txt
│   README.md
│
├───Calculator
│       CMakeLists.txt
│       main.cpp
│
├───CalculatorCore
│   │   CMakeLists.txt
│   │
│   ├───include              # Header files
│   │       Calculator.h
│   │       CalculatorCoreAPI.h
│   │       ExpressionParser.h
│   │       Node.h
│   │       NumberNode.h
│   │       OperatorNode.h
│   │       Token.h
│   │       Tokenizer.h
│   │       Types.h
│   │
│   └───src                  # Source files
│           Calculator.cpp
│           ExpressionParser.cpp
│           NumberNode.cpp
│           OperatorNode.cpp
│           Tokenizer.cpp
│
└───CalculatorTests          # Unit tests using Google Test
    │   CMakeLists.txt
    │   CalculatorTest.cpp
    │
    └───Tests
            BasicOperationsTest.cpp
            CalculatorTestFixture.h
            ComplexExpressionsTest.cpp
            InvalidExpressionsTest.cpp
            UnaryOperationsTest.cpp
            VariableSubstitutionTest.cpp

```

---

## Features Implemented

- **Expression Tree:** Constructs a tree-based structure for mathematical expressions.
- **Template Support:** Supports `double`, `float`, and `int` types via C++ templates.
- **C++11/14 Features:** Utilizes `constexpr` for compile-time constants, `auto` for type deduction, and `std::make_unique` for memory management.
- **Error Handling:** Throws exceptions for invalid expressions and division by zero.
- **Unit Tests:** Implemented with Google Test to verify correctness.

---

## Build Instructions

### Prerequisites

- **C++ Compiler** supporting C++11/14 (e.g., GCC, Clang, or MSVC)
- **CMake** version 3.10 or newer

### Steps

```bash
# Go to the source directory
cd Expression-Tree-Calculator

# Create a build directory
mkdir build && cd build

# Configure the project with CMake
cmake ..

# Build the project
cmake --build .

# Run the Calculator
./Debug/Calculator
```

---

## Usage

When running `Calculator.exe`, you can enter any mathematical expression, and the application will evaluate it. If your expression contains variables, the application will prompt **you to enter their values** before calculating the result.

### Examples:

- Expression with a variable:
  ```
  Enter a mathematical expression: 5+3+15+x*10
  Please enter a value for variable 'x': 5
  The result: 73
  ```

- Arithmetic operations:
  ```
  Enter a mathematical expression: 15*20/4+5400*0.02
  The result: 183
  ```

- Addition with decimal values:
  ```
  Enter a mathematical expression: 0.05 + 0.07
  The result: 0.12
  ```

## Running Tests

The tests are written using Google Test. They can be found in the `CalculatorTests` directory.

To run the tests, navigate to the Debug directory after building the project and execute:

```bash
./CalculatorTests
```
---

## Future Enhancements

- Add symbolic manipulation support.
- Improve code coverage with additional unit tests.
- Make CalculatorCore a purely templated library.
- Implement more C++11/14 features such as `lambda expressions` and `std::optional`.



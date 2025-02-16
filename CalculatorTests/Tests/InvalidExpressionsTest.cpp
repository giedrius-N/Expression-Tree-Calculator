#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, MissingOperand)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("2+"), std::runtime_error);
}

TEST(CalculatorTest, ConsecutiveOperators)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("2++2"), std::runtime_error);
}

TEST(CalculatorTest, InvalidCharacters)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("2&2"), std::runtime_error);
}

TEST(CalculatorTest, EmptyExpression)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate(""), std::runtime_error);
}

TEST(CalculatorTest, OnlyOperator)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("+"), std::runtime_error);
}

TEST(CalculatorTest, PowerOperation)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("2^3"), std::runtime_error);
}

TEST(CalculatorTest, GarbageWhitespace)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("   \t\n "), std::runtime_error);
}

TEST(CalculatorTest, RandomSymbols)
{
    Calculator calc;
    EXPECT_THROW(calc.Evaluate("@#$%"), std::runtime_error);
}

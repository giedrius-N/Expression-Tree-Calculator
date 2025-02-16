#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, MissingOperand)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("2+"), std::runtime_error);
}

TEST(CalculatorTest, ConsecutiveOperators)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("2++2"), std::runtime_error);
}

TEST(CalculatorTest, InvalidCharacters)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("2&2"), std::runtime_error);
}

TEST(CalculatorTest, EmptyExpression)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate(""), std::runtime_error);
}

TEST(CalculatorTest, OnlyOperator)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("+"), std::runtime_error);
}

TEST(CalculatorTest, PowerOperation)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("2^3"), std::runtime_error);
}

TEST(CalculatorTest, GarbageWhitespace)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("   \t\n "), std::runtime_error);
}

TEST(CalculatorTest, RandomSymbols)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("@#$%"), std::runtime_error);
}

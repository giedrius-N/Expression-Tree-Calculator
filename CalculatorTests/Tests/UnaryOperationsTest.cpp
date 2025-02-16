#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, UnaryMinusWithAddition)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("3 + -2"), 1.0);
}

TEST(CalculatorTest, UnaryMinusComplex)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("-(3+2)"), -5.0);
}

TEST(CalculatorTest, UnaryMinusSingleNumber)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("-7"), -7.0);
}

TEST(CalculatorTest, UnaryMinusZero)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("-0"), 0.0);
}

TEST(CalculatorTest, MultipleUnaryMinus)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("--5"), 5.0);
    EXPECT_DOUBLE_EQ(calc.Evaluate("---5"), -5.0);
}

TEST(CalculatorTest, UnaryMinusWithParentheses)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("-(3 + 2)"), -5.0);
    EXPECT_DOUBLE_EQ(calc.Evaluate("-(4 * (2 + 1))"), -12.0);
}

TEST(CalculatorTest, UnaryMinusInComplexExpression)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("5 + -3 * 2"), -1.0);
    EXPECT_DOUBLE_EQ(calc.Evaluate("10 - -(3 + 2)"), 15.0);
}

TEST(CalculatorTest, UnaryMinusWithFractions)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("-0.5"), -0.5);
    EXPECT_DOUBLE_EQ(calc.Evaluate("-0.3333 + 1"), 0.6667);
}

TEST(CalculatorTest, UnaryMinusWithWhitespace)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate(" - 4"), -4.0);
    EXPECT_DOUBLE_EQ(calc.Evaluate("3  +  -   2"), 1.0);
}

TEST(CalculatorTest, UnaryMinusWithoutOperand)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("-"), std::runtime_error);
}

TEST(CalculatorTest, UnaryMinusBeforeOperator)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("5+-"), std::runtime_error);
}

TEST(CalculatorTest, UnaryMinusAfterOperatorMissingOperand)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("5 + -"), std::runtime_error);
}

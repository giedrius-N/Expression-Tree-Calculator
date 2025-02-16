#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, BasicAddition)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("3+5"), 8.0);
}

TEST(CalculatorTest, BasicSubtraction)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("10-3"), 7.0);
}

TEST(CalculatorTest, BasicMultiplication)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("4*2"), 8.0);
}

TEST(CalculatorTest, BasicDivision)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("8/4"), 2.0);
}

TEST(CalculatorTest, DivisionByZero)
{
    Calculator<double> calc;
    EXPECT_THROW(calc.Evaluate("5/0"), std::runtime_error);
}

TEST(CalculatorTest, WhiteSpaces)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate(" 2 +  3 * 4 "), 14.0);
}

TEST(CalculatorTest, BasicMixedOperations)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("2+3*4-1"), 13.0);
}

TEST(CalculatorTest, BasicParentheses)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("(2+3)*4"), 20.0);
}
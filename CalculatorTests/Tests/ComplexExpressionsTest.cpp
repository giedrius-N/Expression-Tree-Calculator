#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, ComplexParentheses)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("(2+3)*(4-2)"), 10.0);
}

TEST(CalculatorTest, NestedParentheses)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("((3+2)*(4-1))/5"), 3.0);
}

TEST(CalculatorTest, MultipleOperations)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("2+3*4-5/5"), 13.0);
}

TEST(CalculatorTest, LargeNumbers)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("1000000+1000000"), 2000000.0);
}

TEST(CalculatorTest, SmallNumbers)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("0.0001+0.0002"), 0.0003);
}

TEST(CalculatorTest, VeryLargeDivision)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("1000000/1"), 1000000.0);
}

TEST(CalculatorTest, RepeatedParentheses)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("((((3+2))))"), 5.0);
}

TEST(CalculatorTest, DecimalMultiplication)
{
    Calculator<double> calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("2.5*4.0"), 10.0);
}
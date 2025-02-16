#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, ComplexParentheses)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("(2+3)*(4-2)"), 10.0);
}

TEST(CalculatorTest, NestedParentheses)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("((3+2)*(4-1))/5"), 3.0);
}

TEST(CalculatorTest, MultipleOperations)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("2+3*4-5/5"), 13.0);
}

TEST(CalculatorTest, LargeNumbers)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("1000000+1000000"), 2000000.0);
}

TEST(CalculatorTest, SmallNumbers)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("0.0001+0.0002"), 0.0003);
}

TEST(CalculatorTest, VeryLargeDivision)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("1000000/1"), 1000000.0);
}

TEST(CalculatorTest, RepeatedParentheses)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("((((3+2))))"), 5.0);
}

TEST(CalculatorTest, DecimalMultiplication)
{
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.Evaluate("2.5*4.0"), 10.0);
}
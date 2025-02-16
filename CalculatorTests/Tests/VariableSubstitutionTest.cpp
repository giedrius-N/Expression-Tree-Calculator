#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, VariableWithUnaryMinus)
{
    Calculator calc;
    VariableMap vars = { {"x", 5.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("-x", vars), -5.0);
}

TEST(CalculatorTest, MultipleVariablesMixedOperations)
{
    Calculator calc;
    VariableMap vars = { {"x", 4.0}, {"y", 2.0}, {"z", 3.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x*y+z", vars), 11.0);
}

TEST(CalculatorTest, VariablesWithParentheses)
{
    Calculator calc;
    VariableMap vars = { {"a", 8.0}, {"b", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("(a+b)*b", vars), 20.0);
}

TEST(CalculatorTest, RepeatedVariableUse)
{
    Calculator calc;
    VariableMap vars = { {"x", 3.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x*x+x", vars), 12.0);
}

TEST(CalculatorTest, MissingVariable)
{
    Calculator calc;
    VariableMap vars = { {"x", 5.0} };
    EXPECT_THROW(calc.Evaluate("x+y", vars), std::runtime_error);
}

TEST(CalculatorTest, VariableWithDivision)
{
    Calculator calc;
    VariableMap vars = { {"x", 10.0}, {"y", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x/y", vars), 5.0);
}

TEST(CalculatorTest, InvalidVariableName)
{
    Calculator calc;
    VariableMap vars = { {"x1", 5.0}, {"y@", 3.0} };
    EXPECT_THROW(calc.Evaluate("x1+y@", vars), std::runtime_error);
}

TEST(CalculatorTest, SingleCharacterVariable)
{
    Calculator calc;
    VariableMap vars = { {"z", 15.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("z", vars), 15.0);
}

TEST(CalculatorTest, MultiCharacterVariable)
{
    Calculator calc;
    VariableMap vars = { {"x", 6.0}, {"y", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x/y", vars), 3.0);
}

TEST(CalculatorTest, VariableWithWhitespace)
{
    Calculator calc;
    VariableMap vars = { {"x", 9.0}, {"y", 3.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate(" x  +  y ", vars), 12.0);
}

TEST(CalculatorTest, LargeVariableValues)
{
    Calculator calc;
    VariableMap vars = { {"big", 1000000.0}, {"small", 0.0001} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("big*small", vars), 100.0);
}

TEST(CalculatorTest, SameVariableNameMultipleTimes)
{
    Calculator calc;
    VariableMap vars = { {"x", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x+x*x", vars), 6.0);
}

TEST(CalculatorTest, VariableWithNegativeValue)
{
    Calculator calc;
    VariableMap vars = { {"neg", -4.0}, {"pos", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("neg+pos", vars), -2.0);
}

TEST(CalculatorTest, VariableWithZero)
{
    Calculator calc;
    VariableMap vars = { {"x", 0.0}, {"y", 10.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x+y", vars), 10.0);
}

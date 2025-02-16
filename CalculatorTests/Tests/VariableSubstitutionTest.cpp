#include "Calculator.h"
#include <gtest/gtest.h>

TEST(CalculatorTest, VariableWithUnaryMinus)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 5.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("-x", vars), -5.0);
}

TEST(CalculatorTest, MultipleVariablesMixedOperations)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 4.0}, {"y", 2.0}, {"z", 3.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x*y+z", vars), 11.0);
}

TEST(CalculatorTest, VariablesWithParentheses)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"a", 8.0}, {"b", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("(a+b)*b", vars), 20.0);
}

TEST(CalculatorTest, RepeatedVariableUse)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 3.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x*x+x", vars), 12.0);
}

TEST(CalculatorTest, MissingVariable)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 5.0} };
    EXPECT_THROW(calc.Evaluate("x+y", vars), std::runtime_error);
}

TEST(CalculatorTest, VariableWithDivision)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 10.0}, {"y", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x/y", vars), 5.0);
}

TEST(CalculatorTest, InvalidVariableName)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x1", 5.0}, {"y@", 3.0} };
    EXPECT_THROW(calc.Evaluate("x1+y@", vars), std::runtime_error);
}

TEST(CalculatorTest, SingleCharacterVariable)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"z", 15.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("z", vars), 15.0);
}

TEST(CalculatorTest, MultiCharacterVariable)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 6.0}, {"y", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x/y", vars), 3.0);
}

TEST(CalculatorTest, VariableWithWhitespace)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 9.0}, {"y", 3.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate(" x  +  y ", vars), 12.0);
}

TEST(CalculatorTest, LargeVariableValues)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"big", 1000000.0}, {"small", 0.0001} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("big*small", vars), 100.0);
}

TEST(CalculatorTest, SameVariableNameMultipleTimes)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x+x*x", vars), 6.0);
}

TEST(CalculatorTest, VariableWithNegativeValue)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"neg", -4.0}, {"pos", 2.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("neg+pos", vars), -2.0);
}

TEST(CalculatorTest, VariableWithZero)
{
    Calculator<double> calc;
    VariableMap<double> vars = { {"x", 0.0}, {"y", 10.0} };
    EXPECT_DOUBLE_EQ(calc.Evaluate("x+y", vars), 10.0);
}

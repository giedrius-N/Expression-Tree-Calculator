#include "CalculatorTestFixture.h"
#include <gtest/gtest.h>

TYPED_TEST(CalculatorTest, MissingOperand)
{
    EXPECT_THROW(this->calc.Evaluate("2+"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, ConsecutiveOperators)
{
    EXPECT_THROW(this->calc.Evaluate("2++2"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, InvalidCharacters)
{
    EXPECT_THROW(this->calc.Evaluate("2&2"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, EmptyExpression)
{
    EXPECT_THROW(this->calc.Evaluate(""), std::runtime_error);
}

TYPED_TEST(CalculatorTest, OnlyOperator)
{
    EXPECT_THROW(this->calc.Evaluate("+"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, PowerOperation)
{
    EXPECT_THROW(this->calc.Evaluate("2^3"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, GarbageWhitespace)
{
    EXPECT_THROW(this->calc.Evaluate("   \t\n "), std::runtime_error);
}

TYPED_TEST(CalculatorTest, RandomSymbols)
{
    EXPECT_THROW(this->calc.Evaluate("@#$%"), std::runtime_error);
}

#include "CalculatorTestFixture.h"
#include <gtest/gtest.h>

TYPED_TEST(CalculatorTest, UnaryMinusWithAddition)
{
    EXPECT_EQ(this->calc.Evaluate("3 + -2"), static_cast<TypeParam>(1));
}

TYPED_TEST(CalculatorTest, UnaryMinusComplex)
{
    EXPECT_EQ(this->calc.Evaluate("-(3+2)"), static_cast<TypeParam>(-5));
}

TYPED_TEST(CalculatorTest, UnaryMinusSingleNumber)
{
    EXPECT_EQ(this->calc.Evaluate("-7"), static_cast<TypeParam>(-7));
}

TYPED_TEST(CalculatorTest, UnaryMinusZero)
{
    EXPECT_EQ(this->calc.Evaluate("-0"), static_cast<TypeParam>(0));
}

TYPED_TEST(CalculatorTest, MultipleUnaryMinus)
{
    EXPECT_EQ(this->calc.Evaluate("--5"), static_cast<TypeParam>(5));
    EXPECT_EQ(this->calc.Evaluate("---5"), static_cast<TypeParam>(-5));
}

TYPED_TEST(CalculatorTest, UnaryMinusWithParentheses)
{
    EXPECT_EQ(this->calc.Evaluate("-(3 + 2)"), static_cast<TypeParam>(-5));
    EXPECT_EQ(this->calc.Evaluate("-(4 * (2 + 1))"), static_cast<TypeParam>(-12));
}

TYPED_TEST(CalculatorTest, UnaryMinusInComplexExpression)
{
    EXPECT_EQ(this->calc.Evaluate("5 + -3 * 2"), static_cast<TypeParam>(-1));
    EXPECT_EQ(this->calc.Evaluate("10 - -(3 + 2)"), static_cast<TypeParam>(15));
}

TYPED_TEST(CalculatorTest, UnaryMinusWithFractions)
{
    if (std::is_same<TypeParam, int>::value) 
    {
        GTEST_SKIP() << "Skipping test for int type.";
    }
    EXPECT_EQ(this->calc.Evaluate("-0.5"), static_cast<TypeParam>(-0.5));
    EXPECT_NEAR(this->calc.Evaluate("-0.3333 + 1"), static_cast<TypeParam>(0.6667), 0.0001);
}

TYPED_TEST(CalculatorTest, UnaryMinusWithWhitespace)
{
    EXPECT_EQ(this->calc.Evaluate(" - 4"), static_cast<TypeParam>(-4));
    EXPECT_EQ(this->calc.Evaluate("3  +  -   2"), static_cast<TypeParam>(1));
}

TYPED_TEST(CalculatorTest, UnaryMinusWithoutOperand)
{
    EXPECT_THROW(this->calc.Evaluate("-"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, UnaryMinusBeforeOperator)
{
    EXPECT_THROW(this->calc.Evaluate("5+-"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, UnaryMinusAfterOperatorMissingOperand)
{
    EXPECT_THROW(this->calc.Evaluate("5 + -"), std::runtime_error);
}

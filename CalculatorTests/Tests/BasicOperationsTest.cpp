#include "Calculator.h"
#include "CalculatorTestFixture.h"
#include <gtest/gtest.h>

TYPED_TEST(CalculatorTest, BasicAddition)
{
    EXPECT_EQ(this->calc.Evaluate("3+5"), static_cast<TypeParam>(8));
}

TYPED_TEST(CalculatorTest, BasicSubtraction)
{
    EXPECT_EQ(this->calc.Evaluate("10-3"), static_cast<TypeParam>(7));
}

TYPED_TEST(CalculatorTest, BasicMultiplication)
{
    EXPECT_EQ(this->calc.Evaluate("4*2"), static_cast<TypeParam>(8));
}

TYPED_TEST(CalculatorTest, BasicDivision)
{
    EXPECT_EQ(this->calc.Evaluate("8/4"), static_cast<TypeParam>(2));
}

TYPED_TEST(CalculatorTest, DivisionByZero)
{
    EXPECT_THROW(this->calc.Evaluate("5/0"), std::runtime_error);
}

TYPED_TEST(CalculatorTest, WhiteSpaces)
{
    EXPECT_EQ(this->calc.Evaluate(" 2 +  3 * 4 "), static_cast<TypeParam>(14));
}

TYPED_TEST(CalculatorTest, BasicMixedOperations)
{
    EXPECT_EQ(this->calc.Evaluate("2+3*4-1"), static_cast<TypeParam>(13));
}

TYPED_TEST(CalculatorTest, BasicParentheses)
{
    EXPECT_EQ(this->calc.Evaluate("(2+3)*4"), static_cast<TypeParam>(20));
}

#include "CalculatorTestFixture.h"
#include <gtest/gtest.h>

TYPED_TEST(CalculatorTest, ComplexParentheses)
{
    EXPECT_EQ(this->calc.Evaluate("(2+3)*(4-2)"), static_cast<TypeParam>(10));
}

TYPED_TEST(CalculatorTest, NestedParentheses)
{
    EXPECT_EQ(this->calc.Evaluate("((3+2)*(4-1))/5"), static_cast<TypeParam>(3));
}

TYPED_TEST(CalculatorTest, MultipleOperations)
{
    EXPECT_EQ(this->calc.Evaluate("2+3*4-5/5"), static_cast<TypeParam>(13));
}

TYPED_TEST(CalculatorTest, LargeNumbers)
{
    EXPECT_EQ(this->calc.Evaluate("1000000+1000000"), static_cast<TypeParam>(2000000));
}

TYPED_TEST(CalculatorTest, SmallNumbers)
{
    EXPECT_NEAR(this->calc.Evaluate("0.0001+0.0002"), static_cast<TypeParam>(0.0003), 1e-5);
}

TYPED_TEST(CalculatorTest, VeryLargeDivision)
{
    EXPECT_EQ(this->calc.Evaluate("1000000/1"), static_cast<TypeParam>(1000000));
}

TYPED_TEST(CalculatorTest, RepeatedParentheses)
{
    EXPECT_EQ(this->calc.Evaluate("((((3+2))))"), static_cast<TypeParam>(5));
}

TYPED_TEST(CalculatorTest, DecimalMultiplication)
{
    if (std::is_same<TypeParam, int>::value) 
    {
        GTEST_SKIP() << "Skipping test for int type.";
    }
    EXPECT_EQ(this->calc.Evaluate("2.5*4.0"), static_cast<TypeParam>(10));
}

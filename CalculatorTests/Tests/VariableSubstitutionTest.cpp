#include "CalculatorTestFixture.h"
#include <gtest/gtest.h>

TYPED_TEST(CalculatorTest, VariableWithUnaryMinus)
{
    VariableMap<TypeParam> vars = { {"x", static_cast<TypeParam>(5)} };
    EXPECT_EQ(this->calc.Evaluate("-x", vars), static_cast<TypeParam>(-5));
}

TYPED_TEST(CalculatorTest, MultipleVariablesMixedOperations)
{
    VariableMap<TypeParam> vars = { 
        {"x", static_cast<TypeParam>(4)}, 
        {"y", static_cast<TypeParam>(2)}, 
        {"z", static_cast<TypeParam>(3)} 
    };
    EXPECT_EQ(this->calc.Evaluate("x*y+z", vars), static_cast<TypeParam>(11));
}

TYPED_TEST(CalculatorTest, VariablesWithParentheses)
{
    VariableMap<TypeParam> vars = { 
        {"a", static_cast<TypeParam>(8)}, 
        {"b", static_cast<TypeParam>(2)} 
    };
    EXPECT_EQ(this->calc.Evaluate("(a+b)*b", vars), static_cast<TypeParam>(20));
}

TYPED_TEST(CalculatorTest, RepeatedVariableUse)
{
    VariableMap<TypeParam> vars = { {"x", static_cast<TypeParam>(3)} };
    EXPECT_EQ(this->calc.Evaluate("x*x+x", vars), static_cast<TypeParam>(12));
}

TYPED_TEST(CalculatorTest, MissingVariable)
{
    VariableMap<TypeParam> vars = { {"x", static_cast<TypeParam>(5)} };
    EXPECT_THROW(this->calc.Evaluate("x+y", vars), std::runtime_error);
}

TYPED_TEST(CalculatorTest, VariableWithDivision)
{
    VariableMap<TypeParam> vars = { 
        {"x", static_cast<TypeParam>(10)}, 
        {"y", static_cast<TypeParam>(2)} 
    };
    EXPECT_EQ(this->calc.Evaluate("x/y", vars), static_cast<TypeParam>(5));
}

TYPED_TEST(CalculatorTest, InvalidVariableName)
{
    VariableMap<TypeParam> vars = { 
        {"x1", static_cast<TypeParam>(5)}, 
        {"y@", static_cast<TypeParam>(3)} 
    };
    EXPECT_THROW(this->calc.Evaluate("x1+y@", vars), std::runtime_error);
}

TYPED_TEST(CalculatorTest, SingleCharacterVariable)
{
    VariableMap<TypeParam> vars = { {"z", static_cast<TypeParam>(15)} };
    EXPECT_EQ(this->calc.Evaluate("z", vars), static_cast<TypeParam>(15));
}

TYPED_TEST(CalculatorTest, MultiCharacterVariable)
{
    VariableMap<TypeParam> vars = { 
        {"x", static_cast<TypeParam>(6)}, 
        {"y", static_cast<TypeParam>(2)} 
    };
    EXPECT_EQ(this->calc.Evaluate("x/y", vars), static_cast<TypeParam>(3));
}

TYPED_TEST(CalculatorTest, VariableWithWhitespace)
{
    VariableMap<TypeParam> vars = { 
        {"x", static_cast<TypeParam>(9)}, 
        {"y", static_cast<TypeParam>(3)} 
    };
    EXPECT_EQ(this->calc.Evaluate(" x  +  y ", vars), static_cast<TypeParam>(12));
}

TYPED_TEST(CalculatorTest, LargeVariableValues)
{
    if (std::is_same<TypeParam, int>::value) 
    {
        GTEST_SKIP() << "Skipping test for int type.";
    }
    VariableMap<TypeParam> vars = { 
        {"big", static_cast<TypeParam>(1000000)}, 
        {"small", static_cast<TypeParam>(0.0001)} 
    };
    EXPECT_EQ(this->calc.Evaluate("big*small", vars), static_cast<TypeParam>(100));
}

TYPED_TEST(CalculatorTest, SameVariableNameMultipleTimes)
{
    VariableMap<TypeParam> vars = { {"x", static_cast<TypeParam>(2)} };
    EXPECT_EQ(this->calc.Evaluate("x+x*x", vars), static_cast<TypeParam>(6));
}

TYPED_TEST(CalculatorTest, VariableWithNegativeValue)
{
    VariableMap<TypeParam> vars = { 
        {"neg", static_cast<TypeParam>(-4)}, 
        {"pos", static_cast<TypeParam>(2)} 
    };
    EXPECT_EQ(this->calc.Evaluate("neg+pos", vars), static_cast<TypeParam>(-2));
}

TYPED_TEST(CalculatorTest, VariableWithZero)
{
    VariableMap<TypeParam> vars = { 
        {"x", static_cast<TypeParam>(0)}, 
        {"y", static_cast<TypeParam>(10)} 
    };
    EXPECT_EQ(this->calc.Evaluate("x+y", vars), static_cast<TypeParam>(10));
}

TYPED_TEST(CalculatorTest, LetterFollowedByDigit)
{
    VariableMap<TypeParam> vars = { {"x", static_cast<TypeParam>(5)} };
    EXPECT_EQ(this->calc.Evaluate("x20", vars), static_cast<TypeParam>(100));
}

TYPED_TEST(CalculatorTest, DigitFollowedByLetter)
{
    VariableMap<TypeParam> vars = { {"x", static_cast<TypeParam>(3)} };
    EXPECT_EQ(this->calc.Evaluate("20x", vars), static_cast<TypeParam>(60));
}

TYPED_TEST(CalculatorTest, MixedLetterDigitMultiplication)
{
    VariableMap<TypeParam> vars = {
        {"a", static_cast<TypeParam>(2)},
        {"b", static_cast<TypeParam>(3)}
    };
    EXPECT_EQ(this->calc.Evaluate("a10+b20", vars), static_cast<TypeParam>(80));
}

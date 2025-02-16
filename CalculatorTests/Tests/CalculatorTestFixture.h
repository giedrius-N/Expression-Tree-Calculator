#ifndef CALCULATOR_TEST_FIXTURE_H
#define CALCULATOR_TEST_FIXTURE_H
#include "Calculator.h"
#include <gtest/gtest.h>

/// <summary>
/// Numeric types used for typed tests.
/// </summary>
typedef ::testing::Types<int, float, double> NumericTypes;

/// <summary>
/// Test fixture for Calculator with templated types.
/// </summary>
/// <typeparam name="T">Numeric type for the Calculator.</typeparam>
template <typename T>
class CalculatorTest : public ::testing::Test
{
protected:
    Calculator<T> calc;
};

TYPED_TEST_SUITE(CalculatorTest, NumericTypes);

#endif // CALCULATOR_TEST_FIXTURE_H

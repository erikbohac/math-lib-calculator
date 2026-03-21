#include <gtest/gtest.h>
#include <stdexcept>
#include <limits.h>
#include "core/math-lib.h"


TEST(MathLibTest, Addition)
{
	EXPECT_EQ(add(2, 3), 5);
	EXPECT_EQ(add(-1, 0), -1);
	EXPECT_EQ(add(-5, -5), -10);
	EXPECT_EQ(add(LONG_LONG_MAX, LONG_LONG_MIN), 0);
	EXPECT_EQ(add(LONG_LONG_MIN, 1), -9'223'372'036'854'775'806LL);
}

TEST(MathLibTest, AdditionDecimal)
{
	EXPECT_EQ(add(3.42, 1.58), 5);
	EXPECT_EQ(add(3.125453, -3.125453), 0);
	EXPECT_NEAR(add(1675664566455.545434L, 5445675234.65345L), 1681110241690.198884L, 1e-9);
}

TEST(MathLibTest, Subtraction)
{
	EXPECT_EQ(subtract(5, 3), 2);
	EXPECT_EQ(subtract(0, 1), -1);
	EXPECT_EQ(subtract(-1, -2), 1);
	EXPECT_EQ(subtract(LONG_LONG_MAX, LONG_LONG_MAX), 0);
	EXPECT_EQ(subtract(LONG_LONG_MIN, LONG_LONG_MIN), 0);
	EXPECT_EQ(subtract(LONG_LONG_MAX, 1), 9'223'372'036'854'775'806LL);
}

TEST(MathLibTest, SubstractionDecimal)
{
	EXPECT_EQ(subtract(102.37, -36.57), 138.94);
	EXPECT_EQ(subtract(-53453,76, -53452,76), -1);
	EXPECT_NEAR(subtract(652342344745645.65234345234, 65423464554543364.5454534565), -64771122209797718.89311000416, 1e-9);
}

TEST(MathLibTest, Multiplication)
{
}

TEST(MathLibTest, Division)
{
}

TEST(MathLibTest, DivisionByZero)
{
	EXPECT_THROW(divide(13423, 0), std::domain_error);
	EXPECT_THROW(divide(-45345.7435, 0), std::domain_error);
}

TEST(MathLibTest, Factorial)
{
	EXPECT_EQ(factorial(0), 1L);
	EXPECT_EQ(factorail(1), 1L);
	EXPECT_EQ(factorail(5), 120L);
	EXPECT_EQ(factorial(20), 2432902008176640000L);
	EXPECT_THROW(factorial(21), std::overflow_error);
}

TEST(MathLibTest, FactorialNegative)
{
	EXPECT_THROW(factorial(-1), std::domain_error);
	EXPECT_THROW(factorial(-10), std::domain_error);
}

TEST(MathLibTest, Power)
{
}

TEST(MathLibTest, PowerNegative)
{
}

TEST(MathLibTest, PowerDecimal)
{
}

TEST(MathLibTest, Root)
{
}

TEST(MathLibTest, RootNegativeOdd)
{
}

TEST(MathLibTest, RootNegativeEven)
{
}

TEST(MathLibTest, RootDecimal)
{
}

/*
TEST(MathLibTest, ...)
{
}
*/


/**
 * @file mathlib_test.cpp
 * @brief Unit tests for the core math library functions.
 *
 * This file contains a comprehensive suite of unit tests for mathematical
 * operations implemented in core/mathlib.h. It verifies correctness for:
 * - basic arithmetic (addition, subtraction, multiplication, division)
 * - advanced operations (power, root, factorial, modulo)
 * - edge cases (negative inputs, zero division, overflow boundaries)
 * - decimal precision behavior with tolerance-based comparisons
 *
 * The tests are written using Google Test framework and validate both
 * correctness and numerical stability across a wide range of inputs.
 *
 * @author Erik Boháč
 */

#include <gtest/gtest.h>
#include <stdexcept>
#include <climits>
#include "core/mathlib.h"


/// Exact comparison tolerance
constexpr long double TOL_EXACT = 0.0L;

/// Small floating-point tolerance
constexpr long double TOL_SMALL = 1e-12L;

/// Medium floating-point tolerance
constexpr long double TOL_MED   = 1e-9L;

/// Large floating-point tolerance
constexpr long double TOL_LARGE = 1e-6L;

/// Very large tolerance for extreme values
constexpr long double TOL_HUGE  = 1e-3L;


TEST(MathLibTest, Addition)
{
	EXPECT_NEAR(add(2L, 3L), 5L, TOL_EXACT);
	EXPECT_NEAR(add(-1L, 0L), -1L, TOL_EXACT);
	EXPECT_NEAR(add(-5L, -5L), -10L, TOL_EXACT);
	EXPECT_NEAR(add(LLONG_MAX, LLONG_MIN), -1L, TOL_EXACT);
	EXPECT_NEAR(add(LLONG_MIN, 1L), -9'223'372'036'854'775'807L, TOL_HUGE);
}

TEST(MathLibTest, AdditionDecimal)
{
	EXPECT_NEAR(add(0.5L, 0.25L), 0.75L, TOL_EXACT);
	EXPECT_NEAR(add(3.42L, 1.58L), 5L, TOL_SMALL);
	EXPECT_NEAR(add(3.125'453L, -3.125'453L), 0L, TOL_SMALL);
	EXPECT_NEAR(add(1'675'664'566'455.545'434L, 5'445'675'234.653'45L), 1'681'110'241'690.198'884L, TOL_HUGE);
}

TEST(MathLibTest, Subtraction)
{
	EXPECT_NEAR(subtract(5L, 3L), 2L, TOL_EXACT);
	EXPECT_NEAR(subtract(0L, 1L), -1L, TOL_EXACT);
	EXPECT_NEAR(subtract(-1L, -2L), 1L, TOL_EXACT);
	EXPECT_NEAR(subtract(LLONG_MAX, LLONG_MAX), 0L, TOL_EXACT);
	EXPECT_NEAR(subtract(LLONG_MIN, LLONG_MIN), 0L, TOL_EXACT);
	EXPECT_NEAR(subtract(LLONG_MAX, 1L), 9'223'372'036'854'775'806L, TOL_HUGE);
}

TEST(MathLibTest, SubtractionDecimal)
{
	EXPECT_NEAR(subtract(0.5L, 0.25L), 0.25L, TOL_EXACT);
	EXPECT_NEAR(subtract(102.37L, -36.57L), 138.94L, TOL_SMALL);
	EXPECT_NEAR(subtract(-53453.76L, -53452.76L), -1L, TOL_SMALL);
	EXPECT_NEAR(subtract(652'342'344'745'645.652'343'452'34L, 65'423'464'554'543'364.545'453'456'5L), -64'771'122'209'797'718.893'110'004'16L, TOL_HUGE);
}

TEST(MathLibTest, Multiplication)
{
	EXPECT_NEAR(multiply(1L, 1L), 1L, TOL_EXACT);
	EXPECT_NEAR(multiply(10L, 0L), 0L, TOL_EXACT);
	EXPECT_NEAR(multiply(0L, 10L), 0L, TOL_EXACT);
	EXPECT_NEAR(multiply(1'000'000L, 1'000'000'000'000L), 1'000'000'000'000'000'000L, TOL_HUGE);
}

TEST(MathLibTest, MultiplicationDecimal)
{
	EXPECT_NEAR(multiply(2.1002L, 3.1003L), 6.511'250'06L, TOL_SMALL);
	EXPECT_NEAR(multiply(0L, 9.876'543'21L), 0L, TOL_EXACT);
	EXPECT_NEAR(multiply(123'456.789L, 987.654'321L), 121'932'631.112'635'269L, TOL_HUGE);
}

TEST(MathLibTest, Division)
{
	EXPECT_NEAR(divide(10000L, 100L), 100L, TOL_EXACT);
	EXPECT_NEAR(divide(1L, 10L), 0.1L, TOL_SMALL);
	EXPECT_NEAR(divide(0L, 100L), 0L, TOL_EXACT);
}

TEST(MathLibTest, DivisionDecimal)
{
	EXPECT_NEAR(divide(198.657L, 1L), 198.657L, TOL_SMALL);
	EXPECT_NEAR(divide(987.654'321L, 123.456'789L), 8.000'000'072'900'000'663L, TOL_HUGE);
}

TEST(MathLibTest, DivisionByZero)
{
	EXPECT_THROW(divide(13423L, 0L), std::domain_error);
	EXPECT_THROW(divide(-45345.7435L, 0L), std::domain_error);
}

TEST(MathLibTest, Factorial)
{
	EXPECT_NEAR(factorial(0L), 1L, TOL_EXACT);
	EXPECT_NEAR(factorial(1L), 1L, TOL_EXACT);
	EXPECT_NEAR(factorial(5L), 120L, TOL_EXACT);
	EXPECT_NEAR(factorial(20L), 2'432'902'008'176'640'000L, TOL_HUGE);
}

TEST(MathLibTest, FactorialNegative)
{
	EXPECT_THROW(factorial(-1L), std::domain_error);
	EXPECT_THROW(factorial(-10L), std::domain_error);
}

TEST(MathLibTest, FactorialDecimal)
{
	EXPECT_THROW(factorial(1.1L), std::domain_error);
	EXPECT_THROW(factorial(-3.5L), std::domain_error);
}

TEST(MathLibTest, Power)
{
	EXPECT_NEAR(power(1L, 0L), 1L, TOL_EXACT);
	EXPECT_NEAR(power(10L, 0L), 1L, TOL_EXACT);
	EXPECT_NEAR(power(4L, 16L), 4'294'967'296L, TOL_MED);
	EXPECT_NEAR(power(22L, 10L), 26'559'922'791'424L, TOL_LARGE);
	EXPECT_NEAR(power(2L, 60L), 1'152'921'504'606'846'976L, TOL_HUGE);
	EXPECT_THROW(power(0L, 0L), std::domain_error);
}

TEST(MathLibTest, PowerBaseNegative)
{
	EXPECT_NEAR(power(-1L, 0L), 1L, TOL_EXACT);
	EXPECT_NEAR(power(-10L, 0L), 1L, TOL_EXACT);
	EXPECT_NEAR(power(-1L, 2L), 1L, TOL_EXACT);
	EXPECT_NEAR(power(-1L, 3L), -1L, TOL_EXACT);
	EXPECT_NEAR(power(-2L, 10L), 1024L, TOL_EXACT);
	EXPECT_NEAR(power(-3L, 9L), -19683L, TOL_SMALL);
}

TEST(MathLibTest, PowerBaseDecimal)
{
	EXPECT_NEAR(power(2.5L, 2L), 6.25L, TOL_EXACT);
	EXPECT_NEAR(power(100.001L, 4L), 100'004'000.060'000'400'001L, TOL_LARGE);
	EXPECT_NEAR(power(23.5L, 8L), 93'012'838'522.503'906'25L, TOL_LARGE);
}

TEST(MathLibTest, PowerExponentNegative)
{
	EXPECT_NEAR(power(10L, -1L), 0.1, TOL_SMALL);
	EXPECT_NEAR(power(2L, -3L), 0.125, TOL_SMALL);
	EXPECT_NEAR(power(10L, -10L), 0.000'000'000'100, TOL_SMALL);
	EXPECT_NEAR(power(23.58L, -4), 0.000'003'234'631'391, TOL_SMALL);
}

TEST(MathLibTest, PowerExponentDec)
{
	EXPECT_THROW(power(2L, 2.5L), std::domain_error);
	EXPECT_THROW(power(100L, -1.35L), std::domain_error);
}

TEST(MathLibTest, Root)
{
	EXPECT_NEAR(root(64L, 6L), 2L, TOL_EXACT);
	EXPECT_NEAR(root(0L, 1L), 0L, TOL_EXACT);
	EXPECT_NEAR(root(54321L, 10L), 2.975'067'170'758'357'296L, TOL_SMALL);
	EXPECT_NEAR(root(1'152'921'504'606'846'976L, 60L), 2L, TOL_EXACT);
	EXPECT_THROW(root(0L, 0L), std::domain_error);
}

TEST(MathLibTest, RootDecimal)
{
	EXPECT_NEAR(root(1.1L, 2L), 1.048'808'848'170'151'546L, TOL_SMALL);
	EXPECT_NEAR(root(54321.12345L, 5L), 8.851'028'693'491'321'781L, TOL_SMALL);
	EXPECT_NEAR(root(1'000'000'000'000'000L, 24L), 4.216'965'034'285'822'485L, TOL_SMALL);
}

TEST(MathLibTest, RootNegativeOdd)
{
	EXPECT_NEAR(root(-4L, 1L), -4L, TOL_EXACT);
	EXPECT_NEAR(root(-8L, 3L), -2L, TOL_EXACT);
	EXPECT_NEAR(root(-987'654'321L, 11L), -6.571'906'269'033'026'256L, TOL_SMALL);
}

TEST(MathLibTest, RootNegativeEven)
{
	EXPECT_THROW(root(-1L, 2L), std::domain_error);
	EXPECT_THROW(root(-13'242'313L, 24L), std::domain_error);
}

TEST(MathLibTest, Modulo)
{
	EXPECT_NEAR(modulo(5L, 2L), 1L, TOL_EXACT);
	EXPECT_NEAR(modulo(-53'453L, 645L), 82L, TOL_EXACT);
	EXPECT_NEAR(modulo(1'000'000L, 10L), 0L, TOL_EXACT);
	EXPECT_NEAR(modulo(6'242'463'545L, 745'345L), 199'170L, TOL_EXACT);
	EXPECT_NEAR(modulo(LLONG_MAX, LLONG_MIN), -1L, TOL_SMALL);
}

TEST(MathLibTest, ModuloDecimal)
{
	EXPECT_NEAR(modulo(5.5L, 2L), 1.5L, TOL_SMALL);
	EXPECT_NEAR(modulo(-5.5L, 2L), 0.5L, TOL_SMALL);
	EXPECT_NEAR(modulo(23'423'342'345.435'465'645L, 3'433'425'345.756'465'756L), 2'822'790'270.896'671'109L, TOL_LARGE);
	EXPECT_NEAR(modulo(642'254'534.753'453'456L, -345'745.643'545L), -140'870.953'156'544L, TOL_LARGE);
}


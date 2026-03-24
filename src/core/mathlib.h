#ifndef MATH_LIB_H
#define MATH_LIB_H

/**
 * @file mathlib.h
 * @brief Header file containing declarations of mathematical functions.
 */

/**
 * @brief Function to add two numbers together.
 * 
 * @param a First number.
 * @param b Second number.
 * @return Sum of the two numbers.
 */
long double add(long double a, long double b);

/**
 * @brief Function to subtract two numbers.
 * 
 * @param a First number.
 * @param b Second number.
 * @return Result of subtracting b from a.
 */
long double subtract(long double a, long double b);

/**
 * @brief Function to multiply two numbers.
 * 
 * @param a First number.
 * @param b Second number.
 * @return Product of the two numbers.
 */
long double multiply(long double a, long double b);

/**
 * @brief Function to divide two numbers.
 * 
 * @param a Dividend.
 * @param b Divisor.
 * @return Result of dividing a by b.
 * @throw std::runtime_error if b is zero.
 */
long double divide(long double a, long double b);

/**
 * @brief Function to calculate the factorial of a given non-negative integer.
 * 
 * @param a Non-negative integer.
 * @return Factorial of the input integer.
 */
long double factorial(long double a);

/**
 * @brief Function to exponentiate the first number by the second number.
 * 
 * @param a Base.
 * @param b Exponent.
 * @return Result of raising a to the power of b.
 * @note Exponent must be an integer.
 */
long double power(long double a, long double b);

/**
 * @brief Function to calculate the square root.
 * 
 * @param a Number.
 * @param b Exponent.
 * @return Square root of the number.
 * @note Exponent must be an integer.
 */
long double root(long double a, long double b);

/**
 * @brief Function to calculate the modulo.
 * 
 * @param a Dividend.
 * @param b Divisor.
 * @return Result of the modulo operation.
 * @throw std::runtime_error if b is zero.
 */
long double modulo(long double a, long double b);

#endif
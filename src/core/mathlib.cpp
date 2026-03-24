#include <iostream>
#include <stack>
#include <cctype>
#include "mathlib.h"
#include <cmath>

/**
 * @brief Function to add two numbers.
 * 
 * @param a First number.
 * @param b Second number.
 * @return Sum of the two numbers.
 */
long double add(long double a, long double b)
{
    return a + b;
}

/**
 * @brief Function to subtract two numbers.
 * 
 * @param a First number.
 * @param b Second number.
 * @return Result of subtracting b from a.
 */
long double subtract(long double a, long double b)
{
    return a - b;
}

/**
 * @brief Function to multiply two numbers.
 * 
 * @param a First number.
 * @param b Second number.
 * @return Product of the two numbers.
 */
long double multiply(long double a, long double b)
{
    return a * b;
}

/**
 * @brief Function to divide two numbers.
 * 
 * @param a Dividend.
 * @param b Divisor.
 * @return Result of dividing a by b.
 * @throws std::domain_error if b is zero.
 */
long double divide(long double a, long double b)
{
    if (b == 0)
    {
        throw std::domain_error("Zero division error"); /**< Cannot divide by zero */
    }
    else
    {
        return a / b;
    }
}

/**
 * @brief Function to calculate the factorial of a non-negative integer.
 * 
 * @param a Non-negative integer.
 * @return Factorial of the input integer.
 */
long double factorial(long double a)
{
    if (fmod(a, 1) != 0){
        std::domain_error("Not an integer");
    }
    if (a < 0)
    {
        throw std::domain_error("Negative number error"); /**< Factorial is not defined for negative numbers */
    }
    else if (a == 0 || a == 1)
    {
        return 1; /**< Factorial of 0 and 1 is 1 */
    }
    else
    {
        return a * factorial(a - 1);
    }
}

/**
 * @brief Function to calculate the power of a number.
 * 
 * @param a Base.
 * @param b Exponent.
 * @return Result of raising a to the power of b.
 * @note Exponent must be an integer.
 */
long double power(long double a, long double b)
{
    if (fmod(b, 1) == 0)
    {
        return pow(a, b);
    }
    else
    {
        throw std::domain_error("Not an integer");
    }
}

/**
 * @brief Function to calculate the square root of a number.
 * 
 * @param a Number.
 * @param b Exponent.
 * @return Square root of the number.
 * @note Exponent must be an integer.
 */

long double root(long double a, long double b)
{
    if (b == 0) throw std::domain_error("");

    // pokud je exponent celé číslo
    if (fmod(b, 1.0) == 0)
    {
        int ib = (int)b;

        if (a < 0)
        {
            if (ib % 2 == 0) {
                throw std::domain_error("Even square root of negative number");
            }
            return -pow(-a, 1.0 / b);
        }
    }
    return pow(a, 1.0 / b);
}

/**
 * @brief Function to calculate the modulo of two numbers.
 * 
 * @param a Dividend.
 * @param b Divisor.
 * @return Result of the modulo operation.
 * @throws std::domain_error if b is zero.
 */
long double modulo(long double a, long double b)
{
    if (b == 0)
    {
        throw std::domain_error("Division by zero");
    }
    else
    {   
        long double result = fmod(a, b);

        // úprava na matematické modulo
        if ((result < 0 && b > 0) || (result > 0 && b < 0))
        result += b;
    }
}
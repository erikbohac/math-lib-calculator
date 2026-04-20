#include <iostream>
#include <stack>
#include <cctype>
#include "mathlib.h"
#include <cmath>


long double add(long double a, long double b)
{
	return a + b;
}


long double subtract(long double a, long double b)
{
	return a - b;
}


long double multiply(long double a, long double b)
{
	return a * b;
}


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


long double power(long double a, long double b)
{
	if (a == 0 && b == 0)
	{
		throw std::domain_error("Undefined operation");
	}
	if (fmod(b, 1) == 0)
	{
		return pow(a, b);
	}
	else
	{
		throw std::domain_error("Not an integer");
	}
}


long double root(long double a, long double b)
{
	if (b == 0) throw std::domain_error("");

	// pokud je exponent celé číslo
	if (fmod(b, 1.0) == 0)
	{
		int ib = (int)b;

		if (a < 0)
		{
			if (ib % 2 == 0)
			{
				throw std::domain_error("Even square root of negative number");
			}
			return -pow(-a, 1.0 / b);
		}
	}
	return pow(a, 1.0 / b);
}


long double modulo(long double a, long double b)
{
	if (b == 0)
	{
		throw std::domain_error("Division by zero");
	}
	else
	{
		long double q = std::trunc(a / b);
		long double r = a - b * q;

		if (r != 0 && ((r < 0) != (b < 0)))
			r += b;

		return r;
	}
}


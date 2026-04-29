/**
 * @file stddev.cpp
 * @brief Computes the standard deviation of a sequence of numbers from standard input.
 *
 * This program reads a sequence of numbers from standard input and computes
 * their standard deviation using helper mathematical functions provided in
 * core/mathlib.h.
 *
 * The computation is done step-by-step using:
 * - sum of values
 * - sum of squared values
 * - arithmetic mean
 * - variance and square root
 *
 * @author Dominik Dusbaba
 */

#include <iostream>
#include "core/mathlib.h"

int main()
{
	long double x = 0;

	/// Sum of all input numbers
	long double sum = 0;

	/// Sum of squares of all input numbers
	long double sum2 = 0;

	/// Number of input values
	long double n = 0;

	/// Arithmetic mean of input values
	long double avg = 0;

	/// Final result (standard deviation)
	long double result = 0;

	// Reading numbers from standard input
	while (std::cin >> x)
	{
		n = add(n, 1);
		sum = add(sum, x);
		sum2 = add(sum2, multiply(x, x));
	}

	// At least 2 numbers are required
	if (n < 2)
	{
		return 1;
	}

	// Compute arithmetic mean
	avg = divide(sum, n);

	// Compute variance and standard deviation
	result = divide(subtract(sum2, multiply(n, multiply(avg, avg))),subtract(n, 1));
	result = root(result, 2);

	// Output result
	std::cout << result << std::endl;

	return 0;
}


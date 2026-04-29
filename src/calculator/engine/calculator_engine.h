/**
 * @file calculator_engine.h
 * @brief Declaration of the CalculatorEngine class used for evaluating mathematical expressions.
 *
 * This file defines a static utility class responsible for parsing and evaluating
 * mathematical expressions represented as strings. It also provides preprocessing
 * utilities to normalize and prepare expressions before evaluation.
 *
 * @author Erik Boháč
 */

#pragma once

#include <string>


/**
 * @class CalculatorEngine
 * @brief Provides functionality to evaluate mathematical expressions.
 *
 * The CalculatorEngine class is a static utility class that supports evaluation
 * of string-based mathematical expressions. It also includes internal preprocessing
 * steps to handle formatting, whitespace, unary signs, and root operations.
 */
class CalculatorEngine
{
	public:
		/**
		 * @brief Evaluates a mathematical expression given as a string.
		 *
		 * This function parses and computes the result of a mathematical expression.
		 * The expression may contain basic arithmetic operations and supported functions
		 * depending on the implementation.
		 *
		 * @param expression The mathematical expression to evaluate.
		 * @return The computed result as a double.
		 */
		static double evaluate(const std::string& expression);

	private:
		/**
		 * @brief Preprocesses root expressions in the input string.
		 *
		 * Converts or normalizes root notation into a format suitable for evaluation.
		 *
		 * @param input The expression string to modify.
		 */
		static void preprocess_root(std::string& input);

		/**
		 * @brief Removes or normalizes whitespace in the input expression.
		 *
		 * Ensures the expression is free of unnecessary spaces before parsing.
		 *
		 * @param input The expression string to modify.
		 */
		static void preprocess_spaces(std::string& input);

		/**
		 * @brief Preprocesses sign operators in the expression.
		 *
		 * Handles unary plus/minus and normalizes sign usage for consistent parsing.
		 *
		 * @param input The expression string to modify.
		 */
		static void preprocess_sign(std::string& input);
};


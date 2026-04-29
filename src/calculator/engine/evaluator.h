/**
 * @file evaluator.h
 * @brief Defines the Evaluator class for computing results from Reverse Polish Notation (RPN).
 *
 * This file contains the Evaluator class, which is responsible for evaluating mathematical
 * expressions that have already been converted into Reverse Polish Notation (postfix form).
 * It supports both binary and unary operations.
 *
 * @author Erik Boháč
 */

#pragma once

#include "token.h"
#include <vector>


/**
 * @class Evaluator
 * @brief Evaluates mathematical expressions in Reverse Polish Notation (RPN).
 *
 * The Evaluator class processes a sequence of tokens in postfix order and computes
 * the resulting numerical value. It supports binary operators (e.g., +, -, *, /)
 * as well as unary operators (e.g., negation).
 */
class Evaluator
{
	public:
		/**
		 * @brief Evaluates an expression given in Reverse Polish Notation.
		 *
		 * This function processes a vector of tokens representing a postfix expression
		 * and computes its final numerical result.
		 *
		 * @param rpn A vector of Token objects in Reverse Polish Notation order.
		 * @return The computed result as a double.
		 */
		double evaluate(const std::vector<Token>& rpn);

	private:
		/**
		 * @brief Applies a binary operator to two operands.
		 *
		 * Supported operators typically include arithmetic operations such as +, -, *, and /.
		 *
		 * @param op The operator character.
		 * @param a The left-hand operand.
		 * @param b The right-hand operand.
		 * @return The result of applying the operator.
		 */
		double applyBinary(char op, double a, double b);

		/**
		 * @brief Applies a unary operator to a single operand.
		 *
		 * Used for operations such as negation.
		 *
		 * @param op The operator character.
		 * @param a The operand.
		 * @return The result of applying the unary operator.
		 */
		double applyUnary(char op, double a);
};


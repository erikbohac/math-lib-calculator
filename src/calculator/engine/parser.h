/**
 * @file parser.h
 * @brief Defines the Parser class for converting infix token sequences to Reverse Polish Notation (RPN).
 *
 * This file contains the Parser class, which is responsible for transforming a list of tokens
 * representing a mathematical expression in infix notation into Reverse Polish Notation (postfix form).
 * It uses operator precedence and associativity rules to perform the conversion.
 *
 * @author Erik Boháč
 */

#pragma once

#include "token.h"
#include <vector>


/**
 * @class Parser
 * @brief Converts infix expressions into Reverse Polish Notation (RPN).
 *
 * The Parser class implements an algorithm (typically Shunting Yard) to convert a sequence
 * of tokens from infix notation into postfix notation (RPN), which is easier to evaluate.
 */
class Parser
{
	public:
		/**
		 * @brief Constructs a Parser with a given list of tokens.
		 *
		 * Initializes the parser with an infix token sequence that will later be converted
		 * into Reverse Polish Notation.
		 *
		 * @param tokens A vector of Token objects representing an infix expression.
		 */
		explicit Parser(const std::vector<Token>& tokens);

		/**
		 * @brief Converts the stored infix tokens into Reverse Polish Notation.
		 *
		 * Uses operator precedence and associativity rules to reorder tokens into postfix form.
		 *
		 * @return A vector of Token objects in RPN order.
		 */
		std::vector<Token> toRPN();

	private:
		/// Internal storage of the infix token sequence
		std::vector<Token> tokens;

		/**
		 * @brief Determines the precedence of an operator.
		 *
		 * Higher returned values indicate higher precedence.
		 *
		 * @param op The operator character.
		 * @return Integer representing operator precedence.
		 */
		int precedence(char op);

		/**
		 * @brief Checks if an operator is right-associative.
		 *
		 * Used during RPN conversion to handle operators like exponentiation correctly.
		 *
		 * @param op The operator character.
		 * @return True if the operator is right-associative, false otherwise.
		 */
		bool isRightAssociative(char op);
};


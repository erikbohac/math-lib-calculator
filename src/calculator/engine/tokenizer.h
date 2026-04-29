/**
 * @file tokenizer.h
 * @brief Defines the Tokenizer class for converting input strings into token sequences.
 *
 * This file contains the Tokenizer class, which is responsible for breaking a raw
 * mathematical expression string into a sequence of Tokens. These tokens are later
 * used by the Parser and Evaluator components to compute results.
 *
 * @author Erik Boháč
 */

#pragma once

#include "token.h"
#include <vector>
#include <string>


/**
 * @class Tokenizer
 * @brief Converts a raw input string into a sequence of tokens.
 *
 * The Tokenizer reads a mathematical expression character by character and converts
 * it into a structured sequence of Token objects representing numbers, operators,
 * and parentheses.
 */
class Tokenizer
{
	public:
		/**
		 * @brief Constructs a Tokenizer with the given input string.
		 *
		 * Initializes the tokenizer with the expression that will be processed.
		 *
		 * @param input The mathematical expression as a string.
		 */
		explicit Tokenizer(const std::string& input);

		/**
		 * @brief Converts the input string into a list of tokens.
		 *
		 * Parses the input expression and returns a sequence of Token objects
		 * representing numbers, operators, and parentheses.
		 *
		 * @return A vector of Token objects representing the tokenized expression.
		 */
		std::vector<Token> tokenize();

	private:
		/// The input expression string to be tokenized
		std::string input;

		/// Current position in the input string
		size_t pos = 0;

		/**
		 * @brief Reads and consumes the current character.
		 *
		 * Advances the position in the input string and returns the current character.
		 *
		 * @return The character at the current position before advancing.
		 */
		char read();

		/**
		 * @brief Peeks at the current character without consuming it.
		 *
		 * @return The current character at the current position.
		 */
		char get();

		/**
		 * @brief Skips whitespace characters in the input string.
		 */
		void skipWhitespace();

		/**
		 * @brief Parses a numeric value from the input string.
		 *
		 * Reads consecutive digits (and possibly decimal point) to form a number token.
		 *
		 * @return A Token representing a numeric value.
		 */
		Token parseNumber();
};


/**
 * @file token.h
 * @brief Defines token types and the Token structure used for expression parsing.
 *
 * This file contains the TokenType enumeration and Token structure, which are used
 * throughout the calculator system to represent parsed elements of a mathematical
 * expression such as numbers, operators, and parentheses.
 *
 * @author Erik Boháč
 */

#pragma once

#include <string>


/**
 * @enum TokenType
 * @brief Represents the type of a token in a mathematical expression.
 */
enum class TokenType
{
	Number,
	Operator,
	LParen,
	RParen
};

/**
 * @struct Token
 * @brief Represents a single element (token) of a parsed mathematical expression.
 *
 * A Token can represent a number, an operator, or a parenthesis. It stores both
 * the type and associated data (numeric value or operator character).
 */
struct Token
{
	TokenType type; ///< Type of the token
	double value;   ///< Numeric value (valid if type == Number)
	char op;        ///< Operator character (valid if type == Operator)

	/**
	 * @brief Creates a numeric token.
	 *
	 * @param v The numeric value to store.
	 * @return A Token of type Number containing the given value.
	 */
	static Token number(double v)
	{
		return
		{
			TokenType::Number, v, 0
		};
	}

	/**
	 * @brief Creates an operator token.
	 *
	 * @param c The operator character (e.g., '+', '-', '*', '/').
	 * @return A Token of type Operator containing the given operator.
	 */
	static Token operation(char c)
	{
		return
		{
			TokenType::Operator, 0, c
		};
	}
};


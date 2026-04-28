#pragma once

#include <string>


enum class TokenType
{
	Number,
	Operator,
	LParen,
	RParen
};

struct Token
{
	TokenType type;
	double value;
	char op;

	static Token number(double v)
	{
		return
		{
			TokenType::Number, v, 0
		};
	}

	static Token operation(char c)
	{
		return
		{
			TokenType::Operator, 0, c
		};
	}
};


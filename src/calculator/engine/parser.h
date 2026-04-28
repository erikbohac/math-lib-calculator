#pragma once

#include "token.h"
#include <vector>


class Parser
{
	public:
		explicit Parser(const std::vector<Token>& tokens);

		std::vector<Token> toRPN();

	private:
		std::vector<Token> tokens;

		int precedence(char op);
		bool isRightAssociative(char op);
};


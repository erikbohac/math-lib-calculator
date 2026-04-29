#include "parser.h"
#include <stack>
#include <stdexcept>


Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens)
{
}

int Parser::precedence(char op)
{
	if(op == '+' || op == '-')
	{
		return 1;
	}
	if(op == '*' || op == '/' || op == '%')
	{
		return 2;
	}
	if(op == '^' || op == 'r')
	{
		return 3;
	}
	if(op == '!')
	{
		return 4;
	}
	return 0;
}

bool Parser::isRightAssociative(char op)
{
	return op == '^' || op == 'r';
}

std::vector<Token> Parser::toRPN()
{
	std::vector<Token> output;
	std::stack<Token> ops;
	TokenType prevType = TokenType::Operator;
	bool prevFact = false;

	for(const auto& token : tokens)
	{
		if(token.type == TokenType::Number)
		{
			if(prevType == TokenType::Number || prevType == TokenType::RParen)
			{
				throw std::runtime_error("Missing operator between values");
			}

			output.push_back(token);
			prevType = TokenType::Number;
		}
		else if(token.type == TokenType::Operator)
		{
			if(prevType == TokenType::Operator && token.op != '!' && !prevFact)
			{
				throw std::runtime_error(std::string("Unexpected operator '") + token.op + "'");
			}

			while(!ops.empty() && ops.top().type == TokenType::Operator)
			{
				char o2 = ops.top().op;

				if((!isRightAssociative(token.op) && precedence(token.op) <= precedence(o2)) || (isRightAssociative(token.op) && precedence(token.op) < precedence(o2)))
				{
					output.push_back(ops.top());
					ops.pop();
				}
				else
				{
					break;
				}
			}

			prevFact = false;
			if(token.op == '!')
			{
				prevFact = true;
			}

			ops.push(token);
			prevType = TokenType::Operator;
		}
		else if(token.type == TokenType::LParen)
		{
			ops.push(token);
			prevType = TokenType::LParen;
		}
		else if(token.type == TokenType::RParen)
		{
			bool found = false;

			while(!ops.empty())
			{
				if(ops.top().type == TokenType::LParen)
				{
					found = true;
					ops.pop();
					break;
				}
				output.push_back(ops.top());
				ops.pop();
			}

			if(!found)
			{
				throw std::runtime_error("Mismatched parentheses");
			}

			prevType = TokenType::RParen;		}
	}

	while(!ops.empty())
	{
		if(ops.top().type == TokenType::LParen)
		{
			throw std::runtime_error("Mismatched parentheses");
		}

		output.push_back(ops.top());
		ops.pop();
	}

	return output;
}


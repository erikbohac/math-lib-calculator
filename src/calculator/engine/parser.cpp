#include "parser.h"
#include <stack>


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

	for(const auto& t : tokens)
	{
		if(t.type == TokenType::Number)
		{
			output.push_back(t);
		}
		else if(t.type == TokenType::Operator)
		{
			while(!ops.empty() && ops.top().type == TokenType::Operator)
			{
				char o2 = ops.top().op;

				if((!isRightAssociative(t.op) && precedence(t.op) <= precedence(o2)) || (isRightAssociative(t.op) && precedence(t.op) < precedence(o2)))
				{
					output.push_back(ops.top());
					ops.pop();
				}
				else
				{
					break;
				}
			}
			ops.push(t);
		}
		else if(t.type == TokenType::LParen)
		{
			ops.push(t);
		}
		else if(t.type == TokenType::RParen)
		{
			while(!ops.empty() && ops.top().type != TokenType::LParen)
			{
				output.push_back(ops.top());
				ops.pop();
			}
			ops.pop();
		}
	}

	while(!ops.empty())
	{
		output.push_back(ops.top());
		ops.pop();
	}

	return output;
}


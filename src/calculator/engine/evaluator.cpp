#include "evaluator.h"
#include "core/mathlib.h"
#include <stack>
#include <stdexcept>


double Evaluator::applyBinary(char op, double a, double b)
{
	switch(op)
	{
		case '+':
			return add(a, b);
		case '-':
			return subtract(a, b);
		case '*':
			return multiply(a, b);
		case '/':
			return divide(a, b);
		case '%':
			return modulo(a, b);
		case '^':
			return power(a, b);
		case 'r':
			return root(b, a);
		default:
			throw std::runtime_error("Unknown binary operator");
	}
}

double Evaluator::applyUnary(char op, double a)
{
	switch(op)
	{
		case '!':
			return factorial(a);
		default:
			throw std::runtime_error("Unknown unary operator");
	}
}

double Evaluator::evaluate(const std::vector<Token>& rpn)
{
	std::stack<double> st;

	for(const auto& token : rpn)
	{
		if(token.type == TokenType::Number)
		{
			st.push(token.value);
		}
		else
		{
			if(token.op == '!')
			{
				if(st.empty())
				{
					throw std::runtime_error("Missing operand for '!'");
				}

				double a = st.top();
				st.pop();
				st.push(applyUnary(token.op, a));
			}
			else
			{
				if(st.size() < 2)
				{
					throw std::runtime_error("Missing operands for binary operator");
				}

				double b = st.top();
				st.pop();
				double a = st.top();
				st.pop();
				st.push(applyBinary(token.op, a, b));
			}
		}
	}

	if(st.size() != 1)
	{
		throw std::runtime_error("Invalid expression");
	}

	return st.top();
}


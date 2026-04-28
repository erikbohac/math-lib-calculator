#include "evaluator.h"
#include "core/mathlib.h"
#include <stack>


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
			return 0.0;
	}
}

double Evaluator::applyUnary(char op, double a)
{
	switch(op)
	{
		case '!':
			return factorial(a);
		default:
			return 0.0;
	}
}

double Evaluator::evaluate(const std::vector<Token>& rpn)
{
	std::stack<double> st;

	for(const auto& t : rpn)
	{
		if(t.type == TokenType::Number)
		{
			st.push(t.value);
		}
		else
		{
			if(t.op == '!')
			{
				double a = st.top();
				st.pop();
				st.push(applyUnary(t.op, a));
			}
			else
			{
				double b = st.top();
				st.pop();
				double a = st.top();
				st.pop();
				st.push(applyBinary(t.op, a, b));
			}
		}
	}

	return st.top();
}


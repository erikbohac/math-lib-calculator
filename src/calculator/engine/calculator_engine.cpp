#include "calculator_engine.h"


double CalculatorEngine::evaluate(const std::string &expr)
{
	size_t len = expr.length();
    std::string norm = normalize(expr, len);
    return compute(norm, len);
}

std::string CalculatorEngine::normalize(const std::string &expr, size_t len)
{
	char prev_char = 0;
	std::string norm_expr = "";
	for(unsigned i = 0; i < len; ++i)
	{
		char curr_char = expr[i];

		
		if(curr_char == '(' && prev_char >= '0' && prev_char <= '9')
		{
			norm_expr += '*';
		}

		if(curr_char != ' ')
		{
			norm_expr += curr_char;
		}

		prev_char = curr_char;
	}

	return norm_expr;
}

double CalculatorEngine::compute(const std::string &expr, size_t len)
{
    // implementation here
}


#include "calculator_engine.h"
#include "tokenizer.h"
#include "parser.h"
#include "evaluator.h"
#include <cstddef>


double CalculatorEngine::evaluate(const std::string& expression)
{
	std::string normalized = expression;
	CalculatorEngine::preprocess_root(normalized);
	CalculatorEngine::preprocess_spaces(normalized);
	CalculatorEngine::preprocess_sign(normalized);

	Tokenizer tokenizer(normalized);
	auto tokens = tokenizer.tokenize();

	Parser parser(tokens);
	auto rpn = parser.toRPN();

	Evaluator evaluator;
	return evaluator.evaluate(rpn);
}

void CalculatorEngine::preprocess_root(std::string& expr)
{
	const std::string root_utf8 = "√";
	const std::string root_internal = "r";

	size_t pos = 0;
	while((pos = expr.find(root_utf8, pos)) != std::string::npos)
	{
		expr.replace(pos, root_utf8.length(), root_internal);
		pos += root_internal.length();
	}
}

void CalculatorEngine::preprocess_spaces(std::string& expr)
{
	size_t out_index = 0;

	for (size_t i = 0; i < expr.size(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(expr[i])))
		{
			expr[out_index++] = expr[i];
		}
	}

	expr.resize(out_index);
}

void CalculatorEngine::preprocess_sign(std::string& expr)
{
	size_t expr_size = expr.size();
	size_t index, out_index;

	for(index = 0, out_index = 0; out_index < expr_size; ++index, ++out_index)
	{
	    expr[index] = expr[out_index];
		if(expr[index] == '-' && expr[out_index + 1] == '-')
		{
			expr[index] = '+';
			++out_index;
		}
	}

	expr.resize(index);
}


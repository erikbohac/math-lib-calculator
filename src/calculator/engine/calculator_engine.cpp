#include "calculator_engine.h"
#include "tokenizer.h"
#include "parser.h"
#include "evaluator.h"


double CalculatorEngine::evaluate(const std::string& expression)
{
	std::string normalized = CalculatorEngine::preprocess(expression);

	Tokenizer tokenizer(normalized);
	auto tokens = tokenizer.tokenize();

	Parser parser(tokens);
	auto rpn = parser.toRPN();

	Evaluator evaluator;
	return evaluator.evaluate(rpn);
}

std::string CalculatorEngine::preprocess(const std::string& input)
{
	std::string out = input;

	const std::string root_utf8 = "√";
	const std::string root_internal = "r";

	size_t pos = 0;
	while((pos = out.find(root_utf8, pos)) != std::string::npos)
	{
		out.replace(pos, root_utf8.length(), root_internal);
		pos += root_internal.length();
	}

	return out;
}


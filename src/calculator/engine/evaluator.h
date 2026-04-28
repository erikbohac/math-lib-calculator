#pragma once

#include "token.h"
#include <vector>


class Evaluator
{
	public:
		double evaluate(const std::vector<Token>& rpn);

	private:
		double applyBinary(char op, double a, double b);
		double applyUnary(char op, double a);
};


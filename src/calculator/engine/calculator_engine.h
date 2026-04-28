#pragma once

#include <string>


class CalculatorEngine
{
	public:
		static double evaluate(const std::string& expression);

	private:
		static std::string preprocess(const std::string& input);
};


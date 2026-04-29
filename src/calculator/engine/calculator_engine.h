#pragma once

#include <string>


class CalculatorEngine
{
	public:
		static double evaluate(const std::string& expression);

	private:
		static void preprocess_root(std::string& input);
		static void preprocess_spaces(std::string& input);
		static void preprocess_sign(std::string& input);
};


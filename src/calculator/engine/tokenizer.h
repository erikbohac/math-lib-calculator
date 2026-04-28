#pragma once

#include "token.h"
#include <vector>
#include <string>


class Tokenizer
{
	public:
		explicit Tokenizer(const std::string& input);

		std::vector<Token> tokenize();

	private:
		std::string input;
		size_t pos = 0;

		char read();
		char get();
		void skipWhitespace();
		Token parseNumber();
};


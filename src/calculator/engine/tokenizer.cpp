#include "tokenizer.h"
#include <cctype>
#include <cstring>
#include <stdexcept>


Tokenizer::Tokenizer(const std::string& input) : input(input)
{
}

char Tokenizer::read()
{
	return pos < input.size() ? input[pos] : '\0';
}

char Tokenizer::get()
{
	return pos < input.size() ? input[pos++] : '\0';
}

void Tokenizer::skipWhitespace()
{
	while(isspace(read()))
	{
		get();
	}
}

Token Tokenizer::parseNumber()
{
	size_t start = pos;
	while(isdigit(read()) || read() == '.')
	{
		get();
	}

	return Token::number(std::stod(input.substr(start, pos - start)));
}

std::vector<Token> Tokenizer::tokenize()
{
	TokenType prevType = TokenType::Operator;
	std::vector<Token> tokens;

	while(pos < input.size())
	{
		skipWhitespace();
		char c = read();

		if(isdigit(c) || c == '.')
		{
			tokens.push_back(parseNumber());
		}
		else if(strchr("+-*/%^!", c))
		{
			tokens.push_back(Token::operation(get()));
		}
		else if(c == 'r')
		{
			if(prevType == TokenType::Operator || prevType == TokenType::LParen || tokens.empty())
			{
				Token two = Token::number(2.0);
				tokens.push_back(two);
			}

			tokens.push_back(Token::operation(get()));
			prevType = TokenType::Operator;
		}
		else if(c == '(')
		{
			get(); tokens.push_back({TokenType::LParen, 0, 0});
		}
		else if(c == ')')
		{
			get(); tokens.push_back({TokenType::RParen, 0, 0});
		}
		else
		{
			throw std::runtime_error("Invalid character");
		}
	}

	return tokens;
}


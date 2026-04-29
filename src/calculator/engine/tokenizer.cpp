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
	bool hasDot = false;

	while(isdigit(read()) || read() == '.')
	{
		if(read() == '.')
		{
			if(hasDot)
			{
				throw std::runtime_error("Invalid number format at position " + std::to_string(pos));
			}
			hasDot = true;
		}
		get();
	}

	std::string str = input.substr(start, pos - start);

	try
	{
		return Token::number(std::stod(str));
	}
	catch(...)
	{
		throw std::runtime_error("Failed to parse number at position " + std::to_string(start));
	}
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
			prevType = TokenType::Number;
		}
		else if(strchr("+-*/%^!", c))
		{
			tokens.push_back(Token::operation(get()));
			prevType = TokenType::Operator;
		}
		else if(c == 'r')
		{
			if(prevType != TokenType::Number)
			{
				tokens.push_back(Token::number(2.0));
			}
			tokens.push_back(Token::operation(get()));
			prevType = TokenType::Operator;
		}
		else if(c == '(')
		{
			get();
			tokens.push_back({TokenType::LParen, 0, 0});
			prevType = TokenType::LParen;
		}
		else if(c == ')')
		{
			get();
			tokens.push_back({TokenType::RParen, 0, 0});
			prevType = TokenType::RParen;
		}
		else
		{
			throw std::runtime_error(std::string("Invalid character '") + c + "' at position " + std::to_string(pos));
		}
	}

	return tokens;
}


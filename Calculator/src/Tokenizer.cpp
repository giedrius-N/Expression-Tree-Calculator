#include "Tokenizer.h"
#include <cctype>
#include <iostream>

void Tokenizer::Tokenize(std::string& expression, std::vector<Token>& tokens)
{
	// Remove spaces
	expression.erase(std::remove_if(expression.begin(), expression.end(), isspace), expression.end());

	tokens.reserve(expression.size());

	std::string currentNumber;

	for (char character : expression)
	{
		if (std::isdigit(character) || character == '.')
		{
			currentNumber += character;
		}
		else
		{
			if (!currentNumber.empty())
			{
				tokens.emplace_back(TokenType::NUMBER, std::stod(currentNumber));
				currentNumber.clear();
				continue;
			}

			if (IsOperator(character))
			{
				tokens.emplace_back(TokenType::OPERATOR, character);
			}
		}
	}

	if (!currentNumber.empty())
	{
		tokens.emplace_back(TokenType::NUMBER, std::stod(currentNumber));
	}
}

bool Tokenizer::IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

#include "Tokenizer.h"
#include <cctype>
#include <iostream>

void Tokenizer::Tokenize(std::string& expression, std::vector<Token>& tokens)
{
	// Removes spaces
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
				// Creates number token
				tokens.emplace_back(std::stod(currentNumber));
				currentNumber.clear();
				continue;
			}

			if (IsOperator(character))
			{
				// Creates operation token
				tokens.emplace_back(character);
			}
		}
	}

	if (!currentNumber.empty())
	{
		tokens.emplace_back(std::stod(currentNumber));
	}
}

bool Tokenizer::IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

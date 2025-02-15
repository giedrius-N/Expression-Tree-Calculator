#include "Calculator.h"
#include "Tokenizer.h"
#include <iostream>

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

double Calculator::Evaluate(std::string expression)
{
	double result = 0.0;

	std::vector<Token> tokens;

	Tokenizer::Tokenize(expression, tokens);

	for (auto const& token : tokens)
	{
		if (token.GetType() == TokenType::NUMBER)
		{
			std::cout << token.GetNumber() << std::endl;
		}
		else
		{
			std::cout << token.GetOperation() << std::endl;
		}
	}

	return result;
}

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

	for (auto token : tokens)
	{
		if (token.type == TokenType::NUMBER)
		{
			std::cout << token.number << std::endl;
		}
		else
		{
			std::cout << token.operation << std::endl;
		}
	}

	return result;
}

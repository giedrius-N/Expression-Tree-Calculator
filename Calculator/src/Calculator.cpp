#include "Calculator.h"
#include "Tokenizer.h"
#include "ExpressionParser.h"
#include "Types.h"
#include <iostream>

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

double Calculator::Evaluate(std::string expression)
{
	std::cout << "Given expression: " << expression << std::endl;

	std::vector<Token> tokens;

	VariableMap variables;

	Tokenizer::Tokenize(expression, tokens, variables);

	for (auto const& pair : variables)
	{
		std::cout << pair.first << " " << pair.second << std::endl;
	}

	ExpressionParser parser;
	auto root = parser.BuildExpressionTree(tokens, variables);
	auto result = root->Evaluate();
	
	for (auto const& token : tokens)
	{
		if (token.GetType() == TokenType::NUMBER)
		{
			std::cout << token.GetNumber() << std::endl;
		}
		else if (token.GetType() == TokenType::OPERATOR)
		{
			std::cout << token.GetOperation() << std::endl;
		}
		else
		{
			std::cout << token.GetVariable() << std::endl;
		}
	}

	return result;
}

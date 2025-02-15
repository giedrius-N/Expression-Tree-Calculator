#include "Calculator.h"
#include "Tokenizer.h"
#include "ExpressionParser.h"
#include <iostream>

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

double Calculator::Evaluate(std::string expression)
{
	std::vector<Token> tokens;

	Tokenizer::Tokenize(expression, tokens);

	ExpressionParser parser;
	auto root = parser.BuildExpressionTree(tokens);

	auto result = root->Evaluate();

	return result;
}

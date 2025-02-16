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
	std::vector<Token> tokens;
	VariableMap variables;

	try 
	{
		Tokenizer::Tokenize(expression, tokens, variables);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
        throw;
 	}

	ExpressionParser parser;
	double result = 0.0;
	try
	{
		auto root = parser.BuildExpressionTree(tokens, variables);
		result = root->Evaluate();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
        throw;
	}

	return result;
}

double Calculator::Evaluate(const std::string& expression, const VariableMap& predefinedVariables)
{
    std::vector<Token> tokens;
    // Use the predefined variables.
    VariableMap variables = predefinedVariables;

    try
    {
        Tokenizer::Tokenize(const_cast<std::string&>(expression), tokens, variables);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }

    ExpressionParser parser;
    double result = 0.0;
    try
    {
        auto root = parser.BuildExpressionTree(tokens, variables);
        result = root->Evaluate();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }

    return result;
}

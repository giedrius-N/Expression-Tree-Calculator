#include "Calculator.h"
#include "Tokenizer.h"
#include "ExpressionParser.h"
#include "Types.h"
#include <iostream>

template class Calculator<double>;

template <typename T>
Calculator<T>::Calculator()
{
}

template <typename T>
Calculator<T>::~Calculator()
{
}

template <typename T>
T Calculator<T>::Evaluate(std::string expression)
{
    VariableMap<T> variables;
    return EvaluateExpression(expression, variables);
}

template <typename T>
T Calculator<T>::Evaluate(const std::string& expression, const VariableMap<T>& predefinedVariables)
{
    return EvaluateExpression(expression, predefinedVariables);
}

template <typename T>
T Calculator<T>::EvaluateExpression(std::string expression, VariableMap<T> variables)
{
    std::vector<Token<T>> tokens;

    try
    {
        Tokenizer<T>::Tokenize(expression, tokens, variables);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        throw;
    }

    ExpressionParser<T> parser;
    T result = 0.0;
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
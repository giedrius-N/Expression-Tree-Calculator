#include "ExpressionParser.h"
#include "NumberNode.h"
#include "OperatorNode.h"
#include <stack>
#include <stdexcept>

/// <summary>
/// Initializing ExpressionParser with three main and tested types: double, float, and int.
/// </summary>
template class ExpressionParser<double>;
template class ExpressionParser<float>;
template class ExpressionParser<int>;

template <typename T>
ExpressionParser<T>::ExpressionParser()
{
}

template <typename T>
ExpressionParser<T>::~ExpressionParser()
{
}

template <typename T>
std::unique_ptr<Node<T>> ExpressionParser<T>::BuildExpressionTree(
    const std::vector<Token<T>>& tokens, 
    const VariableMap<T>& variablePool
)
{
    std::stack<std::unique_ptr<Node<T>>> nodeStack;

    for (const auto& token : tokens)
    {
        if (token.GetType() == TokenType::NUMBER)
        {
            nodeStack.push(std::make_unique<NumberNode<T>>(token.GetNumber()));
        }
        else if (token.GetType() == TokenType::VARIABLE)
        {
            try
            {
                T value = variablePool.at(token.GetVariable());
                nodeStack.push(std::make_unique<NumberNode<T>>(value));
            }
            catch (const std::out_of_range&)
            {
                throw std::runtime_error("Missing variable value!");
            }
        }
        else if (token.GetType() == TokenType::OPERATOR)
        {
            char op = token.GetOperation();
            // If unary minus
            if (op == 'u')
            {
                if (nodeStack.empty())
                {
                    throw std::runtime_error("Invalid expression: missing operand for unary minus.");
                }
                // Pop one operand and create a binary subtraction dummy 0 - operand.
                auto operand = std::move(nodeStack.top());
                nodeStack.pop();
                nodeStack.push(
                    std::make_unique<OperatorNode<T>>(
                        '-',
                        std::make_unique<NumberNode<T>>(static_cast<T>(0.0)),
                        std::move(operand)
                        )
                );
            }
            else
            {
                if (nodeStack.size() < 2)
                {
                    throw std::runtime_error("Invalid expression");
                }
                auto right = std::move(nodeStack.top());
                nodeStack.pop();
                auto left = std::move(nodeStack.top());
                nodeStack.pop();
                nodeStack.push(
                    std::make_unique<OperatorNode<T>>(
                        op,
                        std::move(left),
                        std::move(right)
                        )
                );
            }
        }
    }
    
    // Verify that the stack contains exactly one node, representing the final result.
    if (nodeStack.size() != 1)
    {
        throw std::runtime_error("Invalid expression");
    }

    std::unique_ptr<Node<T>> result = std::move(nodeStack.top());
    nodeStack.pop();

    return result;
}
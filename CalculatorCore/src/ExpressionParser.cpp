#include "ExpressionParser.h"
#include "NumberNode.h"
#include "OperatorNode.h"
#include <stack>
#include <stdexcept>

ExpressionParser::ExpressionParser()
{
}

ExpressionParser::~ExpressionParser()
{
}

std::unique_ptr<Node> ExpressionParser::BuildExpressionTree(
    const std::vector<Token>& tokens, 
    VariableMap& variablePool
)
{
    std::stack<std::unique_ptr<Node>> nodeStack;

    for (const auto& token : tokens)
    {
        if (token.GetType() == TokenType::NUMBER)
        {
            nodeStack.push(std::make_unique<NumberNode>(token.GetNumber()));
        }
        else if (token.GetType() == TokenType::VARIABLE)
        {
            try
            {
                double value = variablePool.at(token.GetVariable());
                nodeStack.push(std::make_unique<NumberNode>(value));
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
                    std::make_unique<OperatorNode>(
                        '-',
                        std::make_unique<NumberNode>(0.0),
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
                    std::make_unique<OperatorNode>(
                        op,
                        std::move(left),
                        std::move(right)
                        )
                );
            }
        }
    }
    
    // Verify that the stack contains exactly one node, representing the final result.
    if (nodeStack.size() != 1 || nodeStack.empty())
    {
        throw std::runtime_error("Invalid expression");
    }

    std::unique_ptr<Node> result = std::move(nodeStack.top());
    nodeStack.pop();

    return result;
}
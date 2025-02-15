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

std::unique_ptr<Node> ExpressionParser::BuildExpressionTree(const std::vector<Token>& tokens)
{
    std::stack<std::unique_ptr<Node>> nodeStack;

    for (const auto& token : tokens)
    {
        if (token.GetType() == TokenType::NUMBER)
        {
            nodeStack.push(std::make_unique<NumberNode>(token.GetNumber()));
        }
        else if (token.GetType() == TokenType::OPERATOR)
        {
            if (nodeStack.size() < 2)
            {
                throw std::runtime_error("Invalid expression");
            }

            auto right = std::move(nodeStack.top());
            nodeStack.pop();
            auto left = std::move(nodeStack.top());
            nodeStack.pop();

            nodeStack.push(std::make_unique<OperatorNode>(token.GetOperation(), std::move(left), std::move(right)));
        }
    }

    if (nodeStack.size() != 1)
    {
        throw std::runtime_error("Invalid expression");
    }

    if (nodeStack.empty())
    {
        throw std::runtime_error("Stack is empty when trying to return result");
    }

    std::unique_ptr<Node> result = std::move(nodeStack.top());
    nodeStack.pop();
    return result;
}
#include "OperatorNode.h"
#include <stdexcept>

OperatorNode::OperatorNode(
	char operation, 
	std::unique_ptr<Node> left, 
	std::unique_ptr<Node> right
)
	: m_operation(operation)
	, m_left(std::move(left))
	, m_right(std::move(right))
{
}

double OperatorNode::Evaluate() const
{
	double leftValue = m_left->Evaluate();
	double rightValue = m_right->Evaluate();

	switch (m_operation)
	{
	case '+':
		return leftValue + rightValue;
	case '-':
		return leftValue - rightValue;
	case '*':
		return leftValue * rightValue;
	case '/':
		if (rightValue != 0)
		{
			return leftValue / rightValue;
		}
		else
		{
			throw std::runtime_error("Division by zero!");
		}
	default:
		throw std::runtime_error("Uknown operator");
	}
}
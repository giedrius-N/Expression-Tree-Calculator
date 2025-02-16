#include "OperatorNode.h"
#include <stdexcept>

template class OperatorNode<double>;

template <typename T>
OperatorNode<T>::OperatorNode(
	char operation, 
	std::unique_ptr<Node<T>> left, 
	std::unique_ptr<Node<T>> right
)
	: m_operation(operation)
	, m_left(std::move(left))
	, m_right(std::move(right))
{
}

template <typename T>
T OperatorNode<T>::Evaluate() const
{
	T leftValue = m_left->Evaluate();
	T rightValue = m_right->Evaluate();

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
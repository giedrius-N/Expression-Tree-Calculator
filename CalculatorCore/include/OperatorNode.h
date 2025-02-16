#ifndef OPERATORNODE_H
#define OPERATORNODE_H
#include "Node.h"
#include <memory>

/// <summary>
/// Node representing an operator.
/// </summary>
/// <typeparam name="T">Numeric type.</typeparam>
template <typename T>
class OperatorNode : public Node<T>
{
public:
	/// <summary>
	/// Creates an OperatorNode with an operation and operands.
	/// </summary>
	/// <param name="operation">Operator character.</param>
	/// <param name="left">Left operand node.</param>
	/// <param name="right">Right operand node.</param>
	OperatorNode(char operation, std::unique_ptr<Node<T>> left, std::unique_ptr<Node<T>> right);
	
	/// <summary>
	/// Evaluates the operation using left and right operands.
	/// </summary>
	/// <returns>Result of the operation.</returns>
	T Evaluate() const override;

private:
	// Operator symbol.
	char m_operation;
	// Left operand node.
	std::unique_ptr<Node<T>> m_left;
	// Right operand node.
	std::unique_ptr<Node<T>> m_right;
};

#endif // OPERATORNODE_H
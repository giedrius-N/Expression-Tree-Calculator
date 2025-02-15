#ifndef OPERATORNODE_H
#define OPERATORNODE_H
#include "Node.h"
#include <memory>

/// <summary>
/// Node representing an operator.
/// </summary>
class OperatorNode : public Node
{
public:
	/// <summary>
	/// Creates an OperatorNode with an operation and operands.
	/// </summary>
	/// <param name="operation">Operator character.</param>
	/// <param name="left">Left operand node.</param>
	/// <param name="right">Right operand node.</param>
	OperatorNode(char operation, std::unique_ptr<Node> left, std::unique_ptr<Node> right);
	
	/// <summary>
	/// Evaluates the operation using left and right operands.
	/// </summary>
	/// <returns>Result of the operation as double.</returns>
	double Evaluate() const override;

private:
	// Operator symbol.
	char m_operation;
	// Left operand node.
	std::unique_ptr<Node> m_left;
	// Right operand node.
	std::unique_ptr<Node> m_right;
};

#endif // OPERATORNODE_H
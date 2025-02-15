#ifndef NUMBERNODE_H
#define NUMBERNODE_H
#include "Node.h"

/// <summary>
/// Node representing a numeric value (leaf node).
/// </summary>
class NumberNode : public Node
{
public:
	/// <summary>
	/// Creates a NumberNode with a given value.
	/// </summary>
	/// <param name="value">The numeric value.</param>
	NumberNode(double value);
	
	/// <summary>
	/// Evaluates and returns the stored numeric value.
	/// </summary>
	/// <returns>Numeric value as double.</returns>
	double Evaluate() const override;

private:
	// Stored numeric value.
	double m_value;
};

#endif // NUMBERNODE_H
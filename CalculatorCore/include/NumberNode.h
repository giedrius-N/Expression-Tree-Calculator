#ifndef NUMBERNODE_H
#define NUMBERNODE_H
#include "Node.h"

/// <summary>
/// Node representing a numeric value (leaf node).
/// </summary>
/// <typeparam name="T">Numeric type.</typeparam>
template <typename T>
class NumberNode : public Node<T>
{
public:
	/// <summary>
	/// Creates a NumberNode with a given value.
	/// </summary>
	/// <param name="value">The numeric value.</param>
	explicit NumberNode(T value);
	
	/// <summary>
	/// Evaluates and returns the stored numeric value.
	/// </summary>
	/// <returns>Numeric value.</returns>
	T Evaluate() const override;

private:
	// Stored numeric value.
	T m_value;
};

#endif // NUMBERNODE_H
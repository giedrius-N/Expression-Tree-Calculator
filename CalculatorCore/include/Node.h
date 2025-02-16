#ifndef NODE_H
#define NODE_H

/// <summary>
/// Base class for expression tree nodes.
/// </summary>
/// <typeparam name="T">Numeric type</typeparam>
template <typename T>
class Node
{
public:
	/// <summary>
	/// Virtual destructor.
	/// </summary>
	virtual ~Node() = default;

	/// <summary>
	/// Evaluates the node and returns a result.
	/// </summary>
	/// <returns>Evaluated result as set type.</returns>
	virtual T Evaluate() const = 0;
};

#endif // NODE_H
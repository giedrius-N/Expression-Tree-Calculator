#ifndef NODE_H
#define NODE_H

/// <summary>
/// Base class for expression tree nodes.
/// </summary>
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
	/// <returns>Evaluated result as double.</returns>
	virtual T Evaluate() const = 0;
};

template class Node<double>;

#endif // NODE_H
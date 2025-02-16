#include "NumberNode.h"

/// <summary>
/// Initializing NumberNode with three main and tested types: double, float, and int.
/// </summary>
template class NumberNode<double>;
template class NumberNode<float>;
template class NumberNode<int>;

template <typename T>
NumberNode<T>::NumberNode(T value) : m_value(value)
{
}

template <typename T>
T NumberNode<T>::Evaluate() const
{
	return m_value;
}

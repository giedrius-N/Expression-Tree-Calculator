#include "NumberNode.h"

template class NumberNode<double>;

template <typename T>
NumberNode<T>::NumberNode(T value) : m_value(value)
{
}

template <typename T>
T NumberNode<T>::Evaluate() const
{
	return m_value;
}

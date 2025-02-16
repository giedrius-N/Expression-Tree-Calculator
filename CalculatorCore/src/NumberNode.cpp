#include "NumberNode.h"

NumberNode::NumberNode(double value) : m_value(value)
{
}

double NumberNode::Evaluate() const
{
	return m_value;
}
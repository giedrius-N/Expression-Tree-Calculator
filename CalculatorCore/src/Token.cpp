#include "Token.h"

template class Token<double>;

template <typename T>
Token<T>::Token(char operation)
	: m_type(TokenType::OPERATOR)
	, m_number(0)
	, m_operation(operation)
	, m_variable("")
{
}

template <typename T>
Token<T>::Token(T number)
	: m_type(TokenType::NUMBER)
	, m_number(number)
	, m_operation('\0')
	, m_variable("")
{
}

template <typename T>
Token<T>::Token(const std::string& variable)
	: m_type(TokenType::VARIABLE)
	, m_number(0)
	, m_operation('\0')
	, m_variable(variable)
{
}

template <typename T>
TokenType Token<T>::GetType() const
{
	return m_type;
}

template <typename T>
T Token<T>::GetNumber() const
{
	return m_number;
}

template <typename T>
char Token<T>::GetOperation() const
{
	return m_operation;
}

template <typename T>
std::string Token<T>::GetVariable() const
{
	return m_variable;
}
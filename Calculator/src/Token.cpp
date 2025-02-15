#include "Token.h"

Token::Token(char operation)
	: m_type(TokenType::OPERATOR)
	, m_number(0)
	, m_operation(operation)
	, m_variable("")
{
}

Token::Token(double number)
	: m_type(TokenType::NUMBER)
	, m_number(number)
	, m_operation('\0')
	, m_variable("")
{
}

Token::Token(const std::string& variable)
	: m_type(TokenType::VARIABLE)
	, m_number(0)
	, m_operation('\0')
	, m_variable(variable)
{
}

TokenType Token::GetType() const
{
	return m_type;
}

double Token::GetNumber() const
{
	return m_number;
}

char Token::GetOperation() const
{
	return m_operation;
}

std::string Token::GetVariable() const
{
	return m_variable;
}
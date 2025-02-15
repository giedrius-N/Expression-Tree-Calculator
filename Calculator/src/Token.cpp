#include "Token.h"

Token::Token(char operation)
	: m_type(TokenType::OPERATOR)
	, m_number(0)
	, m_operation(operation)
{
}

Token::Token(double number)
	: m_type(TokenType::NUMBER)
	, m_number(number)
	, m_operation('\0')
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
#ifndef TOKEN_H
#define TOKEN_H

/// <summary>
/// Enum representing the type of a token.
/// </summary>
enum class TokenType
{
	NUMBER,
	OPERATOR
};

/// <summary>
/// Represents a token in the expression, which can be a number or an operator.
/// </summary>
class Token
{
public:
	/// <summary>
	/// Constructor for number value token
	/// </summary>
	/// <param name="number">Double type number value</param>
	Token(double number);

	/// <summary>
	/// Constructor for math operation token
	/// </summary>
	/// <param name="operation">Char type mathematical operation</param>
	Token(char operation);

	/// <summary>
	/// Gets the token type.
	/// </summary>
	/// <returns>TokenType of the token.</returns>
	TokenType GetType() const;
	
	/// <summary>
	/// Gets the numeric value of the token.
	/// </summary>
	/// <returns>Double value of the token.</returns>
	double GetNumber() const;
	
	/// <summary>
	/// Gets the operator character.
	/// </summary>
	/// <returns>Operator character.</returns>
	char GetOperation() const;

private:
	// Type of the token
	TokenType m_type;
	// Numeric value (if token is a number)
	double m_number;
	// Operator character (if token is an operator)
	char m_operation;
};

#endif // TOKEN_H
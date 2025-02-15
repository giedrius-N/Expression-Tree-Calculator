#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "Token.h"
#include <string>
#include <vector>

/// <summary>
/// Static Tokenizer class to convert an expression string into tokens.
/// </summary>
class Tokenizer
{
public:
	/// <summary>
	/// Deleted default constructor to prevent instantiation.
	/// </summary>
	Tokenizer() = delete;

	/// <summary>
	/// Tokenizes the given expression into a vector of tokens.
	/// </summary>
	/// <param name="expression">The input mathematical expression as a string.</param>
	/// <param name="tokens">The output vector of tokens.</param>
	/// <param name="returnPostix">Flag to tell if return tokens in postfix form. Default is true</param>
	static void Tokenize(std::string& expression, std::vector<Token>& tokens, bool returnPostix = true);

private:
	/// <summary>
	/// Checks if the given character is a valid math operator.
	/// </summary>
	/// <param name="c">Character to check.</param>
	/// <returns>True if valid operator, otherwise false.</returns>
	static bool IsOperator(char c);

	/// <summary>
	/// Checks if the given character is a parenthesis.
	/// </summary>
	/// <param name="c">Character to check.</param>
	/// <returns>True if parenthesis, otherwise false.</returns>
	static bool IsParenthesis(char c);

	/// <summary>
	/// Converts an infix expression token list to postfix.
	/// </summary>
	/// <param name="tokens">Reference to the vector of tokens to convert.</param>
	static void InfixToPostfix(std::vector<Token>& tokens);

	/// <summary>
	/// Gets the precedence of the given operator.
	/// </summary>
	/// <param name="operation">Operator character.</param>
	/// <returns>Precedence value (higher means higher priority).</returns>
	static int GetPrecedence(char operation);
};

#endif // TOKENIZER_H

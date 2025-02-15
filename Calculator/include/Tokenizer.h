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
	static void Tokenize(std::string& expression, std::vector<Token>& tokens);

private:
	/// <summary>
	/// Checks if a character is a valid mathematical operator.
	/// </summary>
	/// <param name="c">The character to check.</param>
	/// <returns>True if the character is an operator, false otherwise.</returns>
	static bool IsOperator(char c);
};

#endif // TOKENIZER_H

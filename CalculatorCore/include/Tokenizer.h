#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "Token.h"
#include "Types.h"
#include <vector>

/// <summary>
/// Static Tokenizer class to convert an expression string into tokens.
/// </summary>
template <typename T>
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
	/// <param name="variables">Variable pool for symbolic variables in expression.</param>
	/// <param name="returnPostfix">Flag to tell if return tokens in postfix form. Default is true</param>
	static void Tokenize(std::string& expression, std::vector<Token<T>>& tokens, VariableMap<T>& variables, bool returnPostfix = true);

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
	static void InfixToPostfix(std::vector<Token<T>>& tokens);

	/// <summary>
	/// Gets the precedence of the given operator.
	/// </summary>
	/// <param name="operation">Operator character.</param>
	/// <returns>Precedence value (higher means higher priority).</returns>
	static int GetPrecedence(char operation);

	/// <summary>
	/// Extracts all variable names from the given expression.
	/// </summary>
	/// <param name="expression">The input mathematical expression as a string.</param>
	/// <returns>A vector of unique variable names found in the expression.</returns>
	static std::vector<std::string> GetVariables(const std::string& expression);

	/// <summary>
	/// Prompts the user to enter values for a list of variables.
	/// </summary>
	/// <param name="variableList">List of variables requiring user input.</param>
	/// <returns>A VariableMap containing variable names and their values.</returns>
	static VariableMap<T> PromptForVariableValues(const std::vector<std::string>& variableList);

	/// <summary>
	/// Inserts multiplication operators between numbers and variables where omitted.
	/// </summary>
	/// <param name="expression">The input expression to be processed.</param>
	static void InsertMultiplication(std::string& expression);
};

#endif // TOKENIZER_H

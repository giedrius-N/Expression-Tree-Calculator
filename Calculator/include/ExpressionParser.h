#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H
#include "Node.h"
#include "Token.h"
#include "Types.h"
#include <memory>
#include <vector>

/// <summary>
/// Parses tokens into an expression tree for evaluation.
/// </summary>
class ExpressionParser
{
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	ExpressionParser();

	/// <summary>
	/// Default destructor.
	/// </summary>
	~ExpressionParser();

	/// <summary>
	/// Builds an expression tree from a vector of tokens.
	/// The token list must represent a postfix expression.
	/// </summary>
	/// <param name="tokens">Vector of tokens representing the expression.</param>
	/// <returns>Unique pointer to the root node of the expression tree.</returns>
	std::unique_ptr<Node> BuildExpressionTree(const std::vector<Token>& tokens, VariableMap& variablePool);
};

#endif // EXPRESSIONPARSER_H
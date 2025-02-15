#include "Tokenizer.h"
#include <cctype>
#include <stack>
#include <iostream>

void Tokenizer::Tokenize(std::string& expression, std::vector<Token>& tokens, bool returnPostfix)
{
	// Removes spaces
	expression.erase(std::remove_if(expression.begin(), expression.end(), isspace), expression.end());

	tokens.reserve(expression.size());

	std::string currentNumber;

	for (char character : expression)
	{
		if (std::isdigit(character) || character == '.')
		{
			currentNumber += character;
		}
		else
		{
			if (!currentNumber.empty())
			{
				// Creates number token
				tokens.emplace_back(std::stod(currentNumber));
				currentNumber.clear();
				//continue;
			}

			if (IsOperator(character) || IsParenthesis(character))
			{
				// Creates operation token
				tokens.emplace_back(character);
			}
		}
	}

	if (!currentNumber.empty())
	{
		tokens.emplace_back(std::stod(currentNumber));
	}

	if (returnPostfix)
	{
		InfixToPostfix(tokens);
	}
}

bool Tokenizer::IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

bool Tokenizer::IsParenthesis(char c)
{
	return c == '(' || c == ')';
}

int Tokenizer::GetPrecedence(char operation)
{
	switch (operation)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}

void Tokenizer::InfixToPostfix(std::vector<Token>& tokens)
{
	std::vector<Token> postfix;
	postfix.reserve(tokens.size());

	std::stack<Token> opStack;

    for (const auto& token : tokens)
    {
        if (token.GetType() == TokenType::NUMBER)
        {
            // Numbers go directly to the output
            postfix.push_back(token);
        }
        else if (IsOperator(token.GetOperation()))
        {
            // While there is an operator at the top of the stack with greater or equal precedence,
            // pop it to the output.
            while (!opStack.empty() && IsOperator(opStack.top().GetOperation()) &&
                GetPrecedence(opStack.top().GetOperation()) >= GetPrecedence(token.GetOperation()))
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
        else if (IsParenthesis(token.GetOperation()))
        {
            if (token.GetOperation() == '(')
            {
                // Push left parenthesis onto the stack
                opStack.push(token);
            }
            else if (token.GetOperation() == ')')
            {
                // Pop from the stack until a left parenthesis is encountered
                while (!opStack.empty() && opStack.top().GetOperation() != '(')
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                if (opStack.empty())
                {
                    throw std::runtime_error("Mismatched parentheses");
                }
                // Discard the '('
                opStack.pop();
            }
        }
    }

    // Pop any remaining operators from the stack
    while (!opStack.empty())
    {
        if (IsParenthesis(opStack.top().GetOperation()))
        {
            throw std::runtime_error("Mismatched parentheses");
        }
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    // Replace the original tokens vector with the postfix version
    tokens = std::move(postfix);
}

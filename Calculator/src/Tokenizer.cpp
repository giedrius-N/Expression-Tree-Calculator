#include "Tokenizer.h"
#include <cctype>
#include <stack>
#include <iostream>
#include <unordered_set>

void Tokenizer::Tokenize(
    std::string& expression, 
    std::vector<Token>& tokens, 
    VariableMap& variables, 
    bool returnPostfix
)
{
    expression.erase(
        std::remove_if(
            expression.begin(), 
            expression.end(), 
            isspace
        ), 
        expression.end()
    );
    tokens.reserve(expression.size());

    std::vector<std::string> variableList = GetVariables(expression);

    if (!variableList.empty())
    {
        variables = PromptForVariableValues(variableList);
        // Insert '*' between numbers and variables to ensure correct parsing
        InsertMultiplication(expression);
    }

    std::string currentNumber;
    std::string currentVariable;

    for (char character : expression)
    {
        if (std::isdigit(character) || character == '.')
        {
            if (!currentVariable.empty())
            {
                tokens.emplace_back(currentVariable);
                currentVariable.clear();
            }
            currentNumber += character;
        }
        else if (std::isalpha(character))
        {
            if (!currentNumber.empty())
            {
                tokens.emplace_back(std::stod(currentNumber));
                currentNumber.clear();
            }
            currentVariable += character;
        }
        else
        {
            if (!currentNumber.empty())
            {
                tokens.emplace_back(std::stod(currentNumber));
                currentNumber.clear();
            }
            if (!currentVariable.empty())
            {
                tokens.emplace_back(currentVariable);
                currentVariable.clear();
            }
            if (IsOperator(character) || IsParenthesis(character))
            {
                tokens.emplace_back(character);
            }
        }
    }

    if (!currentNumber.empty())
    {
        tokens.emplace_back(std::stod(currentNumber));
    }
    if (!currentVariable.empty())
    {
        tokens.emplace_back(currentVariable);
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

std::vector<std::string> Tokenizer::GetVariables(const std::string& expression)
{
    std::vector<std::string> variables;
    std::unordered_set<std::string> seen;

    int i = 0;
    while (i < expression.size())
    {
        if (std::isalpha(expression[i]))
        {
            std::string var;
            while (i < expression.size() && std::isalpha(expression[i]))
            {
                var.push_back(expression[i]);
                i++;
            }

            if (!var.empty() && seen.find(var) == seen.end())
            {
                variables.push_back(var);
                seen.insert(var);
            }
        }
        else
        {
            i++;
        }
    }

    return variables;
}

VariableMap Tokenizer::PromptForVariableValues(const std::vector<std::string>& variableList)
{
    VariableMap variableValues;

    for (const auto& var : variableList)
    {
        double value;
        std::cout << "Please enter a value for variable '" << var << "': ";
        std::cin >> value;
        variableValues[var] = value;
    }

    return variableValues;
}

void Tokenizer::InsertMultiplication(std::string& expression)
{
    std::string result;
    for (size_t i = 0; i < expression.size(); ++i)
    {
        result += expression[i];

        if (std::isdigit(expression[i]) 
            && i + 1 < expression.size() 
            && std::isalpha(expression[i + 1]))
        {
            result += '*';
        }
    }
    expression =  result;
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

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        const Token& current = tokens[i];

        if (current.GetType() == TokenType::NUMBER || current.GetType() == TokenType::VARIABLE)
        {
            // Numbers and variables go directly to the output.
            postfix.push_back(current);
        }
        else if (IsOperator(current.GetOperation()))
        {
            char op = current.GetOperation();

            // Determine if '-' is acting as a unary minus.
            bool isUnaryMinus = false;
            if (op == '-')
            {
                // If it's the first token then this minus is unary.
                if (i == 0)
                {
                    isUnaryMinus = true;
                }
                else
                {
                    // Get the token one before current
                    const Token& prev = tokens[i - 1];
                    // If the previous token is an operator (but not a closing ')'),
                    // then there is no left-hand operand, so minus is unary. 
                    if (prev.GetType() == TokenType::OPERATOR && prev.GetOperation() != ')')
                    {
                        isUnaryMinus = true;
                    }
                }
            }

            if (isUnaryMinus)
            {
                // Insert a dummy zero to convert unary minus into binary subtraction.
                postfix.push_back(Token(0.0));
            }

            while (!opStack.empty() &&
                IsOperator(opStack.top().GetOperation()) &&
                GetPrecedence(opStack.top().GetOperation()) >= GetPrecedence(op))
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(current);
        }
        else if (IsParenthesis(current.GetOperation()))
        {
            if (current.GetOperation() == '(')
            {
                opStack.push(current);
            }
            else // ')'
            {
                while (!opStack.empty() && opStack.top().GetOperation() != '(')
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                if (opStack.empty())
                {
                    throw std::runtime_error("Mismatched parentheses");
                }
                opStack.pop(); // Discard '('
            }
        }
    }

    while (!opStack.empty())
    {
        if (IsParenthesis(opStack.top().GetOperation()))
        {
            throw std::runtime_error("Mismatched parentheses");
        }
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    tokens = std::move(postfix);
}

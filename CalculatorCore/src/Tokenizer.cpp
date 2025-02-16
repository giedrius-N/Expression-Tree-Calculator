#include "Tokenizer.h"
#include <cctype>
#include <stack>
#include <iostream>
#include <unordered_set>

/// <summary>
/// Initializing Tokenizer with three main and tested types: double, float, and int.
/// </summary>
template class Tokenizer<double>;
template class Tokenizer<float>;
template class Tokenizer<int>;

template <typename T>
void Tokenizer<T>::Tokenize(
    std::string& expression, 
    std::vector<Token<T>>& tokens, 
    VariableMap<T>& variables, 
    bool returnPostfix
)
{
    // Removing spaces
    expression.erase(
        std::remove_if(
            expression.begin(), 
            expression.end(), 
            isspace
        ), 
        expression.end()
    );
    tokens.reserve(expression.size());

    auto variableList = GetVariables(expression);

    if (variables.empty() && !variableList.empty())
    {
        variables = PromptForVariableValues(variableList);
        // Insert '*' between numbers and variables to ensure correct parsing
    }
    if (!variableList.empty())
    {
        InsertMultiplication(expression);
    }

    for (size_t i = 0; i < expression.size(); ++i)
    {
        char c = expression[i];

        // Check if the character is a minus, that might be a unary minus.
        if (c == '-')
        {
            bool isUnary = false;
            // If it's the first character, it must be unary.
            if (i == 0)
            {
                isUnary = true;
            }
            else
            {
                char prev = expression[i - 1];
                // If the previous character is not a digit or a closing parenthesis,
                // then this minus is unary.
                if (!std::isdigit(prev) && prev != ')')
                {
                    isUnary = true;
                }
            }

            if (isUnary && i + 1 < expression.size() && (std::isdigit(expression[i + 1]) || expression[i + 1] == '.'))
            {
                std::string numberStr = "-";
                i++;

                // Accumulate the number characters.
                while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.'))
                {
                    numberStr.push_back(expression[i]);
                    i++;
                }
                // Convert the accumulated string to a number and add it as a token.
                tokens.emplace_back(std::stod(numberStr));
                i--; // Adjust index (the for-loop will increment it).
                continue;
            }
            else
            {
                tokens.emplace_back(c);
            }
        }
        else if (std::isdigit(c) || c == '.')
        {
            // Build a number token.
            std::string numStr;
            while (i < expression.size() && (std::isdigit(expression[i]) || expression[i] == '.'))
            {
                numStr.push_back(expression[i]);
                i++;
            }
            tokens.emplace_back(std::stod(numStr));
            i--;
        }
        else if (std::isalpha(c))
        {
            // Build a variable token.
            std::string varStr;
            while (i < expression.size() && std::isalpha(expression[i]))
            {
                varStr.push_back(expression[i]);
                i++;
            }
            tokens.emplace_back(varStr);
            i--;
        }
        else if (IsOperator(c) || IsParenthesis(c))
        {
            tokens.emplace_back(c);
        }
        else
        {
            throw std::runtime_error(std::string("Unexpected character: ") + c);
        }
    }

	if (returnPostfix)
	{
		InfixToPostfix(tokens);
	}
}

template <typename T>
bool Tokenizer<T>::IsOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

template <typename T>
bool Tokenizer<T>::IsParenthesis(char c)
{
	return c == '(' || c == ')';
}

template <typename T>
std::vector<std::string> Tokenizer<T>::GetVariables(const std::string& expression)
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
template <typename T>
VariableMap<T> Tokenizer<T>::PromptForVariableValues(const std::vector<std::string>& variableList)
{
    VariableMap<T> variableValues;

    for (const auto& var : variableList)
    {
        T value;
        std::cout << "Please enter a value for variable '" << var << "': ";
        std::cin >> value;
        variableValues[var] = value;
    }

    return variableValues;
}

template <typename T>
void Tokenizer<T>::InsertMultiplication(std::string & expression)
{
    std::string result;
    result.reserve(expression.size() * 2);

    for (auto i = 0U; i < expression.size(); i++)
    {
        result.push_back(expression[i]);

        if (i + 1 < expression.size())
        {
            char current = expression[i];
            char next = expression[i + 1];

            if ((std::isdigit(current) && std::isalpha(next)) ||
                (std::isalpha(current) && std::isdigit(next)))
            {
                result.push_back('*');
            }
        }
    }

    expression = std::move(result);
}

constexpr int GetPrecedenceHelper(char operation)
{
    switch (operation)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case 'u': // Unary minus
        return 3;
    default:
        return -1;
    }
}

template <typename T>
int Tokenizer<T>::GetPrecedence(char operation)
{
    return GetPrecedenceHelper(operation);
}

template <typename T>
void Tokenizer<T>::InfixToPostfix(std::vector<Token<T>>& tokens)
{
    std::vector<Token<T>> postfix;
    postfix.reserve(tokens.size());

    auto opStack = std::stack<Token<T>>{};

    for (size_t i = 0; i < tokens.size(); ++i)
    {
        const Token<T>& current = tokens[i];

        if (current.GetType() == TokenType::NUMBER || current.GetType() == TokenType::VARIABLE)
        {
            // Numbers and variables go directly to the output.
            postfix.push_back(current);
        }
        else if (IsOperator(current.GetOperation()))
        {
            // Determine if minus is an unary minus.
            char op = current.GetOperation();
            bool isUnaryMinus = false;
            if (op == '-')
            {
                if (i == 0)
                {
                    isUnaryMinus = true;
                }
                else
                {
                    const Token<T>& prev = tokens[i - 1];
                    // If the previous token is not a number and not a variable,
                    // then there is no valid left-hand operand.
                    if (prev.GetType() != TokenType::NUMBER && prev.GetType() != TokenType::VARIABLE)
                    {
                        isUnaryMinus = true;
                    }
                }
            }

            if (isUnaryMinus)
            {
                // Creating unary minus operation
                Token<T> unaryMinus('u');
                while (!opStack.empty() &&
                    IsOperator(opStack.top().GetOperation()) &&
                    GetPrecedence(opStack.top().GetOperation()) >= GetPrecedence('u'))
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(unaryMinus);
            }
            else
            {
                // Process as a normal binary operator.
                while (!opStack.empty() &&
                    IsOperator(opStack.top().GetOperation()) &&
                    GetPrecedence(opStack.top().GetOperation()) >= GetPrecedence(op))
                {
                    postfix.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(current);
            }
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


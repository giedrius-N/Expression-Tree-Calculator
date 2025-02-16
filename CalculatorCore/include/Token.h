#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <type_traits>

/// <summary>
/// Enum representing the type of a token.
/// </summary>
enum class TokenType
{
    NUMBER,
    OPERATOR,
    VARIABLE
};

/// <summary>
/// Represents a token in the expression, which can be a number, an operator, or a variable.
/// Only the numeric value is templated.
/// </summary>
/// <typeparam name="T">Numeric type.</typeparam>
template <typename T>
class Token
{
public:
    /// <summary>
    /// Constructor for number value token.
    /// Only enabled if U is an arithmetic type (int, float, double, etc.).
    /// </summary>
    /// <param name="number">Arithmetic number value</param>
    template <typename U, typename = std::enable_if_t<std::is_arithmetic<U>::value>>
    explicit Token(U number)
        : m_type(TokenType::NUMBER), 
        m_number(static_cast<T>(number)), 
        m_operation('\0'), m_variable("") {}

    /// <summary>
    /// Constructor for math operation token.
    /// </summary>
    /// <param name="operation">Char type mathematical operation</param>
    explicit Token(char operation)
        : m_type(TokenType::OPERATOR), 
        m_number(static_cast<T>(0)), 
        m_operation(operation), 
        m_variable("") {}

    /// <summary>
    /// Constructor for a variable token.
    /// </summary>
    /// <param name="variable">String representing the variable name.</param>
    explicit Token(const std::string& variable)
        : m_type(TokenType::VARIABLE), 
        m_number(static_cast<T>(0)), 
        m_operation('\0'),
        m_variable(variable) {}

    /// <summary>
    /// Gets the token type.
    /// </summary>
    /// <returns>TokenType of the token.</returns>
    TokenType GetType() const { return m_type; }

    /// <summary>
    /// Gets the numeric value of the token.
    /// </summary>
    /// <returns>Numeric value of the token.</returns>
    T GetNumber() const { return m_number; }

    /// <summary>
    /// Gets the operator character.
    /// </summary>
    /// <returns>Operator character.</returns>
    char GetOperation() const { return m_operation; }

    /// <summary>
    /// Gets the variable name of the token.
    /// </summary>
    /// <returns>Variable name as a string.</returns>
    const std::string& GetVariable() const { return m_variable; }

private:
    TokenType m_type;
    T m_number;
    char m_operation; 
    std::string m_variable; 
};

#endif // TOKEN_H

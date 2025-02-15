#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <string>
#include <vector>

enum class TokenType
{
	NUMBER,
	OPERATOR
};

struct Token
{
	TokenType type;
	char operation;
	double number;

	Token(TokenType t, double n) : type(t), number(n), operation('\0') {}
	Token(TokenType t, char op) : type(t), number(0), operation(op) {}
};

class Tokenizer
{
public:
	Tokenizer() = delete;

	static void Tokenize(std::string& expression, std::vector<Token>& tokens);

private:
	static bool IsOperator(char c);
};

#endif // TOKENIZER_H

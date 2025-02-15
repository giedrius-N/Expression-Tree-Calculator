#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>

class Calculator
{
public:
	Calculator();
	~Calculator();

	double Evaluate(std::string expression);
};

#endif // CALCULATOR_H

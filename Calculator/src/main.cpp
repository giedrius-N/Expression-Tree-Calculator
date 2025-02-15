#include "Calculator.h"
#include <iostream>

int main()
{
	std::string expression = "10 + 20x + 20 / 5";
	Calculator calc;

	double result = calc.Evaluate(expression);

	std::cout << "Mathematical expression: " << expression << std::endl;
	std::cout << "The result: " << result << std::endl;

	return 0;
}

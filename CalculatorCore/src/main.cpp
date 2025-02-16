#include "Calculator.h"
#include <iostream>

int main()
{
    std::cout << "Enter a mathematical expression: ";
    std::string expression;
    std::getline(std::cin, expression);

    Calculator calc;
    try
    {
        double result = calc.Evaluate(expression);
        std::cout << "Mathematical expression: " << expression << std::endl;
        std::cout << "The result: " << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error evaluating expression: " << e.what() << std::endl;
    }

	return 0;
}

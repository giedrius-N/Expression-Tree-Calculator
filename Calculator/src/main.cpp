#include "Calculator.h"
#include <iostream>

int main()
{
	Calculator calc;

	calc.Evaluate("1.5+5+9.25 * 20.1 - (5 - 20) / 2.1a");

	return 0;
}

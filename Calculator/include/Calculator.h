#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "Types.h"
#include <string>

/// <summary>
/// Calculator class to evaluate mathematical expressions.
/// </summary>
class Calculator
{
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	Calculator();

	/// <summary>
	/// Default destructor.
	/// </summary>
	~Calculator();

	/// <summary>
	/// Evaluates the given mathematical expression.
	/// </summary>
	/// <param name="expression">String containing the mathematical expression.</param>
	/// <returns>Evaluation result as double.</returns>
	double Evaluate(std::string expression);

	/// <summary>
	/// Evaluates a mathematical expression using a predefined set of variables.
	/// </summary>
	/// <param name="expression">String containing the mathematical expression.</param>
	/// <param name="predefinedVariables">A map containing predefined variable values.</param>
	/// <returns>Evaluation result as double</returns>
	double Evaluate(const std::string& expression, const VariableMap& predefinedVariables);
};

#endif // CALCULATOR_H

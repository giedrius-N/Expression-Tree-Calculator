#ifndef TYPES_H
#define TYPES_H
#include <unordered_map>
#include <string>

/// <summary>
/// Type alias for a map storing variable names as strings and their corresponding set type values.
/// </summary>
template <typename T>
using VariableMap = std::unordered_map<std::string, T>;

#endif // TYPES_H
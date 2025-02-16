#ifndef CALCULATORCOREAPI_H
#define CALCULATORCOREAPI_H

#if defined (_WIN32)
#if defined (CALCULATORCORE_EXPORT)
#define CALCULATORCORE_API __declspec(dllexport)
#else
#define CALCULATORCORE_API __declspec(dllimport)
#endif // CALCULATORCORE_API
#define _sprintf sprintf_s
#endif

#if defined (__GNUC__)
// GCC
#define CALCULATORCORE_API __attribute__((visibility("default")))
#endif

#endif // CALCULATORCOREAPI_H
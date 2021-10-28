#pragma once
#include "Common.h"

#ifndef DLLEXPORT
#define DLLEXPORT __declspec(dllexport)
#endif // !DLLEXPORT

// Define ================================================

// Define End ============================================

#define NOROOT 0
#define DOUBLEROOT 1
#define DIFFERENTROOT 2

// Structure =============================================

// Structure End =========================================

// Functions =============================================
#ifdef __cplusplus
extern "C" {
#endif

// Quadratic Equation ===================================
	DLLEXPORT void quadratic_equation_DIFF(double secondCoeff, double firstCoeff, double discriminant_value, double& result_frist, double& result_second);

	DLLEXPORT double quadratic_equation_DOUBLE(double secondCoeff, double firstCoeff, double constant);

	DLLEXPORT double discriminant(double secondCoeff, double firstCoeff, double constant, int& DISCRI);

// Trigonometric Functions ======================================
	DLLEXPORT double ARCTAN(double value);

	DLLEXPORT double ARCCOS(double value);

	DLLEXPORT double ARCSIN(double value);

	DLLEXPORT double ARCSEC(double value);

	DLLEXPORT double ARCCSC(double value);

	DLLEXPORT double ARCOT(double value);

	DLLEXPORT double SIN(double value);

	DLLEXPORT double COS(double value);

	DLLEXPORT double TAN(double value);

	DLLEXPORT double SEC(double value);

	DLLEXPORT double CSC(double value);

	DLLEXPORT double COT(double value);

	DLLEXPORT double CVT_RAD2DEG(double value);

	DLLEXPORT double CVT_DEG2RAG(double value);

#ifdef __cplusplus
}
#endif
// Functions End =========================================
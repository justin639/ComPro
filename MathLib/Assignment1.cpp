#include "pch.h"
#include "math.h"
#include "Assignment1.h"

// Functions =============================================

// Quadratic Equation ===================================
// Two different roots
void quadratic_equation_DIFF(double secondCoeff, double firstCoeff, double discriminant_value, double& result_frist, double& result_second){
    result_frist = (-firstCoeff - sqrt(discriminant_value))/(2*secondCoeff);
    result_second = (-firstCoeff + sqrt(discriminant_value))/(2*secondCoeff);
    return;
}
// Double root 
double quadratic_equation_DOUBLE(double secondCoeff, double firstCoeff, double constant){
    double result = 0.0;
    result = (-firstCoeff)/(2*secondCoeff);
    return result;
}
// Discriminant
double discriminant(double secondCoeff, double firstCoeff, double constant, int& DISCRI){
    double result = firstCoeff*firstCoeff - 4*secondCoeff*constant;

    if(result < 0.0)
        DISCRI = NOROOT;
    else if(result > 0.0)
        DISCRI = DIFFERENTROOT;
    else
        DISCRI = DOUBLEROOT;
    return result;
}

// Trigonometric Functions ======================================

// #1
double SIN(double value){
    return sin(value);
}
// #2
double COS(double value){
    return cos(value);
}
// #3
double TAN(double value){
    return tan(value);
}
// #5
double SEC(double value){
    return 1/cos(value);
}
// #4
double CSC(double value){
    return 1/sin(value);
}
// #6
double COT(double value){
    return 1/tan(value);
}
// #7
double ARCSIN(double value){
    return asin(value);
}
// #8
double ARCCOS(double value){
    return acos(value);
}
// #9
double ARCTAN(double value){
    return atan(value);
}
// #10
double ARCCSC(double value){
    return asin(1/value);
}
// #11
double ARCSEC(double value){
    return acos(1/value);
}
// #12
double ARCOT(double value){
    return atan(1/value);
}

double CVT_RAD2DEG(double value){
    return value * 180 / PI;
}

double CVT_DEG2RAG(double value){
    return value * PI / 180;
}

// Functions End =========================================
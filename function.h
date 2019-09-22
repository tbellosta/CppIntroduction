// header guard avoids multiple definitions of
// the same function
#ifndef HEADER_GUARD_FUNCTION
#define HEADER_GUARD_FUNCTION

#include <iostream>
#include "vettore.h"

int absVal(const int &value);

float absVal(const float& value);

double absVal(const double& value);

double norm(const double& value);
double norm(const vettore& value);


/**
 * template function for computing the absolute value of a number (int/float/double).
 * Unlike normal functions, template functions must be defined in the header file (.h).
 * This is because it is just a template that is specialized at compile time, i.e. when in the main.cpp file
 * I'm calling function absVal<int>(-15), the compiler is generating the right function by replacing the parameter T
 * with int. Therefore, as long as the internal operations remain the same, the use of template functions can relieve us
 * from defining one function for each datatype as we did before.
 */
template<typename T>
T absVal(const T& value){

    std::cout << "template abs function" << std::endl;

    if(value >= 0) return value;
    else return -value;
}

#endif //HEADER_GUARD_FUNCTION

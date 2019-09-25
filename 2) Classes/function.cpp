#include <cmath>
#include "function.h"

int absVal(const int &value){

    std::cout << "abs function for int type" << std::endl;

    if (value >= 0) return value;
    else return -value;
}

float absVal(const float &value) {

    std::cout << "abs function for float type" << std::endl;

    if (value >= 0) return value;
    else return -value;

}

double absVal(const double &value) {

    std::cout << "abs function for double type" << std::endl;

    if (value >= 0) return value;
    else return -value;

}

double norm(const vettore &vett){

    double norm = 0;
    for (int i = 0; i < vett.getDimension(); ++i) {
        norm += vett[i] * vett[i];
    }
    norm = sqrt(norm);

    return norm;

}

double norm(const double &value) {

    return absVal(value);

}

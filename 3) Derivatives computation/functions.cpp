//============================================================
//
//      Type:        CppIntroduction implementation file
//
//      Author:      Tommaso Bellosta on 24/09/2019.
//                   Dipartimento di Scienze e Tecnologie Aerospaziali
//                   Politecnico di Milano
//                   Via La Masa 34, 20156 Milano, ITALY
//                   e-mail: tommaso.bellosta@polimi.it
//
//      Copyright:   2019, Tommaso Bellosta and the CppIntroduction contributors.
//                   This software is distributed under the MIT license, see LICENSE.txt
//
//============================================================
#include <cmath>

#include "functions.h"

double testFunction(double x){

    double out;

    out = (sin(2*x) + cos(x/2)) / (x+1);

    return out;

}

double dTestFunction(double x){

    double out;

    out = ((2*cos(2*x) - 0.5*sin(x/2))*(x+1) - (sin(2*x) + cos(x/2)) ) / ((x+1) * (x+1));

    return out;

}
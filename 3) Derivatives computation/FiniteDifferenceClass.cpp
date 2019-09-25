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

#include "FiniteDifferenceClass.h"

FiniteDifferenceClass::FiniteDifferenceClass(Grid* mesh){

    this->mesh = mesh;

}

FiniteDifferenceClass::FiniteDifferenceClass() {

    this->mesh = nullptr;

}

void FiniteDifferenceClass::assignGridPointer(Grid *mesh) {

    this->mesh = mesh;

}


double FiniteDifferenceClass::computeDerivative(int index, double(*fun)(double)){

    double x_ip1;
    double x_i;
    double h;

    if(index == this->mesh->nodes.size() - 1){

        x_i = this->mesh->nodes[index];
        x_ip1 = this->mesh->nodes[index] + this->mesh->getCellSize(index - 1);
        h = this->mesh->getCellSize(index - 1);
    }
    else {

        x_ip1 = this->mesh->nodes[index + 1];
        x_i = this->mesh->nodes[index];
        h = this->mesh->getCellSize(index);
    }

    double out = (fun(x_ip1) - fun(x_i)) / h;

    return out;

}


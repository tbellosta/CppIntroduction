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
#include <iostream>

#include "FiniteDifferenceClass.h"

//FiniteDifferenceClass::FiniteDifferenceClass(Grid* meshPtr){
//
//    this->mesh = meshPtr;
//
//}

FiniteDifferenceClass::FiniteDifferenceClass() {

    this->mesh = nullptr;

}

void FiniteDifferenceClass::assignGridPointer(Grid *mesh) {

    this->mesh = mesh;

}


//=================== CenteredFiniteDifferenceClass ===============

double CenteredFiniteDifferenceClass::computeDerivative(int index, double(*fun)(double)){

    double x_ip1;
    double x_im1;
    double h;
    double out;


    if(index == 0){

        x_ip1 = this->mesh->nodes[index + 1];
        h = this->mesh->getCellSize(index);
        x_im1 = this->mesh->nodes[index] - h;

    }
    else if(index == this->mesh->nodes.size() - 1){

        x_im1 = this->mesh->nodes[index - 1];
        h = this->mesh->getCellSize(index - 1);
        x_ip1 = this->mesh->nodes[index] + h;
    }
    else {
        x_ip1 = this->mesh->nodes[index + 1];
        x_im1 = this->mesh->nodes[index - 1];
        h = this->mesh->getCellSize(index);
    }


    out = (fun(x_ip1) - fun(x_im1)) / (2 * h);

    return out;

}

CenteredFiniteDifferenceClass::CenteredFiniteDifferenceClass(Grid *mesh){

    this->mesh = mesh;

}

//=================== ForwardFiniteDifferenceClass ===============

ForwardFiniteDifferenceClass::ForwardFiniteDifferenceClass(Grid *mesh){

    this->mesh = mesh;

}

double ForwardFiniteDifferenceClass::computeDerivative(int index, double(*fun)(double)){

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

//=================== FDSolver ===============

FDSolver::FDSolver(FDType finiteDiffType) {

    this->setFDType(finiteDiffType);

}

void FDSolver::setFDType(FDType type) {

    switch (type){
        case FDType::FORWARD :
            this->numericalMethod = new ForwardFiniteDifferenceClass;
            break;
        case FDType::CENTERED :
            this->numericalMethod = new CenteredFiniteDifferenceClass;
            break;
        default :
            // print warning
            this->numericalMethod = nullptr;
    }
}

FDSolver::FDSolver() {
    this->numericalMethod = nullptr;
}

FDSolver::~FDSolver() {
    delete this->numericalMethod;
}

std::vector<double> FDSolver::comuputeDerivative(Grid &grid, double (*fun)(double)) {

    std::vector<double> derivative(grid.nodes.size());

    this->numericalMethod->assignGridPointer(&grid);

    for (int i = 0; i < grid.nodes.size(); ++i) {
        derivative[i] = this->numericalMethod->computeDerivative(i, fun);
    }

    return derivative;
}

double
FDSolver::comuputeL2Norm(const std::vector<double> &numericalDeriv, Grid &grid, double (*fun)(double)) {

    double L2 = 0;

    double dx = grid.getCellSize(0);
    double exactDerivative;

    for (int i = 0; i < numericalDeriv.size(); ++i) {
        exactDerivative = fun(grid.nodes[i]);
        L2 += (numericalDeriv[i] - exactDerivative) * (numericalDeriv[i] - exactDerivative) * dx;
    }
    L2 = sqrt(L2);

    return L2;

}

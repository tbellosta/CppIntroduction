#include "Solver.h"

Solver::Solver(FiniteDifferenceMethods* ptrMethod){

  this -> setNumericalMethod(ptrMethod);

}

void Solver::setNumericalMethod(FiniteDifferenceMethods *ptrMethod) {

    this -> numericalMethod = ptrMethod;

}

void Solver::setInitialCondition(Solution& u_0){

  this -> currentSolution.u = u_0.u; // così perchè non ho definito = fra oggetti di tipo Solution

}

void Solver::evolveSolution(double finalTime, double dt, double charSpeed, Grid* mesh){

  this -> numericalMethod -> setGridPointer(mesh);

  /* ciclo sul tempo chiamando computeSolution a ogni istante e
   la salvo in currentSolution */


}

Solution Solver::getSolution() {

  return this->currentSolution;

}


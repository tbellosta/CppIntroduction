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

void Solver::setBoundaryCondition(double &lBC) {
    this -> leftBC = lBC;
}

void Solver::evolveSolution(double finalTime, double dt, double charSpeed, Grid* mesh){

  this -> numericalMethod -> setGridPointer(mesh);


  /* charSpeed, dt, u_n, boundaryCondition
  */
  double time;
  time = 0;
  Solution u_np1;

  while(time < finalTime){
      if(time + dt > finalTime) dt = finalTime - time;
      u_np1 = this-> numericalMethod -> computeSolution(currentSolution, dt, charSpeed, leftBC);
      this -> currentSolution.u = u_np1.u;
      // currentSolution = this -> numericalMethod ..
      time += dt;
  }

  /* ciclo sul tempo chiamando computeSolution a ogni istante e
   la salvo in currentSolution */


}

Solution Solver::getSolution() {

  return this->currentSolution;

}


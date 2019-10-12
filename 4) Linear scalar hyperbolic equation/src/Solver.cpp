#include <iostream>
#include "Solver.h"

Solver::Solver(){

    this->numericalMethod = nullptr;
    this->outputLevel = VerbosityLevel::SILENT;

}

Solver::Solver(FiniteDifferenceMethods* ptrMethod){

    this -> setNumericalMethod(ptrMethod);

    this->outputLevel = VerbosityLevel ::SILENT;

}

void Solver::setNumericalMethod(FiniteDifferenceMethods *ptrMethod) {

    this -> numericalMethod = ptrMethod;

}

void Solver::setInitialCondition(Solution& u_0){

    this -> currentSolution.u = u_0.u;

}

void Solver::evolveSolution(double finalTime, double dt, double charSpeed, Grid* mesh){

    this -> numericalMethod -> setGridPointer(mesh);


    /* charSpeed, dt, u_n, boundaryCondition
    */
    double time;
    int iter;
    Solution u_np1;

    time = 0;
    iter = 0;

    while(time < finalTime){

        if(time + dt > finalTime) dt = finalTime - time;

        u_np1 = this-> numericalMethod -> computeSolution(currentSolution, dt, charSpeed);
        this -> currentSolution.u = u_np1.u;

        time += dt;
        ++iter;

        if(this->outputLevel == VerbosityLevel::VERBOSE)
            std::cout << "Iteration # " << iter << "\tTime " << time << std::endl;


  }


}

Solution Solver::getSolution() {

    return this->currentSolution;

}

void Solver::setVerbosity(const VerbosityLevel &lvl) {

    this->outputLevel = lvl;

}


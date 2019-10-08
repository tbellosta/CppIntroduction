#ifndef CPPINTRODUCTION_SOLVER_H
#define CPPINTRODUCTION_SOLVER_H

#include "numerics.h"

class Solver{

  FiniteDifferenceMethods* numericalMethod;
  Solution currentSolution;
  double leftBC;

public:

  Solver() {};
  Solver(FiniteDifferenceMethods* ptrMethod);

  void setInitialCondition(Solution& u_0);
  void setBoundaryCondition(double& leftBC);
  void setNumericalMethod(FiniteDifferenceMethods* method);

  void evolveSolution(double finalTime, double dt, double charSpeed, Grid* mesh);

  Solution getSolution();
};

#endif //CPPINTRODUCTION_SOLVER_H

#ifndef CPPINTRODUCTION_SOLVER_H
#define CPPINTRODUCTION_SOLVER_H

#include "numerics.h"

class Solver{

  FiniteDifferenceMethods* numericalMethod;
  Solution currentSolution;

public:

  Solver() {};
  Solver(FiniteDifferenceMethods* ptrMethod);

  void setInitialCondition(Solution& u_0);
  void setNumericalMethod(FiniteDifferenceMethods* method);

  void evolveSolution(double finalTime, double dt, double charSpeed, Grid* mesh);

  Solution getSolution();
};

#endif //CPPINTRODUCTION_SOLVER_H

#ifndef CPPINTRODUCTION_SOLVER_H
#define CPPINTRODUCTION_SOLVER_H

#include "Numerics.h"


class Solver{

  FiniteDifferenceMethods* numericalMethod;
  Solution currentSolution;
  VerbosityLevel outputLevel;

public:

  Solver();
  Solver(FiniteDifferenceMethods* ptrMethod);

  /**
   * Sets the verbosity of the output messages.
   * Input options are:
   *                    VerbosityLevel::SILENT
   *                    VerbosityLevel::VERBOSE
   */
  void setVerbosity(const VerbosityLevel&);

  /**
   * sets initial condition
   * @param u_0 initial condition
   */
  void setInitialCondition(Solution& u_0);

  /**
   * sets the numerical scheme used in Solver::evolveSolution()
   * @param method: address of child of FiniteDifferenceMethod
   */
  void setNumericalMethod(FiniteDifferenceMethods* method);

  /**
   * Compute solution till final time
   * @param finalTime     final time
   * @param dt            time step
   * @param charSpeed     characteristic speed of advection
   * @param mesh
   */
  void evolveSolution(double finalTime, double dt, double charSpeed, Grid* mesh);

  Solution getSolution();
};

#endif //CPPINTRODUCTION_SOLVER_H

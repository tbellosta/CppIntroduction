#ifndef CPPINTRODUCTION_NUMERICS_H
#define CPPINTRODUCTION_NUMERICS_H

#include "Grid.h"

class Solution{
public:

  std::vector<double> u;

  Solution() {};

  void resizeSolution(const int&);

  Solution& operator=(const Solution& rhs);

};

class FiniteDifferenceMethods{
protected:

  Grid* mesh;

public:

  FiniteDifferenceMethods();

  /**
   * Sets the Grid* of the class
   * @param gridPtr pointer to Grid object
   */
  void setGridPointer(Grid* gridPtr);

  /**
   * Computes the solution at time n+1 from a solution at time n
   * @param u_n         Solution at time n
   * @param charSpeed   Characteristic speed of linear equation
   * @param dt          Integration time
   *
   * @return u_np1      Solution at next time step
   */
  virtual Solution computeSolution(Solution& u_n, double charSpeed, double dt) = 0;

};

class ForwardEuler : public FiniteDifferenceMethods{
public:

  ForwardEuler();
  ForwardEuler(Grid* gridPtr);

  Solution computeSolution(Solution& u_n, double charSpeed, double dt);

};

class LaxWendroff : public FiniteDifferenceMethods{
public:

  LaxWendroff();
  LaxWendroff(Grid* gridPtr);

  Solution computeSolution(Solution& u_n, double charSpeed, double dt);

};

class LaxFriedrichs : public FiniteDifferenceMethods{
public:

    LaxFriedrichs();
    LaxFriedrichs(Grid* gridPtr);

    Solution computeSolution(Solution& u_n, double charSpeed, double dt);

};

class UpwindLeft : public FiniteDifferenceMethods{
public:

    UpwindLeft();
    UpwindLeft(Grid* gridPtr);

    Solution computeSolution(Solution& u_n, double charSpeed, double dt);

};

/**
 * Enum for the level of verbosity
 */
enum class VerbosityLevel {SILENT, VERBOSE};



#endif //CPPINTRODUCTION_NUMERICS_H

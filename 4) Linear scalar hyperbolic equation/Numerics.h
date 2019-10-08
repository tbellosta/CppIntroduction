#ifndef CPPINTRODUCTION_NUMERICS_H
#define CPPINTRODUCTION_NUMERICS_H

#include "Grid.h"

class Solution{
public:

  std::vector<double> u;

  Solution() {};

};

class FiniteDifferenceMethods{
protected:

  Grid* mesh; /* puntatore perchè voglio usare QUELLA mesh,
              per usare un oggetto ne uso un puntatore */

public:

  FiniteDifferenceMethods();
  FiniteDifferenceMethods(Grid* mesh);

  void setGridPointer(Grid* mesh); // associo la mesh in termini di puntatore

  virtual Solution computeSolution(Solution& u_n, double charSpeed, double dt, double leftBC) = 0; // calcolo soluzione a tn + 1

};

class ForwardEuler : public FiniteDifferenceMethods{
public:

  ForwardEuler();
  ForwardEuler(Grid* mesh);

  Solution computeSolution(Solution& u_n, double charSpeed, double dt, double leftBC);

};

class LaxWendroff : public FiniteDifferenceMethods{
public:

  LaxWendroff();
  LaxWendroff(Grid* mesh);

  Solution computeSolution(Solution& u_n, double charSpeed, double dt, double leftBC);

};



#endif //CPPINTRODUCTION_NUMERICS_H

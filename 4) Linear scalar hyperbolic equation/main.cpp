#include "Solver.h"

int main(){

    // mesh variables
    double x0, xf, nPoints;
    Grid mesh;

    // numerical method
    ForwardEuler method;

    // solver variables
    double dt, charSpeed, tf;
    Solution u0;
    Solver explicitSolver;

    // initialize mesh variables
    // x0 = ...
    mesh.buildUniformGrid(x0, xf, nPoints);

    // initialize solver variables
    // charSpeed = ...
    // dt = ??? stability?
    // u0 = ...
    explicitSolver.setNumericalMethod(&method);
    explicitSolver.setInitialCondition(u0);

    // evolve equation till final time
    explicitSolver.evolveSolution(tf, dt, charSpeed, &mesh);

    // get solution at tf
    Solution finalSolution = explicitSolver.getSolution(); // ho a disposizione la soluzione


}

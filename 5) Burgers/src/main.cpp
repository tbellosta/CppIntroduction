#include <iostream>
#include "Solver.h"

int main(){

    double x0, xf, CFL;
    int nPoints;

    Grid mesh;

    InvBurgers govEq;
    RoeFlux fluxType;

    Solver godunovSolver;

    Solution u0(&mesh);

    // ...


}

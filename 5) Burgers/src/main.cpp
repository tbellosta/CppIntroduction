#include <iostream>
#include "Solver.h"
#include "GnuplotDriver.h"

int main(){

    double x0, xf, CFL, uL, uR, tf;
    int nPoints;

    Grid mesh;

    x0 = 0;
    xf = 5;
    nPoints = 500;

    mesh.buildUniformGrid(x0, xf, nPoints);

    InvBurgers govEq;
    RoeFlux fluxType;

    Solver godunovSolver;

    Solution u0(&mesh);

    uL = -1;
    uR = 4;

    for (int i = 0; i < nPoints; ++i) {
        u0.u[i] = (mesh.nodes[i] < 2) ? uL : uR;


    }

    CFL = 0.9;

    godunovSolver.setGridPointer(&mesh);
    godunovSolver.setInitalCondition(u0);
    godunovSolver.setGoverningEquation(&govEq);
    godunovSolver.setFluxType(&fluxType);
    godunovSolver.setCFL(CFL);

    tf = 2.0;

    godunovSolver.computeSolution(tf);

    Solution uF = godunovSolver.getSolution();

    GnuplotDriver driver(GNUPLOT_VIDEO);
    driver.playAnimation(mesh.nodes, 0.0001);

//    Solution sol = godunovSolver.getSolution();
//    for (int j = 0; j < nPoints; ++j) {
//        std::cout << sol.u[j] << std::endl;
//    }


    // ...


}

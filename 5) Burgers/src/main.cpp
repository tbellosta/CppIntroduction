#include <iostream>
#include "Solver.h"
#include "GnuplotDriver.h"

int main(){

    double x0, xf, CFL, uL, uR, tf, xJump;
    int nPoints;

    bool plotVideo = true;

    Grid mesh;

    x0 = 0;
    xf = 5;
    nPoints = 100;

    mesh.buildUniformGrid(x0, xf, nPoints);

    InvBurgers govEq;

//    RoeFlux     fluxTypeR;
//    GodunovFlux fluxTypeG;
//    UHRFlux fluxTypeE;

    std::vector<NumericalFlux*> fluxes(3);
    fluxes[0] = new RoeFlux;
    fluxes[1] = new GodunovFlux;
    fluxes[2] = new UHRFlux;



//    VanLeer limiter;
    MinMod limiter;

    Solver godunovSolver;

    Solution u0(&mesh);

    uL = 1;
    uR = 0;
    xJump = 2.5;

    for (int i = 0; i < nPoints; ++i) {
        u0.u[i] = (mesh.nodes[i] < xJump) ? uL : uR;
    }

    CFL = 0.9;
    tf = 2.5;

    godunovSolver.setGridPointer(&mesh);
    godunovSolver.setInitalCondition(u0);
    godunovSolver.setGoverningEquation(&govEq);
    godunovSolver.setCFL(CFL);

    godunovSolver.setPlotSolution(false);
    godunovSolver.setNFrames(3);
//    godunovSolver.displayExactSolution(true, xJump);

    std::vector<Solution> sols(fluxes.size());

    for (int j = 0; j < fluxes.size(); ++j) {

        godunovSolver.setFluxType(fluxes[j]);
        godunovSolver.setLimiter(&limiter);
        godunovSolver.setInitalCondition(u0);

        godunovSolver.computeSolution(tf);

        sols[j] = godunovSolver.getSolution();
    }




//    Solution uF = godunovSolver.getSolution();

//    if (plotVideo) {
//        GnuplotDriver driverV(GNUPLOT_VIDEO);
//        driverV.playAnimation(mesh.nodes, 0.001);
//    }

//    std::vector<string> leg = {"ROE", "UHR"};
    std::vector<string> leg = {"ROE", "EXACT_RIEMANN", "UHR"};
    GnuplotDriver driver(GNUPLOT_PLOT);
    driver.setLegendTitles(leg);
    driver.plot(mesh.nodes, sols[0].u, mesh.nodes, sols[1].u, mesh.nodes, sols[2].u);
//    driver.plot(mesh.nodes, sols[0].u, mesh.nodes, sols[1].u);



//    Solution sol = godunovSolver.getSolution();
//    for (int j = 0; j < nPoints; ++j) {
//        std::cout << sol.u[j] << std::endl;
//    }


    // ...


}

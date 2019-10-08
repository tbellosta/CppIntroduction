#include "Solver.h"
#include <ostream>
#include <iostream>
#include <fstream>

// Martedi B2 2.2
// Mercoledi B2 1.11

int main(){

    // mesh variables
    double x0, xf, nPoints;
    Grid mesh;

    // numerical method
    LaxWendroff method;

    // solver variables
    double dt, charSpeed, tf, CFL, dx, leftBC;
    Solution u0;
    Solver explicitSolver;

    // initialize mesh variables
    x0 = 0;
    xf = 5;
    nPoints = 1000;
    mesh.buildUniformGrid(x0, xf, nPoints);

    // initialize solver variables
    charSpeed = 1;
    CFL = 0.8;
    dx = mesh.getCellSize(0);
    // CFL = lambda * dt / dx =>  dt = dx * CFL / lambda
    dt = dx * CFL / charSpeed;
    leftBC = 0;
    tf = 1;
    u0.u.resize(mesh.nodes.size());
    for(int i = 0; i < nPoints; i++){
        if(mesh.nodes[i] < 3 || mesh.nodes[i] > 4) u0.u[i] = 0;
        else u0.u[i] = 1;
    }

    explicitSolver.setNumericalMethod(&method);
    explicitSolver.setInitialCondition(u0);
    explicitSolver.setBoundaryCondition(leftBC);

    // evolve equation till final time
    explicitSolver.evolveSolution(tf, dt, charSpeed, &mesh);

    // get solution at tf
    Solution finalSolution = explicitSolver.getSolution();

    std::ofstream outputFile;
    outputFile.open("data.txt");
    for(int i = 0; i < nPoints; i++){
        outputFile << mesh.nodes[i] << "\t" << finalSolution.u[i] << "\n";
    }

    outputFile.close();




}


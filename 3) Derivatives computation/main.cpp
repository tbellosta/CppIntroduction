//============================================================
//
//      Type:        CppIntroduction main file
//
//      Author:      Tommaso Bellosta on 24/09/2019.
//                   Dipartimento di Scienze e Tecnologie Aerospaziali
//                   Politecnico di Milano
//                   Via La Masa 34, 20156 Milano, ITALY
//                   e-mail: tommaso.bellosta@polimi.it
//
//      Copyright:   2019, Tommaso Bellosta and the CppIntroduction contributors.
//                   This software is distributed under the MIT license, see LICENSE.txt
//
//============================================================
#include <cmath>
#include <iostream>
#include <ostream>
#include <fstream>

#include "Grid.h"
#include "FiniteDifferenceClass.h"
#include "functions.h"


int main(){

    std::vector<int> gridNodes = {10, 100, 1000, 10000, 100000};                // initialize vector of grid sizes
    std::vector<double> L2vector;                                               // declare vector to store L2 error


    std::vector<double> derivative;                                             // declare vector to store FD derivatives
    Grid mesh;                                                                  // declare mesh

    FDType FiniteDifferenceScheme = FDType::FORWARD;


    for (int h = 0; h < gridNodes.size(); ++h) {

        double x0 = 1.0;
        double xf = 5.0;
        int nPoints = gridNodes[h];

        mesh.buildUniformGrid(x0, xf, nPoints);                                 // discretize [1, 5] w/ 1000 points

        FDSolver solver(FiniteDifferenceScheme);                                // initialize solver class

        derivative = solver.computeDerivative(mesh, testFunction);             // compute the FD derivative

        double L2Err = solver.computeL2Norm(derivative, mesh, dTestFunction);  // compute L2 error

        std::cout << "ERROR: " << L2Err << std::endl;                           // print L2 error

        L2vector.push_back(L2Err);                                              // add error to vector
    }


    // print result to file for plotting convergence rate with gnuplot
    std::ofstream file;

    file.open("data.txt");

    for (int h = 0; h < gridNodes.size(); ++h) {

        // first column : number of points (x axis)
        // second column: ~h
        // third column : ~h^2
        // fourth column: L2 error
        file << gridNodes[h] << " " << 1.00/((long)gridNodes[h]) << " " << 1.00/((long)gridNodes[h] * (long)gridNodes[h]) << " " << L2vector[h] << std::endl;

    }

    file.close();

}

/*
// Same code as above, just different style (provare oer credere)
//
int main(){

    double x0, xf, L2Err;  // define all variables of type double
    int nPoints;           // define all variables of type int

    Grid mesh;                            // define Grid object

    FiniteDifferenceClass deriv;          // define FiniteDifferenceClass object

    std::vector<double> derivative;       // define vector to store FD derivatives
    std::vector<double> exactDerivative;  // define vector to store exact derivatives

        // initialize grid related variables
        x0 = 1.0;
        xf = 5.0;
        nPoints = 1000;

        // build the grid
        mesh.buildUniformGrid(x0, xf, nPoints);

        // assign the grid to the FiniteDifferenceClass object
        deriv.assignGridPointer(&mesh);

        // initialize the size for the vectors in which we want to store the numerical and exact derivatives
        derivative.resize(mesh.nodes.size());
        exactDerivative.resize(mesh.nodes.size());

        // initialize L2 norm
        L2Err = 0.0;



        // compute L2 error,
        // the numerical derivative at node i of function f is computed as:
        //      derivative[i] = deriv.computeDerivative(i, f);

        std::cout << "ERROR: " << L2Err << std::endl;

}
*/


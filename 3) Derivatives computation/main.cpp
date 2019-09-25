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
#include "Grid.h"
#include "FiniteDifferenceClass.h"
#include "functions.h"

int main(){

    double x0   = 1.0;
    double xf   = 5.0;
    int nPoints = 1000;

    Grid mesh(x0, xf, nPoints);                              // discretize [1, 5] w/ 1000 points

    FiniteDifferenceClass deriv(&mesh);                      // initialize object to compute FD derivatives

    std::vector<double> derivative(mesh.nodes.size());       // initialize vector to store FD derivatives
    std::vector<double> exactDerivative(mesh.nodes.size());  // initialize vector to store exact derivatives

    double L2Err = 0;                                        // initialize variable to store L2 norm of the error


    // compute L2 error,
    // the numerical derivative at node i of function f is computed as:
    //      derivative[i] = deriv.computeDerivative(i, f);

    std::cout << "ERROR: " << L2Err << std::endl;

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


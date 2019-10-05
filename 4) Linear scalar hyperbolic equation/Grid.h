//============================================================
//
//      Type:        CppIntroduction include file
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
#ifndef CPPINTRODUCTION_GRID_H
#define CPPINTRODUCTION_GRID_H

#include <vector>

/**
 * Structure for a one dimensional grid with implicit connectivity:
 *
 *  nodes index     0     1     2          i-1    i    i+1   i+2         f-2   f-1    f
 *                  o --- o --- o   . . .   o --- o --- o --- o   . . .   o --- o --- o
 *  cells index        0     1                i-1    i    i+1               f-2   f-1
 */
class Grid {

public:
    std::vector<double> nodes;

    /**
     * Constructors can be designed to comply with the chosen coding style.
     * The first constructor can be used to split the declaration with the assignment of an object/variable (i.e. Guardone style):
     *      int nNodes;
     *      Grid mesh;         // calls first constructor Grid()
     *
     *          nNodes = 1000;
     *          mesh.buildUniformGrid(1.0, 5.0, nNodes);
     *
     * The second can be used to fuse together the declaration and assignement operations (i.e. Tommaso style):
     *      int nNodes = 1000;
     *      Grid mesh(1.0, 5.0, nNodes);    // calls second constructor Grid(const double &x0, const double &xf, const int &nNodes)
     *
     * The two codes perform the same exact operations, check the code.
     */
    Grid();  // empty grid, doesn't do anything (field nodes is empty after initialization)
    Grid(const double &x0, const double &xf, const int &nNodes); // initializes uniform grid

    // builds a uniform grid, needs to be called iff object was created w/ the first constructor (Guardone style)
    void buildUniformGrid(const double &x0, const double &xf, const int &nNodes);

    // return cell size
    double getCellSize(int i);

};


#endif //CPPINTRODUCTION_GRID_H

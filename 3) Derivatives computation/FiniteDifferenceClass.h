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
#ifndef CPPINTRODUCTION_FINITEDIFFERENCECLASS_H
#define CPPINTRODUCTION_FINITEDIFFERENCECLASS_H

#include "Grid.h"

class FiniteDifferenceClass {
    Grid* mesh;
public:

    /**
     * As in class Grid, two constructors to comply w/ two different coding styles.
     * Check comment in Grid.h file
     */
    FiniteDifferenceClass();              // empty constructor, method assignGridPointer mush be called afterwards
    FiniteDifferenceClass(Grid* mesh);    // "full" constructor, already links the mesh

    void assignGridPointer(Grid* mesh);   // links the mesh iff object was initialized with the empty constructor

    double computeDerivative(int index, double(*fun)(double));  // computes the derivative at node index of function fun


};

#endif //CPPINTRODUCTION_FINITEDIFFERENCECLASS_H

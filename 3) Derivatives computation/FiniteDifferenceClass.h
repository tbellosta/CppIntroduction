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

enum class FDType {UNKNOWN, FORWARD, CENTERED};


/**
 * Interface class for different FD schemes
 */
class FiniteDifferenceClass {

protected:
    Grid* mesh;

public:

//    Grid* mesh;

    FiniteDifferenceClass();
    virtual ~FiniteDifferenceClass() {};

    // links the mesh iff object was initialized with the empty constructor
    void assignGridPointer(Grid *mesh);

    // computes the derivative at node index of function fun
    virtual double computeDerivative(int index, double(*fun)(double)) = 0;
};



class CenteredFiniteDifferenceClass : public FiniteDifferenceClass{

public:

    /**
         * As in class Grid, two constructors to comply w/ two different coding styles.
         * Check comment in Grid.h file
         */
    // empty constructor, method assignGridPointer mush be called afterwards
    CenteredFiniteDifferenceClass() {};
    CenteredFiniteDifferenceClass(Grid *mesh);

    double computeDerivative(int index, double(*fun)(double));


};

class ForwardFiniteDifferenceClass : public FiniteDifferenceClass{

public:

    ForwardFiniteDifferenceClass(){};
    ForwardFiniteDifferenceClass(Grid *mesh);

    double computeDerivative(int index, double(*fun)(double));


};


class FDSolver {

private:

    FiniteDifferenceClass* numericalMethod;

public:

    FDSolver();
    FDSolver(FDType finiteDiffType);
    ~FDSolver();

    void setFDType(FDType type);

    std::vector<double> computeDerivative(Grid &grid, double(*fun)(double));
    double computeL2Norm(const std::vector<double> &numericalDeiv, Grid &grid, double(*fun)(double));
};

#endif //CPPINTRODUCTION_FINITEDIFFERENCECLASS_H

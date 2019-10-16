//============================================================
#ifndef CPPINTRODUCTION_SOLVER_H
#define CPPINTRODUCTION_SOLVER_H

#include "GoverningEquation.h"

class Solver{
    // puntatore alla griglia //
    Grid* ptrMesh;

    //soluzione al tempo corrente//
    Solution u_n;

    //valore di CFL//
    double CFL;


    //funzione che mi calcola dt noto CFL e la soluzione corrente//

    double computeDt();

public:

    Solver();
    Solver(Grid* addressMesh);


    //metodo che iniziaizza il puntatore a grid//
    void setGridPointer(Grid* addressMesh);

    void setInitalCondition(Solution u0);

    void setCFL(double cfl);


    //per la funzione serve un delta t, definizione dei flussi numerici//
    void computeSolution();

};




#endif //CPPINTRODUCTION_SOLVER_H
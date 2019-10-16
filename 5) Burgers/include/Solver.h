//============================================================
#ifndef CPPINTRODUCTION_SOLVER_H
#define CPPINTRODUCTION_SOLVER_H

#include "NumericalFlux.h"

class Solver{

    Grid* ptrMesh; // puntatore alla griglia

    Solution u_n; //soluzione al tempo corrente

    double CFL; //valore di CFL

    GoverningEquation* ptrGovEquation; //puntatore all'equazione di governo

    NumericalFlux* ptrFluxType; //puntatore al metodo numerico per il flusso

    //funzione che mi calcola dt noto CFL e la soluzione corrente
    double computeDt();



public:

    Solver();
    Solver(Grid* addressMesh);


    //metodo che iniziaizza il puntatore a grid
    void setGridPointer(Grid* addressMesh);
    void setGoverningEquation(GoverningEquation* addressEquation);
    void setFluxType(NumericalFlux* addressFluxType);

    void setInitalCondition(Solution u0);

    void setCFL(double cfl);


    void computeSolution(double tf);

};




#endif //CPPINTRODUCTION_SOLVER_H
//============================================================
#ifndef CPPINTRODUCTION_SOLVER_H
#define CPPINTRODUCTION_SOLVER_H

#include "NumericalFlux.h"

struct RiemannProblem{
    double x0;
    Solution ul, ur;
};

class Solver{

    Grid* ptrMesh;                          // puntatore alla griglia
    GoverningEquation* ptrGovEquation;      // puntatore all'equazione di governo
    NumericalFlux* ptrFluxType;             // puntatore al metodo numerico per il flusso

    Solution u_n;                           // soluzione al tempo corrente

    double CFL;                             // valore di CFL

    unsigned short nFrames;                 // plotta la soluzione ogni nFrames iterazioni
    bool plotSolution;

    double computeDt();                     // funzione che mi calcola dt noto CFL e la soluzione corrente

    // flux for imposing boundary conditions
    double leftBC(const Solution& uExt, const Solution& uLeft_n);
    double rightBC(const Solution& uExt, const Solution& uRight_n);

    // definition of riemann problem for plotting of exact solution
    bool exactSolutionRiemann;
    RiemannProblem riemannData;

public:

    Solver();
    Solver(Grid* addressMesh);


    //metodo che iniziaizza il puntatore a grid
    void setGridPointer(Grid* addressMesh);
    void setGoverningEquation(GoverningEquation* addressEquation);
    void setFluxType(NumericalFlux* addressFluxType);
    void setLimiter(FluxLimiter* ptrLim);

    void setInitalCondition(Solution u0);

    void setCFL(double cfl);

    void setPlotSolution(const bool& option = true);
    void setNFrames(const unsigned short& nFrames);
    void displayExactSolution(const bool &opt = true, const double &x0 = 0.0);


    void computeSolution(double tf);

    Solution getSolution() {return u_n;};

};




#endif //CPPINTRODUCTION_SOLVER_H
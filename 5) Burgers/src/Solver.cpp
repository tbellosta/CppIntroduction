#include <iostream>
#include <cmath>
#include "Solver.h"
#include "GnuplotDriver.h"


//classe solver//
Solver::Solver(){
    
    //setto il valore del puntatore non inizializzato a zero per non avere errori//
    this->ptrMesh = nullptr;
    this->ptrFluxType = nullptr;
    this->ptrGovEquation = nullptr;
    this->CFL = -1;
    this->nFrames = 10;
    this->exactSolutionRiemann = false;
    this->plotSolution = false;

    
}

Solver::Solver(Grid* addressMesh){
    
    this->ptrMesh = addressMesh;
    this->ptrFluxType = nullptr;
    this->ptrGovEquation = nullptr;
    this->CFL = -1;
    this->nFrames = 10;
    this->exactSolutionRiemann = false;
    this->plotSolution = false;
}

void Solver::setGridPointer(Grid* addressMesh){

    this->ptrMesh = addressMesh;
}

void Solver::setCFL(double cfl){
    
    this->CFL = cfl;
}

double Solver::computeDt(){
    
    double dt;
    double dx;
    std::vector<double> chSpeed;

    const double eps = 1e-8;


    //calcolo la velocita' come la derivata della funzione flusso//
    chSpeed = this->ptrGovEquation->dFlux(this->u_n);
    double dt_min = 99999;
    
    // CFL= a(u(x))dt/dx.

    for (int i = 0; i < this->ptrMesh->nodes.size(); ++i) {
        //min_dt=CFL*dx/a//

        dx = this->ptrMesh->getDualCellSize(i);
        dt = CFL  / (max(fabs(chSpeed[i])/dx, eps));

        if (dt_min > dt) dt_min = dt;

    }

    return dt_min;
    
}

double Solver::leftBC(const Solution &uExt, const Solution &uLeft_n) {


    double a;
    double fBC;

    a = this -> ptrGovEquation -> dFlux(uLeft_n)[0];

    if (a>0) fBC = this -> ptrGovEquation -> flux(uExt)[0];
    else fBC = this -> ptrGovEquation -> flux(uLeft_n)[0];

    return fBC;

}


double Solver::rightBC(const Solution &uExt, const Solution &uRight_n) {

    double a;
    double fBC;

    a = this -> ptrGovEquation -> dFlux(uRight_n)[0];

    if (a<0) fBC = this -> ptrGovEquation -> flux(uExt)[0];
    else fBC = this -> ptrGovEquation -> flux(uRight_n)[0];

    return fBC;



}

void Solver::setGoverningEquation(GoverningEquation *addressEquation) {

    this->ptrGovEquation=addressEquation;
}

void Solver::setFluxType(NumericalFlux *addressFluxType) {

    this->ptrFluxType=addressFluxType;

}

void Solver::setInitalCondition(Solution u0){

    this->u_n = u0;

}

void Solver::computeSolution(double finalTime) {

    double time=0;
    int nPoints= this-> ptrMesh->nodes.size();
    int nInterfaces= nPoints-1;
    int iter;

    GnuplotDriver driver(GNUPLOT_VIDEO);
    if(plotSolution && exactSolutionRiemann) driver.plot(this->ptrMesh->nodes, u_n.u, this->ptrMesh->nodes, u_n.u);
    else if(plotSolution) driver.plot(this->ptrMesh->nodes, u_n.u);
    iter = 0;



    //metodo di Godonov per tutti gli istanti di tempo
    while (time<finalTime){

        //calcolo il dt a CFL fissato
        double dt;
        double dx;

        dt = this->computeDt();
        dx = this->ptrMesh->getCellSize(1); // hp: uniform mesh, for LWC method

        if(time + dt > finalTime) dt = finalTime - time;


        // U_i(n+1) = U_i(n) + dt/dx * (F_l(n) - F_r(n))
        // U_i(n+1) = U_i(n) + dt/dx * Res_i(n)
        //per calcolare le diferenze dei flussi ciclo sulle facce e accumulo sui nodi

        std::vector<double> numericalFluxes;
        std::vector<double> residuals(nPoints); //Res_i(n) = (F_l(n) - F_r(n))


        //il vettore dei flussi sulle interfacce
        numericalFluxes = this->ptrFluxType->computeFluxes(this->ptrGovEquation, this->u_n, dt, dx);

        int iLeft, iRight;
        for (int i = 0; i < nInterfaces ; ++i) {

            iLeft=i;
            iRight=i+1;

            //aggiorno il valore del residuo con i flussi alle interfacce
            residuals[iRight]+= numericalFluxes[i];
            residuals[iLeft]-= numericalFluxes[i];

        }

        // +++ BOUNDARY CONDITIONS?? (fluxes from both ends of the domain)

        Solution uLeft, uRight, uExtL, uExtR;

        uLeft = this -> u_n[0];
        uRight = this -> u_n[nPoints-1];
        uExtL = uLeft;
        uExtR = uRight;

        residuals[0] += leftBC(uExtL, uLeft);
        residuals[nPoints-1] -= rightBC(uExtR, uRight);



        // U_i(n+1) = U_i(n) + dt/dx * Res_i(n)
        for (int i = 0; i < nPoints; ++i) {

            dx = this->ptrMesh->getDualCellSize(i);

            // U_i(n+1)
            u_n.u[i] = u_n.u[i] + (dt/dx) * residuals[i];

        }

        time+=dt;
        ++iter;

        if ( !(iter % this->nFrames) && plotSolution ){
            if(exactSolutionRiemann){

                double csi;
                vector<double> exactSolution(nPoints);

                for (int i = 0; i < nPoints; ++i) {
                    csi = (this->ptrMesh->nodes[i] - riemannData.x0) / time;
                    exactSolution[i] = this->ptrGovEquation->exactRiemannProblem(riemannData.ul, riemannData.ur, csi).u[0];
                }

                driver.plot(this->ptrMesh->nodes, u_n.u, this->ptrMesh->nodes, exactSolution);

            } else driver.plot(this->ptrMesh->nodes, u_n.u);
        }

        std::cout << "ITER:\t" << iter << "\tTIME:\t" << time << "\tDT:\t " << dt << std::endl;

    }

}

void Solver::setNFrames(const unsigned short &nFrames) {
    this->nFrames = nFrames;
}

void Solver::displayExactSolution(const bool &opt, const double &x0) {
    this->exactSolutionRiemann = opt;


    const int lastNodeID = (int)this->ptrMesh->nodes.size() - 1;

    this->riemannData.ul.resize(1);
    this->riemannData.ur.resize(1);

    this->riemannData.x0 = x0;
    this->riemannData.ul = this->u_n[0];
    this->riemannData.ur = this->u_n[lastNodeID];
}

void Solver::setLimiter(FluxLimiter *ptrLim) {

    // ptrFluxType must be set before calling this function
    if (this->ptrFluxType == nullptr)
        std::cout << "\n\n[ERROR] function Solver::setLimiter must be called after Solver::setFluxType\n\n" << std::endl;

    this->ptrFluxType->setLimiter(ptrLim);

}

void Solver::setPlotSolution(const bool &option) {

    this->plotSolution = option;

}










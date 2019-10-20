#include "Solver.h"


//classe solver//
Solver::Solver(){
    
    //setto il valore del puntatore non inizializzato a zero per non avere errori//
    this-> ptrMesh= nullptr;
    this-> ptrFluxType= nullptr;
    this-> ptrGovEquation= nullptr;
    this-> CFL= -1;

    
}

Solver::Solver(Grid* addressMesh){
    
    this-> ptrMesh=addressMesh;
    this-> ptrFluxType= nullptr;
    this-> ptrGovEquation= nullptr;
    this-> CFL= -1;
}

void Solver::setGridPointer(Grid* addressMesh){

    this-> ptrMesh=addressMesh;
}

void Solver::setCFL(double cfl){
    
    this-> CFL=cfl;
}

double Solver::computeDt(){
    
    double dt;
    double dx;
    std::vector<double> chSpeed;


    //calcolo la velocita' come la derivata della funzione flusso//
    chSpeed = this->ptrGovEquation->dFlux(this->u_n);
    double dt_min = 99999;
    
    // CFL= a(u(x))dt/dx.

    for (int i = 0; i < this->ptrMesh->nodes.size(); ++i) {
        //min_dt=CFL*dx/a//

        dx = this->ptrMesh->getDualCellSize(i);
        dt = CFL * dx / chSpeed[i];

        if (dt_min > dt) dt_min = dt;

    }

    return dt_min;
    
}

void Solver::setGoverningEquation(GoverningEquation *addressEquation) {

    this->ptrGovEquation=addressEquation;
}

void Solver::setFluxType(NumericalFlux *addressFluxType) {

    this->ptrFluxType=addressFluxType;

}

void Solver::setInitalCondition(Solution u0){

    this->u_n.u = u0.u;

}

void Solver::computeSolution(double finalTime) {

    double time=0;
    int nPoints= this-> ptrMesh->nodes.size();
    int nInterfaces= nPoints-1;


    //metodo di Godonov per tutti gli istanti di tempo
    while (time<finalTime){

        //calcolo il dt a CFL fissato
        double dt;
        double dx;

        dt = this->computeDt();

        if(time + dt > finalTime) dt = finalTime - time;


        // U_i(n+1) = U_i(n) + dt/dx * (F_l(n) - F_r(n))
        // U_i(n+1) = U_i(n) + dt/dx * Res_i(n)
        //per calcolare le diferenze dei flussi ciclo sulle facce e accumulo sui nodi

        std::vector<double> numericalFluxes;
        std::vector<double> residuals(nPoints); //Res_i(n) = (F_l(n) - F_r(n))



        //il vettore dei flussi sulle interfacce
        numericalFluxes = this->ptrFluxType->computeFluxes(this->ptrGovEquation,this->u_n);

        int iLeft, iRight;
        for (int i = 0; i < nInterfaces ; ++i) {

            iLeft=i;
            iRight=i+1;

            //aggiorno il valore del residuo con i flussi alle interfacce
            residuals[iRight]+= numericalFluxes[i];
            residuals[iLeft]-= numericalFluxes[i];

        }

        // +++ BOUNDARY CONDITIONS?? (fluxes from both ends of the domain)

        // U_i(n+1) = U_i(n) + dt/dx * Res_i(n)
        for (int i = 0; i < nPoints; ++i) {

            dx = this->ptrMesh->getDualCellSize(i);

            // U_i(n+1)
            u_n.u[i] = u_n.u[i] + (dt/dx) * residuals[i];

        }


        time+=dt;

    }

}










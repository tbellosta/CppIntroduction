#include "Solver.h"


//classe solver//
Solver::Solver(){
    
    //setto il valore del puntatore non inizializzato a zero per non avere errori//
    this-> ptrMesh= nullptr;
    this-> CFL= -1;
    
}

Solver::Solver(Grid* addressMesh){
    
    this-> ptrMesh=addressMesh;
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
    double chSpeed;

    dt = 99999;
    
    // CFL= a(u(x))dt/dx.

    for (int i = 0; i < this->ptrMesh->nodes.size(); ++i) {



    }
    
    
};












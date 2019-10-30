//============================================================
//
//      Type:        burgers include file
//
//      Author:      Tommaso Bellosta on 16/10/2019.
//                   Dipartimento di Scienze e Tecnologie Aerospaziali
//                   Politecnico di Milano
//                   Via La Masa 34, 20156 Milano, ITALY
//                   e-mail: tommaso.bellosta@polimi.it
//
//      Copyright:   2019, Tommaso Bellosta and the burgers contributors.
//                   This software is distributed under the MIT license, see LICENSE.txt
//
//============================================================
#include <cmath>
#include "NumericalFlux.h"
#include <iostream>

// static permette di usare questa funzione solo all'interno di questo file .cpp
// inline (da inserire fra static e int) ottimizza la velocita' della chiamata della funzione
// (non chaima la funzione, copia il corpo della funzione dove viene chiamata)

static inline int sign(const double& val) {return (val>0) - (val<0);}

void NumericalFlux::setLimiter(FluxLimiter *ptrLim) {
    this->limiter = ptrLim;
}

NumericalFlux::NumericalFlux(): limiter(nullptr) {

}

// ROE

std::vector<double> RoeFlux::computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx){
    //cosa serve: eq di governo        - GoverningEquation* ptrGov
    //            soluzione corrente   - Solution u_n

    int nPoints, nInterfaces, iLeft, iRight;

    nPoints = u_n.size();
    nInterfaces = nPoints - 1;

    std::vector<double> fluxes(nPoints),  numericalFlux(nInterfaces), charSpeed(nPoints);

    double aRoe, a, aEF;

    fluxes    = ptrGov->flux(u_n);
    charSpeed = ptrGov->dFlux(u_n);

    const double eps = 1e-10;


    for (int i = 0; i < nInterfaces; ++i) {

        iLeft=i;
        iRight=i+1;


        if (u_n.u[iLeft] == u_n.u[iRight]) aRoe = charSpeed[iLeft];
        else aRoe = (fluxes[iLeft] - fluxes[iRight]) / (u_n.u[iLeft] - u_n.u[iRight] + eps);

        aEF = fabs(aRoe);

        if(charSpeed[iLeft] < 0 && charSpeed[iRight] > 0){

            aEF = ((charSpeed[iLeft] + charSpeed[iRight]) * aRoe
                   - 2*charSpeed[iLeft]*charSpeed[iRight])
                    / (charSpeed[iRight]-charSpeed[iLeft]);
        }

        //flusso numerico alla Roe sull'interfaccia i-esima//
        numericalFlux[i] = 0.5*(fluxes[iLeft] + fluxes[iRight])
                           - 0.5*aEF*(u_n.u[iRight] - u_n.u[iLeft]);

    }

    return numericalFlux;





}


// LaxWendroff

std::vector<double> LWCFlux::computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx){

    int nInterface = u_n.size() - 1;
    int nPoints = u_n.size();
    std::vector<double> numFluxes(nInterface);
    std::vector<double> fluxes(nPoints);


    std::vector<double> ap5(nInterface);
    Solution up5(nInterface);

    fluxes = ptrGov->flux(u_n);

    int iLeft, iRight;

    for (int i=0; i<nInterface; i++){
        iLeft=i;
        iRight=i+1;

        up5.u[i] = 0.5*(u_n.u[iLeft] + u_n.u[iRight]);
    }


    ap5 = ptrGov->dFlux(up5);

    for (int i=0; i<nInterface; i++){
        iLeft=i;
        iRight=i+1;

        numFluxes[i] = 0.5*(fluxes[iLeft]+fluxes[iRight]) -
                       0.5*(dt/dx)*ap5[i]*(fluxes[iRight]-fluxes[iLeft]);

    }

    return numFluxes;
}

// GODUNOV EXACT

std::vector<double>
GodunovFlux::computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx) {

    int nPoints, nInterfaces, iLeft, iRight;

    nPoints = u_n.size();
    nInterfaces = nPoints - 1;

    std::vector<double> numericalFlux(nInterfaces);
    Solution uVertical(nInterfaces);

    for (int i = 0; i < nInterfaces; ++i) {

        iLeft = i;
        iRight = i+1;

        uVertical.u[i] = ptrGov->exactRiemannProblem(u_n[iLeft], u_n[iRight], 0.0).u[0];

    }

    numericalFlux = ptrGov->flux(uVertical);

    return numericalFlux;

}

// UHR

std::vector<double> UHRFlux :: computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx){

    int iLeft, iRight, nInterfaces, nPoints;

    double aRoe, aEF, deltaU, deltaU_upw, deltaU_l, deltaU_r,
           theta, phi;

    nPoints = u_n.size();
    nInterfaces = nPoints - 1;

    std::vector <double> fluxes(nPoints), charSpeed(nPoints);
    std::vector <double> numericalFluxes(nInterfaces);

    fluxes = ptrGov -> flux(u_n);
    charSpeed = ptrGov -> dFlux(u_n);

    for (int i = 0; i < nInterfaces; i++){

        iLeft = i;
        iRight = i+1;

        deltaU = u_n.u[iRight] - u_n.u[iLeft];

        if (u_n.u[iLeft] == u_n.u[iRight]) aRoe = charSpeed[iLeft];
        else aRoe = (fluxes[iLeft] - fluxes[iRight]) / (u_n.u[iLeft] - u_n.u[iRight]);

        aEF = fabs(aRoe);

        if(charSpeed[iLeft] < 0 && charSpeed[iRight] > 0){

            aEF = ((charSpeed[iLeft] + charSpeed[iRight]) * aRoe
                   - 2*charSpeed[iLeft]*charSpeed[iRight])
                  / (charSpeed[iRight]-charSpeed[iLeft]);
        }

        numericalFluxes[i] = 0.5*(fluxes[iRight] + fluxes[iLeft]) -
                             0.5*aEF*(u_n.u[iRight] - u_n.u[iLeft]);

        if (i == 0) deltaU_l = deltaU;
        else deltaU_l = u_n.u[iLeft] - u_n.u[iLeft - 1];

        if (i == nInterfaces - 1) deltaU_r = deltaU;
        else deltaU_r = u_n.u[iRight + 1] - u_n.u[iRight];


        deltaU_upw = 0.5*(deltaU_l + deltaU_r) +
                     0.5*(deltaU_l - deltaU_r)*sign(aRoe);

        theta = deltaU_upw/deltaU;

        phi = limiter -> phi(theta);

        // phi = flux_limiter(theta)
        // theta e' il rapporto di delta_u_upwind e la delta_u_centrata

        numericalFluxes[i] += 0.5*(aEF - aRoe*aRoe*dt/dx)*deltaU*phi;

    }

    return numericalFluxes;

}















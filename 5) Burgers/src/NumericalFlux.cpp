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
#include "NumericalFlux.h"

std::vector<double> RoeFlux::computeFluxes(GoverningEquation* ptrGov, Solution u_n){
    //cosa serve: eq di governo
    //governing equation pointer
    //soluzione corrente

    int nPoints, nInterfaces, iLeft, iRight;

    nPoints = u_n.size();
    nInterfaces = nPoints - 1;

    std::vector<double> fluxes(nPoints),  numericalFlux(nInterfaces);

    double aRoe, a;

    fluxes = ptrGov-> flux(u_n);


    for (int i = 0; i < nInterfaces; ++i) {

        iLeft=i;
        iRight=i+1;

        aRoe = (fluxes[iLeft]-fluxes[iRight]) / (u_n.u[iLeft]-u_n.u[iRight]);

        if(aRoe > 0)  a = 0;
        else          a = aRoe;

        // Same as above
        //a = (aRoe > 0) ? 0 : aRoe;

        //flusso numerico alle Roe sull'interfaccia i-esima//
        numericalFlux[i] = fluxes[iLeft] + a * (u_n.u[iRight] - u_n.u[iLeft]);

    }

    return numericalFlux;

}















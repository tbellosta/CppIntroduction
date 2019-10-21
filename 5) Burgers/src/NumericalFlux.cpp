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

    const double eps = 1e-15;


    for (int i = 0; i < nInterfaces; ++i) {

        iLeft=i;
        iRight=i+1;



        aRoe = (fluxes[iLeft] - fluxes[iRight]) / (u_n.u[iLeft] - u_n.u[iRight] + eps);

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















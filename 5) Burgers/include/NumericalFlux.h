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
#ifndef BURGERS_NUMERICALFLUX_H
#define BURGERS_NUMERICALFLUX_H

#include "GoverningEquation.h"


class NumericalFlux {

public:

    //metodo che mi restituisce un vettore che contiene il valore dei flussi alle interfacce
    virtual std::vector<double> computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx)=0;



};

class RoeFlux:public NumericalFlux{

public:

    std::vector<double> computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx);

};


class LWCFlux:public NumericalFlux{


public:

    std::vector<double> computeFluxes(GoverningEquation *ptrGov, const Solution &u_n, const double &dt, const double &dx);
};


#endif //BURGERS_NUMERICALFLUX_H

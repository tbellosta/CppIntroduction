//============================================================
//
//      Type:        burgers include file
//
//      Author:      Tommaso Bellosta on 27/10/2019.
//                   Dipartimento di Scienze e Tecnologie Aerospaziali
//                   Politecnico di Milano
//                   Via La Masa 34, 20156 Milano, ITALY
//                   e-mail: tommaso.bellosta@polimi.it
//
//      Copyright:   2019, Tommaso Bellosta and the burgers contributors.
//                   This software is distributed under the MIT license, see LICENSE.txt
//
//============================================================
#ifndef BURGERS_FLUXLIMITER_H
#define BURGERS_FLUXLIMITER_H


class FluxLimiter {

public:

    virtual double phi(const double& theta) = 0;

};

class VanLeer : public FluxLimiter {

public:

    double phi(const double& theta);

};

class MinMod : public FluxLimiter {

public:

    double phi(const double& theta);

};


#endif //BURGERS_FLUXLIMITER_H

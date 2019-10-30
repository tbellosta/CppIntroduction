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
#include <cmath>
#include <iostream>
#include "FluxLimiter.h"

static inline int sign(const double& val) {return (val>0) - (val<0);}

double VanLeer::phi(const double& theta) {

    return (fabs(theta) + theta)/(1 + fabs(theta));
    //psi = (a*fabs(b) + fabs(a)*b)/(fabs(a) + fabs(b) + 1.0d-8)

}



double MinMod::phi(const double& theta) {

    return fmax(0.0, fmin(1.0, theta));
    //psi = (0.5*sign(a) + 0.5*sign(b)) * fmin(ABS(a), fabs(b))

}

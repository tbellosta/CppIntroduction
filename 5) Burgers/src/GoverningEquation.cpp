//============================================================
//
//      Type:        CppIntroduction include file
//
//      Author:      Tommaso Bellosta on 15/10/2019.
//                   Dipartimento di Scienze e Tecnologie Aerospaziali
//                   Politecnico di Milano
//                   Via La Masa 34, 20156 Milano, ITALY
//                   e-mail: tommaso.bellosta@polimi.it
//
//      Copyright:   2019, Tommaso Bellosta and the CppIntroduction contributors.
//                   This software is distributed under the MIT license, see LICENSE.txt
//
//============================================================
#include <cmath>
#include "GoverningEquation.h"

std::vector<double> InvBurgers::flux(const Solution &sol){

    int len;

    len = sol.size();

    //creiamo un vettore di double della dimensione di u e ogni elemento sara' 0.5*u^2
    std::vector<double> f(len);

    for (int i = 0; i < len; ++i) f[i] = 0.5 * sol.u[i] * sol.u[i];

    return f;

}

std::vector<double> InvBurgers::dFlux(const Solution &sol){

    int len;

    len = sol.size();

    std::vector<double> dF(len);

    for (int i = 0; i < len; ++i) dF[i] =  sol.u[i];

    return dF;

}

Solution InvBurgers::exactRiemannProblem(const Solution &ul, const Solution &ur, const double &csi) {

    Solution uOut(1);

    if (fabs(ul.u[0] - ur.u[0]) < 1e-8) {
        uOut.u[0] = 0.5 * (ul.u[0] + ur.u[0]);
        return uOut;
    }

    // SHOCK
    if(ul.u[0] > ur.u[0]){

        double s = 0.5 * (ul.u[0] + ur.u[0]);

        uOut.u[0] = (s > csi) ? ul.u[0] : ur.u[0];

    }
    else { // RAREFACTION

        if (csi < ul.u[0])         uOut.u[0] = ul.u[0];
        else if (csi > ur.u[0])    uOut.u[0] = ur.u[0];
        else                       uOut.u[0] = csi;

    }

    return uOut;

}
















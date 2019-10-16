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
#include "GoverningEquation.h"


Solution::Solution(int n){

    this->u.resize(n);

}

Solution::Solution(Grid *griglia) {

    this->u.resize(griglia->nodes.size());

}

int Solution::size() {
    return u.size();
}

std::vector<double> InvBurgers::flux(Solution sol){

    int len;

    len = sol.size();

    //creiamo un vettore di double della dimensione di u e ogni elemento sara' 0.5*u^2
    std::vector<double> f(len);

    for (int i = 0; i < len; ++i) f[i] = 0.5 * sol.u[i] * sol.u[i];

    return f;

}


















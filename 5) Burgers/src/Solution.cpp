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
#include "Solution.h"

Solution::Solution(int n){

    this->u.resize(n);

}

Solution::Solution(Grid *griglia) {

    this->u.resize(griglia->nodes.size());

}

int Solution::size() const {

    return u.size();

}

Solution &Solution::operator=(const Solution &rhs) {

    this->u = rhs.u;

    return *this;

}

Solution Solution::operator[](const int &i) const{

    Solution out(1);

    out.u[0] = this->u[i];

    return out;

}

void Solution::resize(const int &dim) {
    this->u.resize(dim);
}

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

int Solution::size() {

    return u.size();

}
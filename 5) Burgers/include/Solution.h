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
#ifndef BURGERS_SOLUTION_H
#define BURGERS_SOLUTION_H

#include "Grid.h"


class Solution {

public:

    std::vector<double> u;

    Solution () {};
    Solution(int n);//costruttore che inizializza un oggetto con dimensione n//
    Solution (Grid* griglia); //definisco un oggetto di tipo soluzione legato ad una griglia//

    int size();
};


#endif //BURGERS_SOLUTION_H

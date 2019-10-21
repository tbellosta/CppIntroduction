//============================================================
//
//      Type:        CppIntroduction implementation file
//
//      Author:      Tommaso Bellosta on 24/09/2019.
//                   Dipartimento di Scienze e Tecnologie Aerospaziali
//                   Politecnico di Milano
//                   Via La Masa 34, 20156 Milano, ITALY
//                   e-mail: tommaso.bellosta@polimi.it
//
//      Copyright:   2019, Tommaso Bellosta and the CppIntroduction contributors.
//                   This software is distributed under the MIT license, see LICENSE.txt
//
//============================================================
#include "Grid.h"

Grid::Grid(const double &x0, const double &xf, const int &nNodes){

    // initialize uniform grid
    this->buildUniformGrid(x0, xf, nNodes);

}


Grid::Grid() {
    // initialize empty grid
}

void Grid::buildUniformGrid(const double &x0, const double &xf, const int &nNodes) {

    // build uniform grid

    double h = (xf - x0) / (nNodes - 1);

    this->nodes = std::vector<double>(nNodes);

    for (int i = 0; i < nNodes; ++i) {
        this->nodes[i] = x0 + h*i;
    }

}

double Grid::getCellSize(int i) {

    if (i >= this->nodes.size() - 1){
        // warning
    }

    double cellSize;

    cellSize = this->nodes[i+1] - this->nodes[i];

    return cellSize;
}

double Grid::getDualCellSize(int index){

    if (index >= this->nodes.size()){
        // warning
    }

    double dualCellSize;
    int jL, jR;

    if(index == 0){
        jL = 0;
        jR = 1;
    }
    else if(index == this->nodes.size() - 1){
        jL = index - 1;
        jR = index;
    }
    else{
        jL = index - 1;
        jR = index + 1;
    }

    dualCellSize = (nodes[jR] - nodes[jL]) / 2;

    return dualCellSize;

}



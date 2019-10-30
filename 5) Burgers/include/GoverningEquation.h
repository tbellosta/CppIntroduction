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
#ifndef CPPINTRODUCTION_GOVERNINGEQUATION_H
#define CPPINTRODUCTION_GOVERNINGEQUATION_H

#include "Solution.h"

class GoverningEquation {

public:

    virtual std::vector<double> flux(const Solution &u) = 0;
    virtual std::vector<double> dFlux(const Solution &u) = 0;

    virtual Solution exactRiemannProblem(const Solution& ul, const Solution& ur, const double& csi) = 0;



};

class InvBurgers : public GoverningEquation{

public:

    std::vector<double> flux(const Solution &u);
    std::vector<double> dFlux(const Solution &u);

    Solution exactRiemannProblem(const Solution& ul, const Solution& ur, const double& csi);

};



#endif //CPPINTRODUCTION_GOVERNINGEQUATION_H

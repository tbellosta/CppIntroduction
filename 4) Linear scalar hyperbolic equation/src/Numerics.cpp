#include "Numerics.h"

void Solution::resizeSolution(const int &size) {

    this->u.resize(size);

}

Solution &Solution::operator=(const Solution &rhs) {

    this->u = rhs.u;

    return *this;

}

//======================================================================== funzioni classe madre

FiniteDifferenceMethods::FiniteDifferenceMethods() {
    this->mesh = nullptr;
}


void FiniteDifferenceMethods::setGridPointer(Grid* gridPtr){

    this -> mesh = gridPtr;

}

//======================================================================== class ForwardEuler

ForwardEuler::ForwardEuler() {

}

ForwardEuler::ForwardEuler(Grid* gridPtr) {

    this->setGridPointer(gridPtr);

}

Solution ForwardEuler::computeSolution(Solution& u_n, double charSpeed, double dt){

    Solution u_np1;

    int numberNodes;

    double u_im1;
    double u_i;
    double u_ip1;
    double dx;

    numberNodes = this->mesh->nodes.size();
    u_np1.resizeSolution(numberNodes);

    dx = (this -> mesh -> nodes[1] - this -> mesh -> nodes[0]); // hp griglia uniforme

    for(int i = 0; i < numberNodes; ++i){

        if(i == 0){

            u_im1 = u_n.u[numberNodes-2];
            u_i = u_n.u[i];
            u_ip1 = u_n.u[i+1];

        }

        else if(i == numberNodes - 1){

            u_im1 = u_n.u[i-1];
            u_i = u_n.u[i];
            u_ip1 = u_n.u[0];

        }
        else{

            u_im1 = u_n.u[i-1];
            u_i = u_n.u[i];
            u_ip1 = u_n.u[i+1];

        }

        u_np1.u[i] = u_i - 0.5 * (charSpeed * dt / dx) * (u_ip1 - u_im1);

    }

    return u_np1;
}


//======================================================================== class LaxWendroff

LaxWendroff::LaxWendroff(){}

LaxWendroff::LaxWendroff(Grid* gridPtr){

    this->setGridPointer(gridPtr);

}


Solution LaxWendroff::computeSolution(Solution& u_n, double charSpeed, double dt){

    Solution u_np1;  // solution at next time step

    int numberNodes;

    double u_im1;
    double u_i;
    double u_ip1;
    double dx;
    double CFL;

    numberNodes = this->mesh->nodes.size();
    u_np1.resizeSolution(numberNodes);

    dx = (this -> mesh -> nodes[1] - this -> mesh -> nodes[0]); // hp griglia uniforme

    CFL = charSpeed * dt / dx;

    for(int i = 0; i < numberNodes; ++i){

        if(i == 0){

            u_im1 = u_n.u[numberNodes-2];
            u_i = u_n.u[i];
            u_ip1 = u_n.u[i+1];

        }

        else if(i == numberNodes - 1){

            u_im1 = u_n.u[i-1];
            u_i = u_n.u[i];
            u_ip1 = u_n.u[0];

        }
        else{

            u_im1 = u_n.u[i-1];
            u_i = u_n.u[i];
            u_ip1 = u_n.u[i+1];

        }

        u_np1.u[i] = u_i - 0.5 * CFL * (u_ip1 - u_im1) + 0.5 * CFL * CFL * (u_ip1 - 2 * u_i + u_im1);

    }

    return u_np1;

};

//======================================================================== class LaxFriedrichs

LaxFriedrichs::LaxFriedrichs() {

}

LaxFriedrichs::LaxFriedrichs(Grid *gridPtr) {
    this->setGridPointer(gridPtr);
}

Solution LaxFriedrichs::computeSolution(Solution &u_n, double charSpeed, double dt) {

    Solution u_np1;

    int numberNodes;

    double u_im1;
    double u_ip1;
    double dx;

    numberNodes = this->mesh->nodes.size();
    u_np1.resizeSolution(numberNodes);

    dx = (this -> mesh -> nodes[1] - this -> mesh -> nodes[0]); // hp griglia uniforme

    for(int i = 0; i < numberNodes; ++i){

        if(i == 0){

            u_im1 = u_n.u[numberNodes-2];
            u_ip1 = u_n.u[i+1];

        }

        else if(i == numberNodes - 1){

            u_im1 = u_n.u[i-1];
            u_ip1 = u_n.u[0];

        }
        else{

            u_im1 = u_n.u[i-1];
            u_ip1 = u_n.u[i+1];

        }

        u_np1.u[i] = 0.5 * (u_ip1 + u_im1) - 0.5 * (charSpeed * dt / dx) * (u_ip1 - u_im1);

    }

    return u_np1;

}


//======================================================================== class UpwindLeft

UpwindLeft::UpwindLeft() {

}

UpwindLeft::UpwindLeft(Grid *gridPtr) {
    this->setGridPointer(gridPtr);
}

Solution UpwindLeft::computeSolution(Solution &u_n, double charSpeed, double dt) {

    Solution u_np1;

    int numberNodes;

    double u_im1;
    double u_i;
    double dx;

    numberNodes = this->mesh->nodes.size();
    u_np1.resizeSolution(numberNodes);

    dx = (this -> mesh -> nodes[1] - this -> mesh -> nodes[0]); // hp griglia uniforme

    for(int i = 0; i < numberNodes; ++i){

        if(i == 0){

            u_im1 = u_n.u[numberNodes-2];
            u_i = u_n.u[i];

        }
        else{

            u_im1 = u_n.u[i-1];
            u_i = u_n.u[i];

        }

        u_np1.u[i] = u_i - (charSpeed * dt / dx) * (u_i - u_im1);

    }

    return u_np1;

}

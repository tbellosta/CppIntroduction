#include "numerics.h"

//======================================================================== funzioni classe madre

FiniteDifferenceMethods::FiniteDifferenceMethods() {

}

FiniteDifferenceMethods::FiniteDifferenceMethods(Grid* grid) {

    this->setGridPointer(mesh);

}

void FiniteDifferenceMethods::setGridPointer(Grid* grid){

  this -> mesh = grid;

}

//======================================================================== funzioni classe ForwardEuler

ForwardEuler::ForwardEuler() {

}

ForwardEuler::ForwardEuler(Grid* mesh) {

    this->setGridPointer(mesh);

}

Solution ForwardEuler::computeSolution(Solution& u_n, double charSpeed, double dt, double leftBC){

  Solution u_np1; // oggetto soluzione a tn + 1

  int numberNodes = this->mesh->nodes.size();
  u_np1.u.resize(numberNodes); // sto dando dimensione al vettore tn + 1


  double u_im1;
  double u_i;
  double u_ip1;
  double dx;

  dx = (this -> mesh -> nodes[1] - this -> mesh -> nodes[0]); // hp griglia uniforme

  for(int i = 0; i < numberNodes; ++i){

    if(i == 0){

      u_np1.u[0] = leftBC;

      continue; // passo alla i successiva
      }

    else if(i == numberNodes - 1){

      u_i = u_n.u[i];
      u_im1 = u_n.u[i-1];

      u_np1.u[i] = u_i - ((u_i - u_im1) / (dx)) * charSpeed * dt;

      continue;

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

LaxWendroff::LaxWendroff(){}


Solution LaxWendroff::computeSolution(Solution& u_n, double charSpeed, double dt, double leftBC){
  Solution u_np1; // oggetto soluzione a tn + 1

  int numberNodes = this->mesh->nodes.size();
  u_np1.u.resize(numberNodes); // sto dando dimensione al vettore tn + 1


  double u_im1;
  double u_i;
  double u_ip1;
  double dx;

  dx = (this -> mesh -> nodes[1] - this -> mesh -> nodes[0]); // hp griglia uniforme

  for(int i = 0; i < numberNodes; ++i){

    if(i == 0){

      u_np1.u[0] = leftBC;

      continue; // passo alla i successiva
    }

    else if(i == numberNodes - 1){

      u_i = u_n.u[i];
      u_im1 = u_n.u[i-1];

      u_np1.u[i] = u_i - ((u_i - u_im1) / (dx)) * charSpeed * dt;

      continue;

    }
    else{

      u_im1 = u_n.u[i-1];
      u_i = u_n.u[i];
      u_ip1 = u_n.u[i+1];


    }
    double CFL = charSpeed * dt / dx;
    u_np1.u[i] = u_i - 0.5 * CFL * (u_ip1 - u_im1) + 0.5 * CFL * CFL * (u_ip1 - 2 * u_i + u_im1);


  }

  return u_np1;

};

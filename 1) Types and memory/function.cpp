#include "function.h"

int factorial(int& integer){
   // computes the factorial of variable integer
   // and sets it to zero

   int fact = 1;
   for(int i = integer; i > 0; i--){
     fact = fact * i;
   }

  integer = 0;

  return fact;
}

void fillArray(double array[], int dimension){
   // sets all elements of array to zero
   for(int i = 0; i < dimension; i++){
     array[i] = 0.0;
   }

}

void fillMatrix(double matrix[][3],int nRows){
  // sets all elements of static matrix (declared on stack) to zero
  // only for matrices w/ 3 columns
  for(int i = 0; i < nRows; i++){
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = 0.0;
    }
  }
}

void fillDynamicMatrix(double** matrix,int nRows, int nColumns){
  // sets all elements of dynamic matrix (declared on heap) to zero
  // works w/ any size of matrix
  for(int i = 0; i < nRows; i++){
    for (int j = 0; j < nColumns; j++) {
      matrix[i][j] = 0.0;
    }
  }

}

/*
  REFERENCE MATERIAL
    textbooks:
      THE C++ PROGRAMMING LANGUAGE - Bjarne Stroustrup
      C++ PRIMER - Lippman,Lajoie,Moo

    online:
      cppreference.com
      cplusplus.com

  COMPILER INSTALLATION
    LINUX
      $ sudo apt install build-essential
      $ sudo apt install cmake
    MAC
      install xcode from appstore, then type on terminal
        $ xcode-select --install
      install homebrew from http://brew.sh, then
        $ brew install cmake

  TEXT EDITOR (w/ syntax highlight for c++)
    atom (macOS/Linux)
    sublimeText (Linux)
    gedit (Linux)

  IDE (integrated development enviroinment)
    CLion (macOS/Linux free license from POLIMI website)
    Xcode (macOS)
    VisualStudio (Windows)

  VIRTUAL MACHINE
    VirtualBox

*/


#include "function.h"
#include <iostream>

int main(){

  // simple types and pointers

  int intero, int2;   // defines two integer variables

  int* ptrInt;        // defines pointer to integer variable
  float* ptrFloat;    // defines pointer to float variable

  intero = 1;         // assign value to integer variable
  ptrInt = &intero;   // assign address of variable intero to pointer ptrInt

  *ptrInt = 15;       // chage the value of the variable pointed to by ptrInt to 15
                    // same as intero = 15;

  ptrInt = &int2;     //ptrInt now points to int2;
  *ptrInt = 15;       // chage the value of the variable int2 to 15

  int& refInt = intero;             // reference (AKA alias) to variable intero

  int fact = factorial(intero);     // defines integer variable and assigns it to
                                  //the result of function factorial

  std::cout << "Value of factorial: " << fact << "\n";
  std::cout << "Integer value: "<< intero << "\n";


  const int dim = 10;  // constant dimension of array
  double array[dim];   // defines stack array (dimension is known at compile-time)
  double matrix[3][3]; // defines stack matrix (dimension is known at compile-time)

  fillArray(array, dim);
  fillMatrix(matrix,3);

  std::cout << "Valore array: \t";
  for (int i = 0; i < dim; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl; // ends line

  // Define dynamically allocated arrays (on the heap, dimension known at runtime)
  int dimDyn = 15;                   // not const, can be given by user or result of computation
  double* data = new double[dimDyn]; // allocate array, doesn't go out of scope
  delete[] data;                     // free array

  int* intDyn = new int;  // declare simple int on the heap
  delete intDyn;          // delets the int

  // declares matrix of wanted size on the heap
  int nRows = 15;                          // number of rows/dimension of a column
  int nColumns = 10;                       // number of columns/dimension of a row
  double** matrixDyn = new double*[nRows]; // declares array of pointers to double
  for (int i = 0; i < nRows; i++) {
    matrixDyn[i] = new double[nColumns]; // each pointer of the array points to the
                                         // block of memory storing a given row
  }

  fillDynamicMatrix(matrixDyn, nRows, nColumns);

  std::cout << "matrixDyn[2][4]: \t" << matrixDyn[2][4] << std::endl; // prints element [2,4] of the matrix

}

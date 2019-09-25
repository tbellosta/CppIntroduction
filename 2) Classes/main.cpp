#include "function.h"
#include <iostream>

#include "vettore.h"
#include "vector"

int main(){

    /**
     * Playing with the first class we created.
     * Vettore is a dynamic array of doubles (see code from first lecture)
     * - memory management (allocation/deallocation) is hidden behind the curtains
     * - operator overloading for simple arithmetic operations
     */

    std::cout << "\n\nCLASS VETTORE\n";

    // creating an empty vector (v1) and two vectors of 5 elements
    // v1,v2,v3 are three OBJECTS of CLASS vettore
    vettore v1, v2(5), v3(5);


    // setting the 4th component of v2 and v3
    v3[3] = 2.0;
    v2[3] = 5.0;

    // adding a new element to both v2 and v3
//    v2.push_back(5.0); // adding a new element = 5 at the end of v2
//    v3.push_back(8.0); // adding a new element = 8 at the end of v3

    // setting v1 equals to v2 + 2v3
    v1 = v2 + v3*2.0;


    // prints the elements of v1
    std::cout << v1 << std::endl;


    /**
     * Polymorphism and templates.
     *
     * C++ allows us to define multiple functions with different parameters using the same name i.e. polymorphism
     * In the following, function norm computes the two-norm of a vector or the absolute value of a double depending
     * on the type that is passed to the function.
     */

    std::cout << "\n\n\nPOLYMORPHISM FUNCTION NORM\n\n";

    double d = 4.12634564353242;

    std::cout << norm(d) << std::endl;  // abs of d
    std::cout << norm(v1) << std::endl;  // two-norm of v1

    /**
     * In the following polymorphism is used to define three different functions absVal that return
     * the absolute value of an int, a float or a double. The functions do the exact same thing but work
     * on different types.
     *
     * The use of templates allows to define absVal so that it is independent on the type of data. Templates are
     * parametric functions in which one or more parameters can change. In the case of the absVal function the
     * parameter that is allowed to change is the type of data that we pass to the function (and is returned by it).
     * This allows to define only one template function instead of the three independent functions we defined above.
     * The parameters of a template function must be specified in between <> (see below)
     */

    std::cout << "\n\n\nPOLYMORPHISM FUNCTION ABSVAL\n\n";

    int i = -4;
    float f = -4.3456363f;

    // using polymorphism (the name is the same (absVal) but the function definition is different)
    std::cout << absVal(i) << std::endl;
    std::cout << absVal(f) << std::endl;
    std::cout << absVal(d) << std::endl;

    std::cout << "\n\n\nTEMPLATE FUNCTION ABSVAL\n\n";

    // same thing but with templates (we defined only one function)
    std::cout << "abs of integer: " << absVal<int>(i) << std::endl;
    std::cout << "abs of float: " << absVal<float>(f) << std::endl;
    std::cout << "abs of double: " << absVal<double>(d) << std::endl;


    vettore vv(15);

    Grid mesh6;

    std::vector<mesh> vMesh(5);









}

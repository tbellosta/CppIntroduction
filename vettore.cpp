#include <algorithm>
#include <iostream>
#include "vettore.h"
#include "cmath"


//===================================CONSTRUCTORS/DESTRUCTOR===================================

vettore::vettore(){

    /** (this) is a pointer to the object of the class
    * operator -> is like operator . but for pointers, it lets you access members of a pointer to an object
    * example:
    *          vettore vect(12);                       // vector of 12 elements
    *          vettore* ptrVect = &vect;               // pointer to the same vector (vect)
    *          int size = vect.getDimension();
    *          int size2 = ptrVect->getDimension();
    * size e size2 are the same since I'm calling the function on the same object, once on the object itself and the
    * second time on a pointer to the same object
    *
    * using (this) to access internal members is not mandatory but it makes code mode clear by separating the variables
    * of the class from the parameters of the method (function defined inside of the class)
    *
    * in the following
    *          this->data = nullptr
    * is equivalent to
    *          data = nullptr;
    */

    this->dimension = 0;
    this->data = nullptr;   // since this constructor initializes an empty vector we don't want data to
                            // point to any address in memory. Setting data equal to nullptr is the way to do so.


}

vettore::vettore(int dim){

    this->dimension = dim;
    this->allocateMemory();
    this->setToZero();

}

vettore::vettore(const vettore& rhs){

    this->dimension = rhs.dimension;
    this->allocateMemory();

    std::copy(rhs.data, rhs.data + rhs.dimension, this->data);  // this line is equivalent to the following for loop, just faster
                                                                // copies the data from the block of memory of the vector rhs to this vector

//    for (int i = 0; i < dimension; ++i) {
//        this->data[i] = rhs.data[i];
//    }


}

vettore::~vettore() {

    deallocateMemory();

}

//===================================PRIVATE METHODS===================================

void vettore::allocateMemory() {

    this->data = new double[dimension];

}

void vettore::deallocateMemory() {

    delete[] this->data;
    this->data = nullptr;

}

void vettore::setToZero() {

    // set all elements to zero, could also be done by looping through all elements
    // of the vector and setting them = 0
    std::memset(this->data, 0, this->dimension * sizeof(double));

    /**
     * What function std::memeset(void* ptr, char value, int size) does is the following:
     * It takes an address in memory (ptr) and sets (size) consecutive bytes starting from that address
     * equal to (value). (value) is defined as a char because the size of a char is 1 byte.
     */


}

//===================================PUBLIC METHODS===================================

int vettore::getDimension() const {
    return this->dimension;
}

void vettore::push_back(const double &value) {

    /**
     * this method adds a new element at the end of the vector. In c++ there is no way to append a new element at the
     * end of a previously allocated block of memory with an array-like data structure. The only way to do so is to
     * allocate a new block of memory with size increased by one and copy the data to the new memory location.
     * Remember also to deallocate the memory occupied by the previous block of data.
     */

    // allocate new block of memory of size increased by one. tmp is the address of this new block
    double* tmp = new double[this->dimension + 1];
    // copy what it is in memory starting from the address (this->data) up to
    // address (this->data + this->dimension) in new memory block starting at address (tmp)
    std::copy(this->data, this->data + this->dimension, tmp);
    // set the value of the last element in newly allocated memory
    tmp[dimension] = value;

    // deallocate old memory block
    this->deallocateMemory();
    // the pointer inside the class needt to point to the new block of memory
    this->data = tmp;
    // increase the dimension variable to the new size
    this->dimension++;

}

//===================================OPERATORS OVERLOADING===================================

double& vettore::operator[](int index) const {

    return this->data[index];

}


vettore &vettore::operator=(const vettore &rhs) {

    if (this != &rhs){  // avoids making the copy if assigning object to itself (a = a)

        if (this->dimension != rhs.dimension) {  // resize array
            this->deallocateMemory();
            this->dimension = rhs.dimension;
            this->allocateMemory();
        }

        std::copy(rhs.data, rhs.data + rhs.dimension, this->data);

    }
    return *this;
}


vettore vettore::operator+(const vettore &rhs) {

    // only on vectors of the same size
    if (this->dimension == rhs.dimension) {
        vettore out(this->dimension);

        for (int i = 0; i < this->dimension; ++i) {
            out[i] = this->data[i] + rhs[i];
        }

        return out;
    }
    else {
        // print warning or error
    }

    return *this;


}

vettore vettore::operator-(const vettore &rhs) {
    // only on vectors of the same size
    if (this->dimension == rhs.dimension) {
        vettore out(this->dimension);

        for (int i = 0; i < this->dimension; ++i) {
            out[i] = this->data[i] - rhs[i];
        }

        return out;
    }
    else {
        // print warning or error
    }

    return *this;
}

vettore vettore::operator*(const double &rhs) {


    vettore out(this->dimension);

    for (int i = 0; i < this->dimension; ++i) {
        out[i] = this->data[i] * rhs;
    }

    return out;

}


vettore vettore::operator/(const double &rhs) {

    vettore out(this->dimension);

    for (int i = 0; i < this->dimension; ++i) {
        out[i] = this->data[i] / rhs;
    }

    return out;
}


std::ostream &operator<<(std::ostream &out, const vettore &rhs) {

    for (int i = 0; i < rhs.getDimension(); ++i) {
        out << i << "| " << rhs[i] << std::endl;
    }

    return out;
}

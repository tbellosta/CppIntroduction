#ifndef CPPINTRODUCTION_VETTORE_H
#define CPPINTRODUCTION_VETTORE_H

/**
 * Class vettore defines a dynamic array of doubles.
 * Operations add/subtract between objects of class vettore of the same size are defined.
 * Multiplication/division by a scalar is also defined.
 */
class vettore {
private: // private members, can be accessed only from inside the class

    int dimension;
    double* data;
    void allocateMemory();
    void deallocateMemory();
    void setToZero();                 // initializes all elements to zero;

public: // public members, can be accessed also from the outside

    vettore();                              // default constructor, empty vector
    vettore(int dim);                       // constructor, vector of size dim (elements set to zero)
    vettore(const vettore& rhs);            // copy constructor
    ~vettore();                             // destructor

    int getDimension() const;               // returns number of elements in the array
    void push_back(const double& value);    // push new value at the end of array


    double& operator[](int index) const;    // returns reference to element index in the array

    // the following operators allow to use simple arithmetic operations between vectors
    // see main.cpp for examples
    vettore& operator=(const vettore& rhs);
    vettore operator+(const vettore& rhs);  // vector + vector iff size is the same
    vettore operator-(const vettore& rhs);  // vector - vector iff size is the same
    vettore operator*(const double& rhs);   // vector + scalar
    vettore operator/(const double& rhs);   // vector - scalar


};


// overload of the stream insertion operator (<<). Now a vector can be printed using:
//          vettore vect(15);
//          std::cout << vect;
std::ostream& operator<<(std::ostream& out, const vettore& rhs);


#endif //CPPINTRODUCTION_VETTORE_H

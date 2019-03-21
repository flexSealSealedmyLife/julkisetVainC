#ifndef ConcreteSquareMatrix_H_INCLUDED
#define ConcreteSquareMatrix_H_INCLUDED

#include "element.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>

/*!
This class is used to perform calculation on given ConcreteSquareMatrix
!*/
class SymbolicSquareMatrix;

class ConcreteSquareMatrix{

public:
    ConcreteSquareMatrix();  /*! Constructor for ConcreteSquareMatrix !*/
    ConcreteSquareMatrix(const std::string& str); /*! This places values to ConcreteSquareMatrix, is const so cant be changed !*/
    ConcreteSquareMatrix(const ConcreteSquareMatrix& m);
    ~ConcreteSquareMatrix();  /*! Kills ConcreteSquareMatrix !*/
    ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix& m);
    ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&& m);
    ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix& m); /*!this adds the numbers together in m !*/
    ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix& m); /*!This is the minus ?function? takes values from m !*/
    ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix& m); /*!This is the * function. Takes values from m !*/
    bool operator==(const ConcreteSquareMatrix& m) const;
    void print(std::ostream& os) const;
    std::string toString() const;
    ConcreteSquareMatrix transpose() const;
    ConcreteSquareMatrix operator ==(const ConcreteSquareMatrix& first);
private:
    friend SymbolicSquareMatrix;
    int n;
    std::vector< std::vector<uniq_intelem_pointer> > elements;
};

ConcreteSquareMatrix operator +(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);  /*!I dont know what this is but intelement.h had a similar so i thought what the hell. Please instruct me what this is if you happen to see this comment. !*/
ConcreteSquareMatrix operator -(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
ConcreteSquareMatrix operator *(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
/*!



!*/

#endif // ConcreteSquareMatrix_H_INCLUDED

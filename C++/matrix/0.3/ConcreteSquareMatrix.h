#ifndef ConcreteSquareMatrix_H_INCLUDED
#define ConcreteSquareMatrix_H_INCLUDED

#include "element.h"
#include "SquareMatrix.h"
#include <string>
#include <numeric>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>

/*!
This class is used to perform calculation on given ConcreteSquareMatrix
!*/
class SymbolicSquareMatrix;

class ConcreteSquareMatrix : public SquareMatrix{

public:
    ConcreteSquareMatrix();  /*! Constructor for ConcreteSquareMatrix !*/
    ConcreteSquareMatrix(const std::string& str); /*! This places values to ConcreteSquareMatrix, is const so cant be changed !*/
    ConcreteSquareMatrix(const ConcreteSquareMatrix& m);
    ~ConcreteSquareMatrix();
    ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix& m);
    ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&& m);
    ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix& m);
    ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix& m);
    ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix& m);
    bool operator==(const ConcreteSquareMatrix& m) const;
    void print(std::ostream& os) const;
    std::string toString() const;
    ConcreteSquareMatrix transpose() const;
    ConcreteSquareMatrix operator ==(const ConcreteSquareMatrix& first);
    SquareMatrix* clone() const;
    ConcreteSquareMatrix evaluate (const Valuation& valuation) const;

private:
    friend SymbolicSquareMatrix;
    int n;
    std::vector< std::vector<uniq_intelem_pointer> > elements;
};



ConcreteSquareMatrix operator +(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
ConcreteSquareMatrix operator -(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
ConcreteSquareMatrix operator *(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
/*!



!*/

#endif // ConcreteSquareMatrix_H_INCLUDED

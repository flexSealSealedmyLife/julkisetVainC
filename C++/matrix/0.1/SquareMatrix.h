#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED

#include "IntElement.h"
#include <string>
#include <iostream>

/*!
This class is used to perform calculation on given squarematrix
!*/

class SquareMatrix{

public:
    SquareMatrix();  /*! Constructor for SquareMatrix !*/
    SquareMatrix(const IntElement& i11, const IntElement& i12, const IntElement& i21, const IntElement& i22); /*! This places values to squarematrix, is const so cant be changed !*/
    SquareMatrix(const SquareMatrix& m);
    ~SquareMatrix();
    SquareMatrix& operator+=(const SquareMatrix& m);
    SquareMatrix& operator-=(const SquareMatrix& m);
    SquareMatrix& operator*=(const SquareMatrix& m);
    //print(std::ostream& os) const;
    std::string toString() const;


private:
    IntElement e11;  /*!These 4 following elements are used in calculations in squarematrix.cpp !*/
    IntElement e12;
    IntElement e21;
    IntElement e22;




};
SquareMatrix operator +(const SquareMatrix& first, const SquareMatrix& second);

/*!



!*/

#endif // SQUAREMATRIX_H_INCLUDED

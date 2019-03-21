#include "SquareMatrix.h"

SquareMatrix::SquareMatrix() {

}

SquareMatrix::SquareMatrix(const SquareMatrix& m){

    e11 = m.e11;
    e12 = m.e12;  /*! Place value!*/
    e21 = m.e21;
    e22 = m.e22;

}

SquareMatrix::SquareMatrix(const IntElement& i11, const IntElement& i12, const IntElement& i21, const IntElement& i22) {

     e11 = i11;
     e12 = i12;
     e21 = i21;
     e22 = i22;
}

SquareMatrix::~SquareMatrix() {

}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m) {

    e11 += m.e11;
    e12 += m.e12;
    e21 += m.e21;
    e22 += m.e22;

    return(*this);
}

SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m) {

    e11 -= m.e11;
    e12 -= m.e12;
    e21 -= m.e21;
    e22 -= m.e22;

    return(*this);
}

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m) {

    IntElement ii11;
    IntElement ii12;
    IntElement ii21;
    IntElement ii22;

    ii11 = (e11 * m.e11) + (e12 * m.e21);
    ii12 = (e11 * m.e12) + (e12 * m.e22);
    ii21 = (e12 * m.e11) + (e22 * m.e21);
    ii22 = (e12 * m.e21) + (e22 * m.e22);

    e11 = ii11;
    e12 = ii12;
    e21 = ii21;
    e22 = ii22;

    return(*this);
}

SquareMatrix operator+(const SquareMatrix& first, const SquareMatrix& second) {
    SquareMatrix temp = first;
    temp+=second;
    return(temp);
}




/*std::string toString() const {


}*/



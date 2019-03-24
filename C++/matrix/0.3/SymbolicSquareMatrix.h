#ifndef SYMBOLICSQUAREMATRIX_H_INCLUDED
#define SYMBOLICSQUAREMATRIX_H_INCLUDED
#include <ostream>
#include <memory>
#include <map>
#include "element.h"
#include "SquareMatrix.h"
#include <vector>
#include "ConcreteSquareMatrix.h"

/*! This is the header file for SymbolicSquareMatrix !*/

class SymbolicSquareMatrix : public SquareMatrix {

private:
    int n; /*! !*/
    std::vector<std::vector<std::unique_ptr<Element>>> elements; /*! !*/

public:
    SymbolicSquareMatrix(); /*!  !*/
    SymbolicSquareMatrix(const std::string& str_m); /*! !*/
    SymbolicSquareMatrix(const SymbolicSquareMatrix& m); /*! !*/
    SymbolicSquareMatrix(SymbolicSquareMatrix &&m); /*! !*/
    ~SymbolicSquareMatrix(); /*! Deconstructor for this class !*/
    SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix& m); /*! !*/
    SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&& m); /*! !*/
    SymbolicSquareMatrix transpose() const; /*! !*/
    bool operator==(const SymbolicSquareMatrix& m) const; /*! This is the == operator !*/
    void print(std::ostream& os) const; /*! Used to print, doesnt return anything !*/
    std::string toString() const; /*!  !*/
    ConcreteSquareMatrix evaluate(const Valuation& val) const; /*! !*/
    SquareMatrix* clone() const;
};
/*
ConcreteSquareMatrix operator +(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
ConcreteSquareMatrix operator -(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);
ConcreteSquareMatrix operator *(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second);*/

#endif // SYMBOLICSQUAREMATRIX_H_INCLUDED

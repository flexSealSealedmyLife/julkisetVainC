#ifndef COMPOSITESQUAREMATRIX_H_INCLUDED
#define COMPOSITESQUAREMATRIX_H_INCLUDED

#include "SquareMatrix.h"
#include "ConcreteSquareMatrix.h"

using CSMFunction = std::function<ConcreteSquareMatrix(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&)>;


class CompositeSquareMatrix : public SquareMatrix {

private:
    uniq_sqm_ptr oprnd1;
    uniq_sqm_ptr oprnd2;
    CSMFunction oprtor;
    char op_char;

public:
    CompositeSquareMatrix();
    virtual ~CompositeSquareMatrix(){};
    CompositeSquareMatrix(const SquareMatrix &opr1, const SquareMatrix &opr2, const CSMFunction& optr, char c);
    CompositeSquareMatrix(const CompositeSquareMatrix &m);
    CompositeSquareMatrix(CompositeSquareMatrix &&m);
    CompositeSquareMatrix& operator=(const CompositeSquareMatrix &m);
    CompositeSquareMatrix& operator=(CompositeSquareMatrix &&m);
    bool operator==(const CompositeSquareMatrix &m);
    SquareMatrix* clone() const;
    void print(std::ostream& os) const;
    std::string toString() const;
    ConcreteSquareMatrix evaluate(const Valuation& val) const; /*! !*/
};


#endif // COMPOSITESQUAREMATRIX_H_INCLUDED


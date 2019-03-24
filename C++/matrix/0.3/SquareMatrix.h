#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED

#include <ostream>
#include <string>
#include "element.h"

class ConcreteSquareMatrix;

class SquareMatrix {

public:
    virtual ~SquareMatrix(){};
    virtual SquareMatrix* clone() const = 0;
    virtual void print(std::ostream &os) const = 0;
    virtual std::string toString() const = 0;
    virtual ConcreteSquareMatrix evaluate (const Valuation& valuation) const = 0;

};
using uniq_sqm_ptr = std::unique_ptr<SquareMatrix>;
#endif // SQUAREMATRIX_H_INCLUDED

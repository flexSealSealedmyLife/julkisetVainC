#include "ConcreteSquareMatrix.h"
#include "CompositeSquareMatrix.h"
#include "stdexcept"
#include "limits"
#include <ostream>
#include <memory>
#include <map>



CompositeSquareMatrix::CompositeSquareMatrix():oprnd1(nullptr), oprnd2(nullptr) {

}


CompositeSquareMatrix::CompositeSquareMatrix(const SquareMatrix &opr1, const SquareMatrix &opr2, const CSMFunction &optr, char c) {

    oprnd1 = uniq_sqm_ptr(opr1.clone());
    oprnd2 = uniq_sqm_ptr(opr2.clone());
    oprtor = optr;
    op_char = c;

}

CompositeSquareMatrix::CompositeSquareMatrix(const CompositeSquareMatrix &m) {

    oprnd1 = uniq_sqm_ptr(m.oprnd1 -> clone());
    oprnd2 = uniq_sqm_ptr(m.oprnd2 -> clone());
    oprtor = m. oprtor;
    op_char = m.op_char;

}

CompositeSquareMatrix::CompositeSquareMatrix(CompositeSquareMatrix &&m) {

    oprnd1 = std::move(m.oprnd1);
    oprnd2 = std::move(m.oprnd2);
    oprtor = m.oprtor;
    op_char = m.op_char;

}



CompositeSquareMatrix& CompositeSquareMatrix::operator=(const CompositeSquareMatrix &m) {

    if(this == &m)
        return *this;

    oprnd1 = uniq_sqm_ptr(m.oprnd1 -> clone());
    oprnd2 = uniq_sqm_ptr(m.oprnd2 -> clone());
    oprtor = m.oprtor;
    op_char = m.op_char;

    return *this;

}

CompositeSquareMatrix& CompositeSquareMatrix::operator=(CompositeSquareMatrix &&m) {

    if(this == &m)
        return *this;

    oprnd1 = std::move(m.oprnd1);
    oprnd2 = std::move(m.oprnd2);
    oprtor = m. oprtor;
    op_char = m.op_char;
    return *this;

}

bool CompositeSquareMatrix::operator==(const CompositeSquareMatrix &m) {

    return toString() == m.toString();
}

SquareMatrix* CompositeSquareMatrix::clone() const {

    return new CompositeSquareMatrix(*this);

}

void CompositeSquareMatrix::print(std::ostream& os) const {

    os << toString();
}

std::string CompositeSquareMatrix::toString() const {

    std::string first = oprnd1 -> toString();
    std::string second = oprnd2 -> toString();
    return ((first + op_char + second));
}

ConcreteSquareMatrix CompositeSquareMatrix::evaluate(const Valuation& valuation) const {

    ConcreteSquareMatrix first = oprnd1 -> evaluate(valuation); //vaikuttaako onko valuation vai Valuation
    ConcreteSquareMatrix second = oprnd2 -> evaluate(valuation);
    return oprtor(first, second);
}



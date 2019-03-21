#include "IntElement.h"

IntElement::IntElement() {
}

IntElement::~IntElement() {
}

IntElement::IntElement(int v) {

    val = v;

}

int IntElement::getVal() const {
    return val;
}

void IntElement::setVal(int v) {
    val = v;
}

IntElement& IntElement::operator+=(const IntElement& i) {
    val += i.val;
    return(*this);
}

IntElement& IntElement::operator-=(const IntElement& i) {
    val -= i.val;
    return(*this);
}

IntElement& IntElement::operator*=(const IntElement& i) {
    val *= i.val;
    return(*this);
}

IntElement operator +(const IntElement& first, const IntElement& second) {
    IntElement temp = first;
    temp+=second;
    return temp;
}
IntElement operator *(const IntElement& first, const IntElement& second) {
    IntElement temp = first;
    temp+=second;
    return temp;
}

#include "element.h"

IntElement::IntElement() {  /*! Constructor !*/
}

IntElement::~IntElement() {  /*! Deconstructor !*/
}

Element* IntElement::clone() const {  /*! Used to clone IntElement !*/

    IntElement *pElem = new IntElement(val);
    return pElem;
}

IntElement::IntElement(int v) {  /*! Storing the val variable !*/

    val = v;

}

int IntElement::getVal() const {  /*! Gets the value of val !*/
    return val;
}

void IntElement::setVal(int v) {  /*! Sets the value of val !*/
    val = v;
}

IntElement& IntElement::operator+=(const IntElement& i) {  /*! Uses the + operator !*/
    val += i.val;
    return(*this);
}

IntElement& IntElement::operator-=(const IntElement& i) {  /*! Uses the - operator !*/
    val -= i.val;
    return(*this);
}

IntElement& IntElement::operator*=(const IntElement& i) {  /*! Uses the * operator !*/
    val *= i.val;
    return(*this);
}

std::string IntElement::toString() const{  /*! Produces string !*/

    return std::to_string(val);
}

int IntElement::evaluate(const Valuation& valu) const{

    return val;
}

bool IntElement::operator==(const IntElement& i) const {  /*! This tells if the variable match !*/

    return getVal() == i.getVal();
}


IntElement operator+(const IntElement& first, const IntElement& second) {  /*! Tells how to use + operator !*/
    IntElement temp = first;
    temp+=second;
    return temp;
}
IntElement operator*(const IntElement& first, const IntElement& second) {  /*! Tells how to use * operator !*/
    IntElement intelem(first.getVal());
    intelem*=second;
    return intelem;
}

IntElement operator-(const IntElement& first, const IntElement& second) {  /*! Tells how to use - operator !*/
    IntElement temp = first;
    temp-=second;
    return temp;
}

std::ostream& operator<<(std::ostream &os, const IntElement &el) {  /*! Tells how to use << operator!*/
    os << el.getVal();
    return os;
}

VariableElement::VariableElement():var('x') {
}

VariableElement::VariableElement(char v) {
    var=v;
}

VariableElement::~VariableElement() {
}

char VariableElement::getVal() const {
    return var;
}

void VariableElement::setVal(char v) {
    var=v;
}

Element* VariableElement::clone() const {
    return new VariableElement(var);
}

int VariableElement::evaluate(const Valuation& val) const {

    int retVal = 0;
    auto iter = val.find(var);
    if(iter == val.end()) {
        throw std::exception();
    }
    else {
        retVal = iter -> second;
    }
    return retVal;
}

bool VariableElement::operator==(const VariableElement &ve) const {
    return var == ve.getVal();
}
std::string VariableElement::toString() const{
    std::string s="";
    s+=var;
    return s;
}

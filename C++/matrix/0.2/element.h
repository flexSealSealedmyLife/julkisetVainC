#ifndef INTELEMENT_H_INCLUDED
#define INTELEMENT_H_INCLUDED
#include <ostream>
#include <memory>
#include <map>

 /*! This is the header file for element file !*/

using Valuation = std::map<char,int>;  /*! Using Valuation !*/

class Element {

public:
    virtual ~Element(){};
    virtual Element* clone() const = 0;
    virtual std::string toString()const = 0;
    virtual int evaluate(const Valuation& valu) const = 0;
};

class IntElement : public Element {
private:
    int val;
public:
    IntElement(int v);
    int getVal() const;
    void setVal(int v);
    IntElement& operator+=(const IntElement& i);
    IntElement& operator-=(const IntElement& i);
    IntElement& operator*=(const IntElement& i);
    bool operator==(const IntElement& i) const;
    IntElement();
    ~IntElement();
    Element* clone() const;
    std::string toString() const;
    int evaluate(const Valuation& valu) const;
};

class VariableElement : public Element {

private:
    char var;
public:
    VariableElement();
    VariableElement(char c);
    virtual ~VariableElement();
    char getVal() const;
    void setVal(char v);
    bool operator==(const VariableElement& another) const;
    Element* clone() const;
    int evaluate(const Valuation& val) const;
    std::string toString() const;
};

IntElement operator-(const IntElement& first, const IntElement& second);
IntElement operator+(const IntElement& first, const IntElement& second);
IntElement operator*(const IntElement& first, const IntElement& second);
std::ostream& operator<<(std::ostream &os, const IntElement &el);

typedef std::unique_ptr<IntElement> uniq_intelem_pointer;
typedef std::unique_ptr<Element> uniq_elem_ptr;
#endif // INTELEMENT_H_INCLUDED

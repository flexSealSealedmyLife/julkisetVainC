#ifndef INTELEMENT_H_INCLUDED
#define INTELEMENT_H_INCLUDED

class IntElement{
private:
    int val;
public:
    IntElement(int v);
    int getVal() const;
    void setVal(int v);
    IntElement& operator+=(const IntElement& i);
    IntElement& operator-=(const IntElement& i);
    IntElement& operator*=(const IntElement& i);
    IntElement();
    ~IntElement();
};


IntElement operator+(const IntElement& first, const IntElement& second);
IntElement operator*(const IntElement& first, const IntElement& second);
#endif // INTELEMENT_H_INCLUDED

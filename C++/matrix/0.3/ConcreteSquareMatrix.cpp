#include "ConcreteSquareMatrix.h"
#include "stdexcept"
#include "limits"



ConcreteSquareMatrix::ConcreteSquareMatrix() {
    n = 0;

}

ConcreteSquareMatrix::~ConcreteSquareMatrix() {

}

ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string& str) {


    std::stringstream inputstream(str);
    char c;
    int row_num = 0;
    int col = 0;
    int number;
    n = std::numeric_limits<int>::max();



    inputstream >> c;
    if(!inputstream.good() || c!= '[') {
      //  std::cout << "tultiin false3"  << std::endl;
        throw(std::invalid_argument("Invalid initial string1"));
    }

    while (row_num < n) { //käy arrayta lapi kunnes se on kayty kokonaan lapi
            inputstream >> c;
            std::vector<uniq_intelem_pointer> row;
            if(!inputstream.good() || c!= '[') {//Testattu toimivaksi
                //std::cout << "tultiin false2"  << std::endl;
               // std::cout << c << std::endl;
                throw(std::invalid_argument("Invalid initial string2"));
            }
            while (c!=']') { //jatka kunnes saavutaan ]
                inputstream >> number >> c;
                if(!inputstream.good()) {
                    throw(std::invalid_argument("Invalid initial string3"));
                }
                if(c==',') {
                    col++;
                }else{
                    if(c==']'){
                        col++;
                        if(n==std::numeric_limits<int>::max()) {
                            n = col;
                        }else{
                            if(col != n)
                                throw(std::invalid_argument("Invalid initial string4"));
                        }
                    }else{
                        throw(std::invalid_argument("Invalid initial string5"));
                    }
                }
                row.push_back(uniq_intelem_pointer (new IntElement(number)));
            }
            elements.push_back(std::move(row));
            row_num++;
        }

        inputstream >> c;
        if(!inputstream.good() || c!=']') {
            throw(std::invalid_argument("Invalid initial string6"));
        }

        inputstream >> c;
        if(!inputstream.eof()) {
            throw(std::invalid_argument("Invalid initial string7"));
        }

}

ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix& m) {

    n = m.n;

    for(auto &m_row:m.elements) {
        std::vector<uniq_intelem_pointer> row;
        for(auto &elem:m_row) {
            row.push_back(uniq_intelem_pointer(
                          static_cast<IntElement*>(elem -> clone())));
        }
        elements.push_back(std::move(row));
    }
}

/*ConcreteSquareMatrix::ConcreteSquareMatrix(ConcreteSquareMatrix &&m):n(m.n),elements(std::move(m.elements)) {
}*/

ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(const ConcreteSquareMatrix &m) {

    if (this == &m)
        return (*this);

    n= m.n;
    elements.clear();

    for(auto &m_row:m.elements) {
        std::vector<uniq_intelem_pointer> row;
        for(auto &elem:m_row) {
            row.push_back(uniq_intelem_pointer(
                          static_cast<IntElement*>(elem -> clone())));
        }
        elements.push_back(std::move(row));
    }
    return (*this);
}

ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(ConcreteSquareMatrix &&m) {
    n = m.n;
    std::swap(elements, m.elements);
    return(*this);
}



ConcreteSquareMatrix& ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix& m) {  /*!  Calculates and returns the values it got !*/
    if (n != m.n)
        throw(std::out_of_range("Dimension not compatible"));

            auto row1= elements.begin();
            auto row2= m.elements.begin();

            while (row1 != elements.end()) {
                std::transform(row1->begin(), row1->end(),row2->begin(), row1->begin(),
                               [] (const uniq_intelem_pointer &i1, const uniq_intelem_pointer &i2) {
                                    uniq_intelem_pointer ptElem = uniq_intelem_pointer(new IntElement(i1->getVal()-i2->getVal()));
                               return ptElem;
                               });
                            row1++;
                            row2++;
            }


    return(*this);
}

ConcreteSquareMatrix& ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix& m) {  /*! Calculates and returns the values it got !*/

    if (n != m.n)
        throw(std::out_of_range("Dimension not compatible"));

        std::vector<std::vector<uniq_intelem_pointer>> new_elements;
        ConcreteSquareMatrix trans = m.transpose();
           for(auto &row: elements) {
            std::vector<uniq_intelem_pointer> new_row;
            for (auto &trans_row: trans.elements ) {
                uniq_intelem_pointer prod= std::inner_product(row.begin(), row.end(), trans_row.begin()
                                                        ,uniq_intelem_pointer(new IntElement(0)),
                                                        [](const uniq_intelem_pointer &i1, const uniq_intelem_pointer &i2) {
                                                        uniq_intelem_pointer ptElem = uniq_intelem_pointer(new IntElement(i1->getVal()+i2->getVal()));
                                                        return ptElem;
                                                        },
                                                        [](const uniq_intelem_pointer &i1, const uniq_intelem_pointer &i2) {
                                                        uniq_intelem_pointer ptElem = uniq_intelem_pointer(new IntElement(i1->getVal()*i2->getVal()));
                                                        return ptElem;
                                                        }
                                                        );
                                    new_row.push_back(std::move(prod));
                                }
                                new_elements.push_back(std::move(new_row));
                            }
                            std::swap(elements, new_elements);
                            return (*this);
}

ConcreteSquareMatrix& ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix& m) {
    if (n != m.n)
        throw(std::out_of_range("Dimension not compatible"));

    auto row1= elements.begin();
    auto row2= m.elements.begin();

    while (row1 != elements.end()) {
        std::transform(row1->begin(), row1->end(),row2->begin(), row1->begin(),
                       [] (const uniq_intelem_pointer &i1, const uniq_intelem_pointer &i2) {
                            uniq_intelem_pointer ptElem = uniq_intelem_pointer(new IntElement(i1->getVal()+i2->getVal()));
                       return ptElem;
                       });
                    row1++;
                    row2++;
    }

    return(*this);
}

bool ConcreteSquareMatrix::operator==(const ConcreteSquareMatrix &m) const {
    if ( n!= m.n)
        return false;


    auto row1 = elements.begin();
    auto row2 = m.elements.begin();

    while(row1 != elements.end()) {

        auto elem1 = row1->begin();
        auto elem2 = row2->begin();

        while(elem1 != row1->end()) {
            if(!(**elem1 == **elem2))
                return false;
            elem1++;
            elem2++;
        }
        row1++;
        row2++;
    }
    return true;


}

ConcreteSquareMatrix ConcreteSquareMatrix::transpose() const {

 ConcreteSquareMatrix transu;

 transu.n = n;
 transu.elements = std::vector<std::vector<uniq_intelem_pointer>>(n);
 int col_num = 0;
 for (auto &row: elements ) {
    for (auto &elements: row) {
        transu.elements[col_num].push_back(uniq_intelem_pointer(
                                                                static_cast<IntElement*>(elements -> clone())));
        col_num = (col_num+1)%n;
    }
 }
    return transu;
}

std::string ConcreteSquareMatrix::toString() const {

    std::stringstream outputstream;
    //tulostetaan matriisi stringstreamiin
    outputstream << "[";
    for(auto& row: elements) {
        outputstream << "[";
        bool first = true;
        for(auto& elem:row) {
            if(!first)
                outputstream << ",";
            outputstream << *elem;
            first = false;
        }
        outputstream << "]";
    }
    outputstream << "]";
    //print(ss);
    return outputstream.str();
}

void ConcreteSquareMatrix::print(std::ostream &os) const{
    os << toString();
}

ConcreteSquareMatrix operator+(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second) {
    ConcreteSquareMatrix temp = first;
    temp+=second;
    return(temp);
}

ConcreteSquareMatrix operator-(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second) {
    ConcreteSquareMatrix temp = first;
    temp-=second;
    return(temp);
}

ConcreteSquareMatrix operator*(const ConcreteSquareMatrix& first, const ConcreteSquareMatrix& second) {
    ConcreteSquareMatrix temp = first;
    temp*=second;
    return(temp);
}

SquareMatrix* ConcreteSquareMatrix::clone() const {

    return new ConcreteSquareMatrix(*this);
}


ConcreteSquareMatrix ConcreteSquareMatrix::evaluate (const Valuation& valuation) const {

    return *this;
}

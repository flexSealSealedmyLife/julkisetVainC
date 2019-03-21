#include "SymbolicSquareMatrix.h"
#include "stdexcept"
#include "limits"



SymbolicSquareMatrix::SymbolicSquareMatrix() {
    n = 0;

}

SymbolicSquareMatrix::~SymbolicSquareMatrix() {

}
SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string& str_m){

    std::stringstream inputstr{};
    inputstr << str_m;
    n = std::numeric_limits<int>::max();
    char c1;
    //int a;
    //int col = 0;
    int row_num = 0;

    inputstr >> c1;
    if(c1!='[') throw(std::invalid_argument("Invalid init string"));

    inputstr >> c1;
    if(!inputstr.good()) throw(std::invalid_argument("Invalid init string"));

    while(inputstr.good() && c1 != ']'){
        std::vector<uniq_elem_ptr> row;

        if(!inputstr.good() || c1 !='[') throw(std::invalid_argument("Invalid init string"));
        int col = 0;
        while(c1 != ']'){
            char symbol;
            inputstr >> symbol;

            if(isdigit(symbol)){
                row.push_back(uniq_elem_ptr(new IntElement(symbol)));
            }else{
            // JOS EI ONNISTU LUKU
            // Push the element to row vector
            row.push_back(uniq_elem_ptr(new VariableElement(symbol)));
            }
            if(c1==','){
                col++;
            }
            else{
                if(c1==']'){
                    col++;
                    if(n==std::numeric_limits<int>::max()){
                        n = col;
                    }
                    else{
                        if(col!=n)
                            throw(std::invalid_argument("Invalid init string"));
                    }
                }
                else{
                    throw(std::invalid_argument("Invalid init string"));
                }
            }
        }
        row_num++;

        // Push the row into elements
        elements.push_back(std::move(row));
    }

    inputstr >> c1;
    if(!inputstr.good() || c1!=']'){
        throw(std::invalid_argument("Invalid init string"));
    }
    inputstr >> c1;
    if(!inputstr.eof()){
        throw(std::invalid_argument("Invalid init string"));
    }
}

SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(const SymbolicSquareMatrix &m) {

    if (this == &m)
        return (*this);

    n= m.n;
    elements.clear();

    for(auto &m_row:m.elements) {
        std::vector<uniq_elem_ptr> row;
        for(auto &elem:m_row) {
            row.push_back(uniq_elem_ptr(elem -> clone()));
        }
        elements.push_back(std::move(row));
    }
    return (*this);
}



SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(SymbolicSquareMatrix &&m) {
    n = m.n;
    std::swap(elements,m.elements);
    return (*this);

}

bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix& m) const {
    if(n!=m.n)
        return false;

    return (this->toString() == m.toString());

}

SymbolicSquareMatrix SymbolicSquareMatrix::transpose() const {

    SymbolicSquareMatrix tr;
    tr.n = n;
    tr.elements = std::vector<std::vector<uniq_elem_ptr>>(n);
    int col_num = 0;
    for(auto &row: elements) {
        for(auto &element: row) {
            tr.elements[col_num].push_back(uniq_elem_ptr(element->clone()));
            col_num = (col_num+1)%n;
        }
    }
    return tr;
}

std::string SymbolicSquareMatrix::toString() const {

    std::stringstream outputstream;
    //tulostetaan matriisi stringstreamiin
    outputstream << "[";
    for(auto& row: elements) {
        outputstream << "[";
        bool first = true;
        for(auto &element:row) {
            if(!first){
                outputstream << ",";
        }
            first = false;
            outputstream << element -> toString();
        }
        outputstream << "]";
    }
    outputstream << "]";
    return outputstream.str();
}

ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation& val) const {

    ConcreteSquareMatrix csm;
    csm.n = n;

    for(auto &row: elements) {
        std::vector<uniq_intelem_pointer> csmrow;
        for (auto &element: row) {
            csmrow.push_back(uniq_intelem_pointer(new IntElement(element->evaluate(val))));
        }
        csm.elements.push_back(std::move(csmrow));
    }
    return csm;
}


void SymbolicSquareMatrix::print(std::ostream &os) const {
    os << toString();
}

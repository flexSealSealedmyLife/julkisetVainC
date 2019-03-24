#include "SymbolicSquareMatrix.h"
#include "stdexcept"
#include "limits"



SymbolicSquareMatrix::SymbolicSquareMatrix() {
    n = 0;

}

SymbolicSquareMatrix::~SymbolicSquareMatrix() {

}
SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string& str_m){
    std::stringstream ss{};
    ss << str_m;
    int x = -1;
    n = std::numeric_limits<int>::max();
    char c = 0;
    int rows = 0;

    ss >> c;
    if(c!='[')
        throw(std::invalid_argument("Invalid init string 1"));

    ss >> c;
    if(!ss.good())
        throw(std::invalid_argument("Invalid init string 2"));

    while(ss.good() && c != ']'){
        std::vector<uniq_elem_ptr> row;
        if(!ss.good() || c != '[')
            throw(std::invalid_argument("Invalid init string 3"));
        int cols = 0;
        while(c != ']'){
            char variable;
            ss >> variable;
            if(!ss.good())
                throw(std::invalid_argument("Invalid init string 4"));
            ss >> c;
            if(!ss.good() || (c != ',' && c != ']'))
                throw(std::invalid_argument("Invalid init string 5"));
            if(isdigit(variable)){
                int value = variable - '0';
                row.push_back(uniq_elem_ptr(new IntElement(value)));
            }else{
                row.push_back(uniq_elem_ptr(new VariableElement(variable)));
                }
            cols++;
        }
        if(x == -1){
            x = cols;
        }
        else if(x != cols){
            throw(std::invalid_argument("Invalid init string 6"));
        }
        ss >> c;
        if(!ss.good() || (c != '[' && c!= ']'))
            throw(std::invalid_argument("Invalid init string 7"));
        elements.push_back(std::move(row));
        rows++;
    }

    if(x != rows)
        throw(std::invalid_argument("Invalid init string 8"));
    std::string tail{};
    ss >> tail;
    if(tail.size() != 0)
        throw(std::invalid_argument("Invalid init string 9"));
    n = x;
}

SymbolicSquareMatrix::SymbolicSquareMatrix(const SymbolicSquareMatrix& m) {

    n= m.n;


    for(auto &m_row:m.elements) {
        std::vector<uniq_elem_ptr> row;
        for(auto &elem:m_row) {
            row.push_back(uniq_elem_ptr(elem -> clone()));
        }
        elements.push_back(std::move(row));
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

SquareMatrix* SymbolicSquareMatrix::clone() const{
    return new SymbolicSquareMatrix(*this);
}


void SymbolicSquareMatrix::print(std::ostream &os) const {
    os << toString();
}

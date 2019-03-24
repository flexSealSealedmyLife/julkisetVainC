#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

#include "ConcreteSquareMatrix.h"
#include "SymbolicSquareMatrix.h"
#include "CompositeSquareMatrix.h"

/*! This is a test file for the concreteSquareMatrix !*/

TEST_CASE("ConcreteSquareMatrix checking", "[matrix]") {

    ConcreteSquareMatrix testi1 ("[[5,-6][4,3]]"); /*! Inserting values to test !*/
    ConcreteSquareMatrix testi2 ("[[1,7][-2,5]]"); /*! Inserting values to test !*/
    CHECK(testi1.toString()=="[[5,-6][4,3]]"); /*! Checking if the values and toString worked !*/
    CHECK(testi2.toString()=="[[1,7][-2,5]]"); /*! Checking if the values and toString worked !*/
    ConcreteSquareMatrix testi3 = testi1 + testi2; /*! Testing the + operator !*/
    ConcreteSquareMatrix testi4 = testi1 - testi2; /*! Testing the - operator !*/
    ConcreteSquareMatrix testi5 = testi1 * testi2; /*! Testing the * operator !*/
    CHECK(testi3.toString()=="[[6,1][2,8]]"); /*! Checking if operators worked !*/
    CHECK(testi4.toString()=="[[4,-13][6,-2]]"); /*! Checking if operators worked !*/
    CHECK(testi5.toString()=="[[17,5][-2,43]]"); /*! Checking if operators worked !*/
}

TEST_CASE("CompositeSquareMatrix checking", "[matrix]") {

    Valuation valua;
    valua.insert (std::pair<char, int>('a', 1));
    valua.insert (std::pair<char, int>('b', 2));
    valua.insert (std::pair<char, int>('c', 3));
    valua.insert (std::pair<char, int>('d', 4));

    ConcreteSquareMatrix conc("[[1,3][5,8]]");
    SymbolicSquareMatrix symbo1("[[a,b][c,d]]");
    SymbolicSquareMatrix symbo2("[[1,b][2,d]]");
    SymbolicSquareMatrix symbo3("[[-10,b][-20,d]]");
    CompositeSquareMatrix com1(symbo1,symbo2,std::plus<ConcreteSquareMatrix>(), '+');
    CompositeSquareMatrix conc2(conc,com1,std::multiplies<ConcreteSquareMatrix>(), '*');
    ConcreteSquareMatrix res = conc2.evaluate(valua);
    conc2.print(std::cout);
    std::cout << std::endl;
    std::cout << conc.evaluate(valua).toString() << std::endl;
    CHECK(res.toString()=="[[17,28][50,84]]");




}

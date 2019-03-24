#include "catch.hpp"
#include <string>

#include "SymbolicSquareMatrix.h"

/*! This is a test file for the SymbolicSquareMatrix !*/



TEST_CASE("SymbolicSquareMatrix checking", "[matrix]") {

    SymbolicSquareMatrix valkyrie("[[x,4][y,4]]");
    CHECK(valkyrie.toString()=="[[x,4][y,4]]");
    SymbolicSquareMatrix jackal("[[x,1,3][f,g,3][h,3,3]]");
    CHECK(jackal.toString()=="[[x,1,3][f,g,3][h,3,3]]");
    CHECK_THROWS(SymbolicSquareMatrix("!¡NWãx*ñ­Ü┼=║?xÐ♥£*5♫g"));
    CHECK_THROWS(SymbolicSquareMatrix("[]"));
    CHECK_THROWS(SymbolicSquareMatrix(" "));
    CHECK_THROWS(SymbolicSquareMatrix("[["));
    CHECK_THROWS(SymbolicSquareMatrix("]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[1,5;3a][5,3,4]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1;1][3;4]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,3,3][3,3,3][7,8,3]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,3,3][3,3,3][7,8,3]][3,3,3]"));
    CHECK(valkyrie.transpose().toString()=="[[x,y][4,4]]");
    CHECK_FALSE(valkyrie.transpose().toString()=="[[4,y][4,4]]");
    SymbolicSquareMatrix mira;
    CHECK(mira.toString() == "[]");
    SymbolicSquareMatrix ash("[[2,x][y,8]]");
    CHECK(ash.toString() == "[[2,x][y,8]]");
    mira = ash;
    CHECK(mira.toString() == "[[2,x][y,8]]");
    CHECK(mira == ash);
    Valuation blackbeard;
    blackbeard.insert(std::pair<char,int>('x',2));
    blackbeard.insert(std::pair<char,int>('z',9));
    blackbeard.insert(std::pair<char,int>('u',110));
    ConcreteSquareMatrix jager;
    SymbolicSquareMatrix hibana("[[3,2,x][z,4,3][4,2,u]]");
    jager = hibana.evaluate(blackbeard);
    CHECK(jager.toString()=="[[3,2,6][7,4,3][4,2,110]]");
    Valuation montagne;
    montagne.insert(std::pair<char,int>('a',3));
    montagne.insert(std::pair<char,int>('b',9));
    montagne.insert(std::pair<char,int>('c',1));
    ConcreteSquareMatrix frost;
    SymbolicSquareMatrix lion("[[a,2,6][b,4,3][4,2,c]]");
    frost = lion.evaluate(montagne);
    CHECK(frost.toString()=="[[3,2,6][9,4,3][4,2,1]]");
}


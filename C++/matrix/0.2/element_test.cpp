
#include "catch.hpp"

#include "element.h"

 /*! These are the test cases for IntElement.cpp. First one places a value of 5 and it is then checked if the value was placed in correct spot
 Next one uses function to set value of 6 and then it is checked with a getVal function.
 Then we give value of 16 to ielem2 and add it to ielem and check that the value is 22. finally we * the numbers and check for the value.
  !*/

TEST_CASE ("IntElement checking", "[matrix]") {
    IntElement ielem(5);
    CHECK(ielem.getVal()==5);
    ielem.setVal(6);
    CHECK(ielem.getVal()==6);
    IntElement ielem2(16);
    ielem += ielem2;
    CHECK(ielem.getVal()==22);
    ielem *= ielem2;
    CHECK(ielem.getVal()==352);

     /*! Test cases for variableElement. Pairing and testing the value to make sure  !*/

    VariableElement m('x');
    VariableElement mm('z');
    VariableElement mmm('u');
    Valuation valu;
    valu.insert (std::pair<char, int> ('y', 10));
    valu.insert (std::pair<char, int> ('x', 35));
    valu.insert (std::pair<char, int> ('z', 20));
    CHECK(m.evaluate(valu)==35);

}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "henkilot.h"


TEST_CASE ("henkilot testing") {


    opiskelija kivi("233", "tuomas", "sela", "34", "130000-222W");
    CHECK (kivi.getHetu() == "130000-222W");
    CHECK (kivi.getEtuNimi() == "tuomas" );
    CHECK (kivi.getSukunimi() == "sela");
    CHECK (kivi.getNum() == "233");
    CHECK (kivi.getIka() == "34");


    tyontekija puro("123","Seppo", "Tale", "121209-482s", "32999", "22");
    CHECK (puro.getHetu() == "121209-482s");
    CHECK (puro.getmEtuNimi() == "Seppo" );
    CHECK (puro.getSukunimi() == "Tale");
    CHECK (puro.getNum() == "123");
    CHECK (puro.getIka() == "22");

    Singleton* s = Singleton::getInstance();
    s->tervetuloa();

}



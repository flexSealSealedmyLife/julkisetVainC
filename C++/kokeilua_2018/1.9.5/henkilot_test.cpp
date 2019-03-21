/*#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "henkilot.h"


TEST_CASE ("henkilot testing") {

	henkilot kivi;
	kivi.setTiedot("Pauli", "Kyrsy", "130000-213W" , 34000.23000f, 5);
	CHECK( kivi.printHenkiloIka() == 5);
	CHECK( kivi.printHenkiloHetu() == "130000-213W");
	CHECK( kivi.printHenkiloEtuNimi() == "Pauli");
	CHECK( kivi.printHenkiloSukuNimi() == "Kyrsy");
	CHECK( kivi.printPalkka() == 34000.23000f);

	henkilot kivi2;
	kivi2.setTiedot("Seksiseppo", "Taalasmaa", "238593-482T", 35000.23000f, 23);
	CHECK( kivi2.printHenkiloIka() == 23);
	CHECK( kivi2.printHenkiloHetu() == "238593-482T");
	CHECK( kivi2.printHenkiloEtuNimi() == "Seksiseppo");
	CHECK( kivi2.printHenkiloSukuNimi() == "Taalasmaa");
	CHECK( kivi2.printPalkka() == 35000.23000f);

}

*/

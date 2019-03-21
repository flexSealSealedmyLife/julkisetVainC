#include "henkilot.h"
#include <iostream>

henkilot::henkilot() {


    std::cout << "\n\n\nPlip Plup. -HenkiloOlio Luotu.-" << std::endl;

}

henkilot::~henkilot() {

}

/* ********************************************************************************* */

tyontekija::tyontekija(int henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, float palkanmaara, int henkiloIka){

    std::cout << "Plip Plup. Bzzz. -TyontekijaOlio Luotu.-\n\n\n" << std::endl;
    henkiloNumero = henkiloNum;
    etuNimi = henkiloEtunimi;
	sukuNimi = henkiloSukunimi;
	palkka = palkanmaara;
	ika = henkiloIka;
	henkiloHetu = hetu;
}

tyontekija::~tyontekija(){
}

std::string tyontekija::printHenkiloHetu() {


    std::cout << "Henkilon hetu on " << henkiloHetu << "." << std::endl;
	return henkiloHetu;
}

float tyontekija::printPalkka() {

    return palkka;
}

std::string tyontekija::printHenkiloEtuNimi() {

    std::cout << "Henkilon etuNimi on " << etuNimi << "." << std::endl;
	return etuNimi;
}


std::string printHenkiloEtuNimi();
/* ********************************************************************************* */



opiskelija::opiskelija(int opiskelijaNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, int henkiloIka) {

    opiskelijaNumero = opiskelijaNum;
    etuNimi = henkiloEtunimi;
	sukuNimi = henkiloSukunimi;
	ika = henkiloIka;
	henkiloHetu = hetu;


}

opiskelija::~opiskelija() {

}

opiskelija::printOpiskelijaNumero() {

    std::cout
			<< "Henkilon opiskelijanumero on " << opiskelijaNumero
			<< "." << std::endl;

    return opiskelijaNumero;
}

std::string opiskelija::printHenkiloEtuNimi() {

    std::cout << "Henkilon etuNimi on " << etuNimi << "." << std::endl;
	return etuNimi;
}

#include "henkilot.h"
#include <iostream>

henkilot::henkilot() {


    std::cout << "\n\n\nPlip Plup. -HenkiloOlio Luotu.-" << std::endl;

}

henkilot::~henkilot() {
}

void henkilot::printInfo() {

    std::cout << "Henkilon hetu on " << henkiloHetu << "." << std::endl;
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

void tyontekija::printInfo() {

    std::cout << "Henkilon hetu on " << henkiloHetu << "." << std::endl;
    std::cout << "Henkilon tyomiesnumero on " << henkiloNumero << "." << std::endl;

}

/* ********************************************************************************* */



opiskelija::opiskelija(int opiskelijaNum, std::string henkiloEtunimi, std::string henkiloSukunimi, int henkiloIka, std::string hetu) {

    opiskelijaNumero = opiskelijaNum;
    etuNimi = henkiloEtunimi;
	sukuNimi = henkiloSukunimi;
	ika = henkiloIka;
	henkiloHetu = hetu;



}

opiskelija::~opiskelija() {

}

void opiskelija::printInfo() {

   std::cout << "Henkilon hetu on " << henkiloHetu << "." << std::endl;
   std::cout << "Henkilon opiskelijanumero on " << opiskelijaNumero << "." << std::endl;

}

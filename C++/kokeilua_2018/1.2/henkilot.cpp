        #include "henkilot.h"
#include <iostream>

henkilot::henkilot() {
}

henkilot::~henkilot() {
}

void henkilot::printInfo() {

    std::cout << "Henkilon hetu on " << henkiloHetu << "." << std::endl;
}

std::string henkilot::getHetu() {

    return henkiloHetu;
}

/* ********************************************************************************* */

tyontekija::tyontekija(int henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, float palkanmaara, int henkiloIka){

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

    std::cout << "Tyontekijan hetu on " << henkiloHetu << "." << std::endl;
    //std::cout << "Tyontekijan tyomiesnumero on " << henkiloNumero << ".\n" << std::endl;

}

std::string tyontekija::getHetu() {

    return henkiloHetu;
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

   std::cout << "Opiskelijan hetu on " << henkiloHetu << "." << std::endl;
   //std::cout << "Opiskelijan opiskelijanumero on " << opiskelijaNumero << ".\n" << std::endl;

}

std::string opiskelija::getHetu() {

    return henkiloHetu;
}

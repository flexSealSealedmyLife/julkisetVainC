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

void henkilot::muokkaaTietoja() {


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

void tyontekija::muokkaaTietoja() {

    virhe:

    std::cout << "\nMitas muokataan?\n 1 - etunimea\n2 - sukunimea\n3 - opiskelijanumeroa.\nPaina 4 poistuaksesi.\n";
    std::cin >> valinta;


    if (valinta == "1") {
            std::cout << "\nAnna henkilon uusi etunimi.\n";
            std::cin >> etuNimi;
            std::cout << "\nHenkilon uusi etunimi on: " << etuNimi << ".";

    }else if (valinta == "2") {
            std::cout << "\nAnna henkilon uusi sukunimi.\n";
            std::cin >> sukuNimi;
            std::cout << "\nHenkilon uusi sukunimi on: " << sukuNimi << ".";

    }else if (valinta == "3") {
            std::cout << "\nAnna henkilon uusi tyaukkonumero.\n";
            std::cin >> henkiloNumero;
            std::cout << "\nHenkilon uusi tyaukkonumero on: " << henkiloNumero << ".";

    }else if (valinta == "4") {
            std::cout << "\nLopetataan henkilon tietojen muokkaaminen.\n";
    }else{
        std::cout << "\nTapahtui virhe, yrita uudelleen.\n";
        goto virhe;
    }

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

void opiskelija::muokkaaTietoja() {

    virhe:

    std::cout << "\nMitas muokataan?\n 1 - etunimea\n2 - sukunimea\n3 - opiskelijanumeroa.\nPaina 4 poistuaksesi.\n";
    std::cin >> valinta;


    if (valinta == "1") {
            std::cout << "\nAnna henkilon uusi etunimi.\n";
            std::cin >> etuNimi;
            std::cout << "\nHenkilon uusi etunimi on: " << etuNimi << ".";

    }else if (valinta == "2") {
            std::cout << "\nAnna henkilon uusi sukunimi.\n";
            std::cin >> sukuNimi;
            std::cout << "\nHenkilon uusi sukunimi on: " << sukuNimi << ".";

    }else if (valinta == "3") {
            std::cout << "\nAnna henkilon uusi opiskelijanumero.\n";
            std::cin >> opiskelijaNumero;
            std::cout << "\nHenkilon uusi opiskelijanumero on: " << opiskelijaNumero << ".";

    }else if (valinta == "4") {
            std::cout << "\nLopetataan henkilon tietojen muokkaaminen.\n";
    }else{
        std::cout << "\nTapahtui virhe, yrita uudelleen.\n";
        goto virhe;
    }

}

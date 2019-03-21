        #include "henkilot.h"
#include <iostream>

henkilot::henkilot() {
}

henkilot::~henkilot() {
}
/*! Tama funktio printtaa henkilon tietoja. */
void henkilot::printInfo() {

    std::cout << "Henkilon etunimi on " << etuNimi << "." << std::endl;
    std::cout << "Henkilon sukunimi on " << sukuNimi << "." << std::endl;
    std::cout << "Henkilon hetu on " << henkiloHetu << "." << std::endl;
    std::cout << "Henkilon ika on " << ika << "." << std::endl;

}

std::string henkilot::getHetu() {

    return henkiloHetu;
}

void henkilot::muokkaaTietoja() {


}

/*! Tyontekija aliluokan funktiot */

/*! Konstruktori */

tyontekija::tyontekija(std::string henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, std::string palkanmaara, std::string henkiloIka){

    henkiloNumero = henkiloNum;
    etuNimi = henkiloEtunimi;
	sukuNimi = henkiloSukunimi;
	palkka = palkanmaara;
	ika = henkiloIka;
	henkiloHetu = hetu;
}

tyontekija::~tyontekija(){
}
/*! Printtaa tarkeat tiedot konsoliin */
void tyontekija::printInfo() {

    std::cout << "Henkilon etunimi on " << etuNimi;
    std::cout << ", sukunimi " << sukuNimi;
    std::cout << ", hetu " << henkiloHetu;
    std::cout << ", ika " << ika;
    std::cout << ", tyamiesnumero " << henkiloNumero;
    std::cout << ", palkka " << palkka << "." << std::endl;

}
/*! Palauttaa hetun */
std::string tyontekija::getHetu() {

    return henkiloHetu;
}
/*! Tama funktio ottaa halutun muuttujan ja muuttaa sen arvon */
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


/*! Opiskelija aliluokka alkaa tasta kohtaa  */

/*! Konstruktori */
opiskelija::opiskelija(std::string opiskelijaNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string henkiloIka, std::string hetu) {

    opiskelijaNumero = opiskelijaNum;
    etuNimi = henkiloEtunimi;
	sukuNimi = henkiloSukunimi;
	ika = henkiloIka;
	henkiloHetu = hetu;



}

opiskelija::~opiskelija() {

}
/*! Tama funktio printtaa halutut tiedot */
void opiskelija::printInfo() {

    std::cout << "Opiskelijan etunimi on " << etuNimi;
    std::cout << ", sukunimi " << sukuNimi;
    std::cout << ", ika " << ika;
    std::cout << ", hetu " << henkiloHetu;
    std::cout << ", opiskelijanumero " << opiskelijaNumero << ".\n" << std::endl;

}
/*! Tama funktio palauttaa hetun */
std::string opiskelija::getHetu() {

    return henkiloHetu;
}
/*! Tama funktio muokkaa haluttuja muuttujia */
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

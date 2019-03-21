#include "henkilot.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "math.h"

//using namespace std;



int main () {

    std::string valinta = "y";                          /*! Kayttajan valinta kirjataan tahan variableen !*/

    Singleton* s = Singleton::getInstance();            /*! Luodaan singleton mallin mukainen luokka !*/
    alku:                                               /*! Ohjelma palaa tahan kun jokin toiminto on suoritettu !*/
    s->tervetuloa();
    std::cin >> valinta;

    if (valinta == "1") {
        s->addObjects();                                /*!Ensimmainen valinta. Tama lisaa joko tyontekija tai student olion vectoriin.*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }else if (valinta == "3"){
        s->printInfo();                                 /*! Printtaa kaikki vektorista loytyvat oliot ja niiden tiedot.*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }else if (valinta == "2") {
        s->poistaVektori();                             /*!Tama toiminto poistaa vektorista olioita. Ensin varmistetaan, etta vektori ei ole jo tyhja.*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }else if (valinta == "4") {
        s->montakoVektori();                            /*!Tama toiminto katsoo montako oliota vektorista loytyy ja ilmoittaa sen kayttajalle*/
        goto alku;
    }else if (valinta == "5") {
        s->tutkiVektori();                              /*! Tama on hakutoiminto. Tama toiminto ensin katsoo onko vektori tyhja, jos on ilmoittaa siita.*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }else if (valinta == "6") {
        s->etsiOlio();                                  /*!Tama toiminto etsii for-loopilla hetun avulla oikean olion, ottaa sen kasittelyyn ja muokkaa halutun tiedon kayttajan toivomaksi.*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }else if (valinta == "9") {
        std::cout << "\nHyvaa yota.\n";                 /*! Ohjelma sammuu !*/
    }else if (valinta == "7") {
        s->lasketaanPalkka();                           /*! Tama toiminto laskee kayttajalle tuntipalkan kayttaen hyvaksi templatea!*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }else if (valinta == "8") {                         /*! Tama toiminta printtaa vektorin ja tulostaa sieltä kaiken. !*/
        s->clone();
        goto alku;
    }else{
        std::cout << "\nNyt tuli invaliidi input\n";    /*!Mikali tapahtuu virhe ja if lauseet eivat toimi tullaan tanne josta palataan ohjelman alkuun yrittamaan uudelleen !*/
        goto alku;                                      /*! Palataan ohjelman alkuun !*/
    }


}



#include "henkilot.h"
#include <iostream>
#include "math.h"


henkilot::henkilot() { /*! Konstruktori !*/

}

henkilot::~henkilot() { /*! Dekonstruktori !*/
}
/*! Tama funktio printtaa henkilon tietoja. */
void henkilot::printInfo() {

}

std::string henkilot::getHetu() { /*! Palauttaa henkilon hetun. Tanne ei kaytannossa koskaan tulla. !*/

    return testi;
}

std::string henkilot::getEtuNimi()
{
    return testi;
}
std::string henkilot::getSukunimi()
{
    return testi;
}
std::string henkilot::getPalkka()
{
    return testi;
}
std::string henkilot::getNum()
{
    return testi;
}
std::string henkilot::getIka()
{
    return testi;
}

void henkilot::muokkaaTietoja() { /*! Muokkaa henkilon tietoja. Tanne ei koskaan tulla. !*/


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

tyontekija::~tyontekija(){ /*! Dekonstruktori !*/
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

std::string tyontekija::getEtuNimi()
{
    return etuNimi;
}
std::string tyontekija::getSukunimi()
{
    return sukuNimi;
}
std::string tyontekija::getPalkka()
{
    return palkka;
}
std::string tyontekija::getNum()
{
    return henkiloNumero;
}
std::string tyontekija::getIka()
{
    return ika;
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
/*! Dekonstruktori !*/
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
        std::cout << "\nTapahtui virhe, yrita uudelleen.\n"; /*! Mikali sattuu sormen lipsahdus ja osutaan vaaraan nappiin tama nappaa virheen ja palauttaa alkuun !*/
        goto virhe;
    }

}

/*! Loput tyontekiaj luokan funktiosta ovat testeja varten. !*/
std::string opiskelija::getEtuNimi()
{
    return etuNimi;
}
std::string opiskelija::getSukunimi()
{
    return sukuNimi;
}

std::string opiskelija::getNum()
{
    return opiskelijaNumero;
}
std::string opiskelija::getIka()
{
    return ika;
}





Singleton* Singleton::instance = 0; /*! 0 koska instanssi tehdaan pyynnosta !*/

Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }
    return instance;
}

Singleton::Singleton()
{

}

void Singleton::clone()                                        /*! Luo vektorista kopion. Tämän jälkeen kopiosta printataan kaikki ulos jotta varmistutaan sen onnistumisesta.!*/
    {
        std::vector <henkilot *> kopio(VectorOfObjects);
        std::cout << "\nPrintataan kopiosta kaikki ulos.\n";
        lukumaara = kopio.size();
            for (int i=0; i<lukumaara; i++) {
                kopio[i]->printInfo();
                }

    }
    void Singleton::printInfo()                                    /*! Printtaa kaikki vektorista loytyvat oliot ja niiden tiedot.*/
    {
    lukumaara = VectorOfObjects.size();
            for (int i=0; i<lukumaara; i++) {
                VectorOfObjects[i]->printInfo();
                }
    }
void Singleton::addObjects()                                   /*!Ensimmainen valinta. Tama lisaa joko tyontekija tai student olion vectoriin.*/
    {


        std::cout << "\n Press 1 to add employees, press anything else for student \n\n";
        std::cin >> valinta2;

        if (valinta2 == "1") {                          /*!Talla lisataan vectoriin haluttu maara employee tyypin olioita*/
            std::cout << "\nHow many employees to add?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) {           /*! Tassa for-loopin sisalla lisataan yksi kerrallaan manuaalisesti vektoriin tyontekija olio push_back toiminnolla.*/
                std::cout << "\nPlease state the needed information now.\n";
                std::cout << "Please give the first name of the worker\n";
                std::cin >> etunimi;
                std::cout << "Please give the surname of the worker\n";
                std::cin >> sukunimi;
                std::cout << "Please give the age of the worker\n";
                std::cin >> ika;
                std::cout << "\nHetu?\n";
                std::cin >> hetu;
                std::cout << "Please give the pay amount of the worker\n";
                std::cin >> gibMoney;
                std::cout << "\nTyoukko numero?\n";
                std::cin >> tyoMiasNumero;
                henkilot *p = new tyontekija(tyoMiasNumero, etunimi, sukunimi, hetu, gibMoney, ika); /*! Luodaan uusi tyontekija olio ja lisataan sille arvoja. !*/
                try {
                VectorOfObjects.push_back(p);           /*! Tyonnetaan luotu olio vektoriin try-block sisalla. Jos muisti loppuu saadaan error kiinni.!*/
                } catch (std::bad_alloc& ex) {
                    std::cerr << "\nbad_alloc caught.\n";
                }
            }

        }else{                                lukumaara = VectorOfObjects.size();
            for (int i=0; i<lukumaara; i++) {
                VectorOfObjects[i]->printInfo();
                }                                       /*!Talla lisataan vectoriin haluttu maara opiskelija olioita*/
            std::cout << "How many Students would you like to add now?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) {           /*! Tassa for-loopin sisalla lisataan yksi kerrallaan manuaalisesti vektoriin opiskelija olio push_back toiminnolla. */
                std::cout << "\nPlease state the needed information now.\n";
                std::cout << "Please give the first name of the Student\n";
                std::cin >> etunimi;
                std::cout << "Please give the surname of the Student\n";
                std::cin >> sukunimi;
                std::cout << "Please give the age of the Student\n";
                std::cin >> ika;
                std::cout << "Please give the Students social security number\n";
                std::cin >> hetu;
                std::cout << "Please give the Students StudentID\n";
                std::cin >> kouluMiasNumero;
                henkilot *d = new opiskelija(kouluMiasNumero, etunimi, sukunimi, ika, hetu); /*! Luodaan uusi opiskelija olio ja lisataan sille arvoja. !*/
                try {
                VectorOfObjects.push_back(d);            /*! Tyonnetaan luotu olio vektoriin try-block sisalla. Jos muisti loppuu saadaan error kiinni.!*/
                } catch (std::bad_alloc& ex) {
                    std::cerr << "\nbad_alloc caught.\n";
                }
            }
        }


    }
void Singleton::poistaVektori()                                /*!Tama toiminto poistaa vektorista olioita. Ensin varmistetaan, etta vektori ei ole jo tyhja.*/
    {
        lukumaara = VectorOfObjects.size();             /*!Taman jalkeen poistetaan joko kaikki oliot tai etsitaan hetun avulla for-loopilla oikea olio poistettavaksi.*/
        if (lukumaara == 0) {
            std::cout << "\nTietokanta on jo tyhja.\n";
        }else{
            std::cout << "\nPress 1 to delete everything. \nPress anything else to delete specific person from existence.\n";
            std::cin >> valinta2;
            if (valinta2 == "1") {
                lukumaara = VectorOfObjects.size();     /*! Poistetaan vectorista kaikki pop_back kayttaen.!*/
                for (int i = 0; i +1 <= lukumaara; i++) {
                    VectorOfObjects.pop_back();
                }
            }else{
                lukumaara = VectorOfObjects.size();
                    std::cout << "\nPlease give the social security number of the person you'd like to delete.\n";
                    std::cin >> hetu;
                    for (int i = 0; i < lukumaara; i++) {
                            std::cout << i;
                        vertausHetu = VectorOfObjects[i]->getHetu(); /*! Kutsutaan olion getHetu funktiota, jotta voidaan verrata hetuja ja loytaa oikea henkilo. !*/
                        if ( vertausHetu == hetu) {
                            VectorOfObjects.erase(VectorOfObjects.begin() + i); /*! Poistetaan valittu olio vektorista !*/
                        }
                    }
                    std::cout << "\nKyseista henkiloa ei loydy tietokannasta.\n";
                }
            }


    }
void Singleton::montakoVektori()                               /*!Tama toiminto katsoo montako oliota vektorista loytyy ja ilmoittaa sen kayttajalle*/
    {
        std::cout << "\nThere are " << VectorOfObjects.size() << " people in the system\n\n";
    }
void Singleton::tutkiVektori() /*! Tama on hakutoiminto. Tama toiminto ensin katsoo onko vektori tyhja, jos on ilmoittaa siita.*/
    {
        lukumaara = VectorOfObjects.size();             /*!Muussa tapauksessa for-loopissa kaydaan jokainen olio lapi kunnes loytyy etsitty. Taman tiedot sitten printataan.*/
            if (lukumaara == 0) {                       /*!Mikali oliota ei loydy ilmoitetaan tasta ja palataan ohjelman alkuun.*/
                std::cout << "\nTietokanta on tyhja.\n";
            }else{
            std::cout << "\nAnna haettavan henkilon Hetu\n";
            std::cin >> hetu;
            for (int i = 0; i < lukumaara; i++) {
                vertausHetu = VectorOfObjects[i]->getHetu(); /*! Etsitaan vektorin olioista oikea olio hetua kayttaen. Kutsutaan getHetu funktio jonka returnia verrataan kayttajan antamaan !*/
                    if ( vertausHetu == hetu) {
                        VectorOfObjects[i]->printInfo(); /*! Printataan oikean olion tiedot sen printInfo funktiolla !*/
                    }
            }
            std::cout << "\nKyseista henkiloa ei loydy tietokannasta.\n";
        }
    }
void Singleton::etsiOlio()                                     /*!Tama toiminto etsii for-loopilla hetun avulla oikean olion, ottaa sen kasittelyyn ja muokkaa halutun tiedon kayttajan toivomaksi.*/
    {
        lukumaara = VectorOfObjects.size();
            if (lukumaara == 0) {
                std::cout << "\nTietokanta on tyhja. Mitaan ei voida siis muokata.\n";
            }else{
                    std::cout << "\nTo modify information, give the social security number of the person in question.\n";
                    std::cin >> hetu;
                    for (int i = 0; i < lukumaara; i++) {
                        vertausHetu = VectorOfObjects[i]->getHetu();
                        if ( vertausHetu == hetu) {
                            VectorOfObjects[i]->muokkaaTietoja(); /*! Kutsutaan olion muokkaaTietoja funktiota, joka antaa kayttajan muokata muutamia olion muuttujia !*/
                        }
                    }
                    std::cout << "\nKyseista henkiloa ei loydy tietokannasta.\n";
            }
    }
void Singleton::lasketaanPalkka()                              /*! Tama toiminto laskee kayttajalle tuntipalkan kayttaen hyvaksi templatea!*/
{

        std::cout <<"\nAnna tyontekijan tuntipalkka. Kayta pistetta desimaalin erottamiseksi tarvittaessa.\n";
        std::cin >> tuntipalkkafloat; if (std::cin.fail()) {std::cin.clear(); std::cout << "\nYou did not provide a number.\n"; goto loppu;} /*! Tahan variableen laitetaan tyontekijan tuntipalkka. Joko int tai double. Muunnos hoidetaan intiksi tai doubleksi myohemmasa kohtaa ohjelmaa. If-lauseke hoitaa tapaukset joissa input ei ole int tai double !*/
        std::cout << "\nAnna tyontekijan tuntimaara per paiva.\n";
        std::cin >> tuntimaarafloat; if (std::cin.fail()) {std::cin.clear(); std::cout << "\nYou did not provide a number.\n"; goto loppu;} /*! Tahan variableen laitetaan tyontekijan tuntimaara. Joko int tai double. Muunnos intiksi tai doubleksi hoidetaan myohemmassa kohtaa ohjelmaa. If-lauseke hoitaa tapaukset joissa input ei ole int tai double !*/
        /*! Katsotaan onko input int vai float. Tama etta saadaan kayttaa templatea. !*/
        if (floorf(tuntipalkkafloat) == tuntipalkkafloat && floorf(tuntimaarafloat) == tuntimaarafloat) { /*! Tarkistetaan ovatko molemmat variable int jolloin voidaan kutsua oikeaa templatea.!*/
            tuntipalkkaInt = tuntipalkkafloat;
            tuntimaaraInt = tuntimaarafloat;
            std::cout << "\nHenkilon kuukausipalkka on " << laskePalkka(tuntipalkkaInt, tuntimaaraInt) << " Euroa.\n"; /*! Annetaan templateen funktioon laskettavaksi kuukausipalkka !*/
        }else if (floorf(tuntipalkkafloat) != tuntipalkkafloat || floorf(tuntimaarafloat) != tuntimaarafloat) /*! Mikali joukossa on float tyyppisia lasketaan taalla iffissa tulos !*/
       {
            std::cout << "\nHenkilon palkka on " << laskePalkka(tuntipalkkafloat, tuntimaarafloat) << " Euroa.\n"; /*! Annetaan templateen funktioon laskettavaksi tuntipalkka !*/
        }
loppu:;
}

void Singleton::tervetuloa()
    {
        std::cout << "\nPress 1 to add people. \nPress 2 to delete people. \nPress 3 to print all the people. \nPress 4 to see how many people are in the system.\nPress 5 to search for a specific person and print their info.\nPress 6 to modify certain users information.\nPress 7 to calculate employees monthly pay.\nPress 8 to clone vector for funzies.\nPress 9 to quit\n\n";
    }

#include "henkilot.h"
#include <iostream>
#include <vector>
#include <fstream>

//using namespace std;

int main () {

    int lukumaara = 0; /*! Muuttuja joka seuraa kayttajan toiveita ja kaytetaan myos for loopeissa seka vektorin koon seurantaan */
    std::string gibMoney, tyoMiasNumero, kouluMiasNumero, ika, valinta, valinta2, hetu, vertausHetu, etunimi, sukunimi = "baa baa senkin lammas"; /*! Henkilon luomiseen kaytettavia muuttujia*/

    std::vector<henkilot *> VectorOfObjects;    /*! Henkilo-luokan pointerit */

    std::cout << "\nTervetuloa to ihmisManagementProgram 9001.\n" << std::endl;
    alku:
    std::cout << "\nPress 1 to add people. \nPress 2 to delete people. \nPress 3 to print all the people. \nPress 4 to see how many people are in the system.\nPress 5 to search for a specific person and print their info.\nPress 6 to modify certain users information.\nPress 7 to quit\n\n";
    std::cin >> valinta;

    if (valinta == "1") {                       /*!Ensimmainen valinta. Tama lisaa joko tyontekija tai student olion omaan vectoriinsa.*/

        std::cout << "\n Press 1 to add employees, press anything else for student \n\n";
        std::cin >> valinta2;

        if (valinta2 == "1") {                  /*!Talla lisataan vectoriin haluttu maara employee tyypin olioita*/
            std::cout << "\nHow many employees to add?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) {   /*! Tassa for-loopin sisalla lisataan yksi kerrallaan manuaalisesti vektoriin tyontekija olio push_back toiminnolla.*/
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
                henkilot *p = new tyontekija(tyoMiasNumero, etunimi, sukunimi, hetu, gibMoney, ika);
                try {
                VectorOfObjects.push_back(p);
                } catch (std::bad_alloc& ex) {
                    std::cerr << "\nbad_alloc caught.\n";
                }
            }
            goto alku;
        }else{                                  /*!Talla lisataan vectoriin haluttu maara opiskelija olioita*/
            std::cout << "How many Students would you like to add now?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) {   /*! Tassa for-loopin sisalla lisataan yksi kerrallaan manuaalisesti vektoriin opiskelija olio push_back toiminnolla. */
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
                henkilot *d = new opiskelija(kouluMiasNumero, etunimi, sukunimi, ika, hetu);
                try {
                VectorOfObjects.push_back(d);
                } catch (std::bad_alloc& ex) {
                    std::cerr << "\nbad_alloc caught.\n";
                }
            }
        }
        goto alku;
    }else if (valinta == "3"){                  /*! Printtaa kaikki vektorista loytyvat oliot ja niiden tiedot.*/
            lukumaara = VectorOfObjects.size();
            for (int i=0; i<lukumaara; i++) {
                VectorOfObjects[i]->printInfo();
                }
            goto alku;
    }else if (valinta == "2") {                 /*!Tama toiminto poistaa vektorista olioita. Ensin varmistetaan, etta vektori ei ole jo tyhja.*/
        lukumaara = VectorOfObjects.size();     /*!Taman jalkeen poistetaan joko kaikki oliot tai etsitaan hetun avulla for-loopilla oikea olio poistettavaksi.*/
        if (lukumaara == 0) {
            std::cout << "\nTietokanta on jo tyhja.\n";
            goto alku;
        }else{
            std::cout << "\nPress 1 to delete everything. \nPress anything else to delete specific person\n";
            std::cin >> valinta2;
            if (valinta2 == "1") {
                lukumaara = VectorOfObjects.size();
                for (int i = 0; i +1 <= lukumaara; i++) {
                    VectorOfObjects.pop_back();
                }
                goto alku;
            }else{
                lukumaara = VectorOfObjects.size();
                    std::cout << "\nPlease give the social security number of the person you'd like to delete.\n";
                    std::cin >> hetu;
                    for (int i = 0; i < lukumaara; i++) {
                            std::cout << i;
                        vertausHetu = VectorOfObjects[i]->getHetu();
                        if ( vertausHetu == hetu) {
                            VectorOfObjects.erase(VectorOfObjects.begin() + i);
                            goto alku;
                        }
                    }
                    std::cout << "\nKyseista henkiloa ei loydy tietokannasta.\n";
                    goto alku;
                }
            }

    }else if (valinta == "4") {                  /*!Tama toiminto katsoo montako oliota vektorista loytyy ja ilmoittaa sen kayttajalle*/
        std::cout << "\nThere are " << VectorOfObjects.size() << " people in the system\n\n";
        goto alku;

    }else if (valinta == "5") {                 /*! Tama on hakutoiminto. Tama toiminto ensin katsoo onko vektori tyhja, jos on ilmoittaa siita.*/
        lukumaara = VectorOfObjects.size();     /*!Muussa tapauksessa for-loopissa kaydaan jokainen olio lapi kunnes loytyy etsitty. Taman tiedot sitten printataan.*/
            if (lukumaara == 0) {               /*!Mikali oliota ei loydy ilmoitetaan tasta ja palataan ohjelman alkuun.*/
                std::cout << "\nTietokanta on tyhja.\n";
                goto alku;
            }else{
            std::cout << "\nAnna haettavan henkilon Hetu\n";
            std::cin >> hetu;
            for (int i = 0; i < lukumaara; i++) {
                vertausHetu = VectorOfObjects[i]->getHetu();
                    if ( vertausHetu == hetu) {
                        VectorOfObjects[i]->printInfo();
                        goto alku;
                    }
            }
            std::cout << "\nKyseista henkiloa ei loydy tietokannasta.\n";
            goto alku;
        }
    }else if (valinta == "6") {                 /*!Tama toiminto etsii for-loopilla hetun avulla oikean olion, ottaa sen kasittelyyn ja muokkaa halutun tiedon kayttajan toivomaksi.*/
        lukumaara = VectorOfObjects.size();
            if (lukumaara == 0) {
                std::cout << "\nTietokanta on tyhja. Mitaan ei voida siis muokata.\n";
                goto alku;
            }else{
                    std::cout << "\nTo modify information, give the social security number of the person in question.\n";
                    std::cin >> hetu;
                    for (int i = 0; i < lukumaara; i++) {
                        vertausHetu = VectorOfObjects[i]->getHetu();
                        if ( vertausHetu == hetu) {
                            VectorOfObjects[i]->muokkaaTietoja();
                            goto alku;
                        }
                    }
                    std::cout << "\nKyseista henkiloa ei loydy tietokannasta.\n";
                    goto alku;
            }

    }else if (valinta == "7") {
        //for (henkilot * obj: VectorOfObjects)
            //delete obj;
        //VectorOfObjects.clear();
        std::cout << "\nHyvaa yota.\n";
    }else{                                      /*!Mikali tapahtuu virhe ja if lauseet eivat toimi tullaan tanne josta palataan ohjelman alkuun yrittamaan uudelleen*/
        std::cout << "\nNyt tuli invaliidi input\n";
        goto alku;
    }


}



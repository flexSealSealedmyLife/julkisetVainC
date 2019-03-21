#include "henkilot.h"
#include <iostream>
#include <vector>

//using namespace std;

int main () {

    int tyoMiasNumero, lukumaara, ika, kouluMiasNumero = 0;
    std::string valinta, valinta2, hetu, vertausHetu, etunimi, sukunimi = "baa baa senkin lammas";
    float gibMoney = 0;

    std::vector<henkilot *> VectorOfObjects; //henkilo luokkaa eikä muut, Vain yksi vectori

    std::cout << "\nTervetuloa to ihmisManagementProgram 9001.\n" << std::endl;
    alku:
    std::cout << "\nPress 1 to add people. \nPress 2 to delete people. \nPress 3 to print all the people. \nPress 4 to see how many people are in the system.\nPress 5 to quit.\n\n";
    std::cin >> valinta;

    if (valinta == "1") { //Ensimmainen valinta. Tama lisaa joko tyontekija tai student olion omaan vectoriinsa.

        std::cout << "\n Press 1 to add employees, press anything else for student \n\n";
        std::cin >> valinta2;

        //Tähän rakentuu joko employee tai student valinta

        if (valinta2 == "1") { //Talla lisataan vectoriin haluttu maara employee tyypin olioita
            std::cout << "\nHow many employees to add?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) { // tama antaa lisata halutun maaran oliota vectoriin
                /*std::cout << "\nPlease state the needed information now.\n";
                std::cout << "Please give the first name of the Student\n";
                std::cin >> etunimi;
                std::cout << "Please give the surname of the Student\n";
                std::cin >> sukunimi;
                std::cout << "Please give the age of the Student\n";
                std::cin >> ika;*/
                std::cout << "\nPlease state the needed information now.\n";
                std::cout << "\nHetu?\n";
                std::cin >> hetu;
                //std::cout << "\nTyoukko numero?\n";
                //std::cin >> tyoMiasNumero;
                henkilot *p = new tyontekija(tyoMiasNumero, etunimi, sukunimi, hetu, gibMoney, ika);
                VectorOfObjects.push_back(p); // lisaa uuden tyontekija olion vectoriin
            } // olioiden lisaaminen loppuu
            goto alku;
        }else{ //Talla lisataan vectoriin haluttu maara opiskelija olioita
            std::cout << "How many Students would you like to add now?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) { // tama antaa lisata halutun maaran oliota vectoriin
                /*std::cout << "\nPlease state the needed information now.\n";
                std::cout << "Please give the first name of the Student\n";
                std::cin >> etunimi;
                std::cout << "Please give the surname of the Student\n";
                std::cin >> sukunimi;*/
                //std::cout << "Please give the age of the Student\n";
                //std::cin >> ika;
                std::cout << "Please give the Students social security number\n";
                std::cin >> hetu;
                //std::cout << "Please give the Students StudentID\n";
                //std::cin >> kouluMiasNumero;
                henkilot *d = new opiskelija(kouluMiasNumero, etunimi, sukunimi, ika, hetu);
                VectorOfObjects.push_back(d);
            }
        }
        goto alku;
        //Tähän loppuu employy tai student valinta

    }else if (valinta == "3"){ // Printtaa kaiken oliosta. Testitoiminto
            lukumaara = VectorOfObjects.size();
            for (int i=0; i<lukumaara; i++) {
                VectorOfObjects[i]->printInfo();
                }
            goto alku;
    }else if (valinta == "2") {
        lukumaara = VectorOfObjects.size();
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
                    for (int i = 0; i <= lukumaara; i++) {
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

    }else if (valinta == "4") {
        std::cout << "\nThere are " << VectorOfObjects.size() << " people in the system\n\n";
        goto alku;
    }else if (valinta == "5") {
        std::cout << "\nHyvaa yota.\n";

    }else {
        std::cout << "\nNyt tuli invaliidi input\n";
        goto alku;
    }



}

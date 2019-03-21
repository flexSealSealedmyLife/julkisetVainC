#include "henkilot.h"
#include <iostream>
#include <vector>

//using namespace std;

int main () {

    int valinta, valinta2, tyoMiasNumero, lukumaara, ika, kouluMiasNumero = 0;
    std::string hetu, etunimi, sukunimi = "baa baa senkin lammas";
    float gibMoney = 0;

    std::vector<henkilot *> VectorOfObjects; //henkilo luokkaa eikä muut, Vain yksi vectori

    std::cout << "\nTervetuloa to ihmisManagementProgram 9001.\n" << std::endl;
    alku:
    std::cout << "Press 1 to add people. Anything else to print vector...\n";
    std::cin >> valinta;

    if (valinta == 1) { //Ensimmainen valinta. Tama lisaa joko tyontekija tai student olion omaan vectoriinsa.

        std::cout << "\n Press 1 for dat employee, press 2 for student \n\n";
        std::cin >> valinta2;

        //Tähän rakentuu joko employee tai student valinta

        if (valinta2 == 1) { //Talla lisataan vectoriin haluttu maara employee tyypin olioita
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
                std::cout << "\nTyoukko numero?\n";
                std::cin >> tyoMiasNumero;
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
                std::cout << "Please give the age of the Student\n";
                std::cin >> ika;
                std::cout << "Please give the Students social security number\n";
                std::cin >> hetu;
                std::cout << "Please give the Students StudentID\n";
                std::cin >> kouluMiasNumero;
                henkilot *d = new opiskelija(kouluMiasNumero, etunimi, sukunimi, ika, hetu);
                VectorOfObjects.push_back(d);
            }
        }
        goto alku;
        //Tähän loppuu employy tai student valinta

    }else{ // Printtaa kaiken oliosta. Testitoiminto
            lukumaara = VectorOfObjects.size();
            for (int i=0; i<lukumaara; i++) {
                VectorOfObjects[i]->printInfo();
                }
            goto alku;
    }



}

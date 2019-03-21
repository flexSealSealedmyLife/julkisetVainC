#include "henkilot.h"
#include <iostream>
#include <vector>

//using namespace std;

int main () {

    int valinta, valinta2, tyoMiasNumero, lukumaara, ika, kouluMiasNumero = 0;
    std::string hetu, etunimi, sukunimi = "baa baa senkin lammas";
    float gibMoney = 0;

    std::vector<tyontekija *> VectorOfTyoObjects; //henkilo luokkaa eik‰ muut, Vain yksi vectori
    std::vector<opiskelija *> VectorOfKouluObjects;
    std::cout << "\nTervetuloa to ihmisManagementProgram 9001.\n" << std::endl;
    alku:
    std::cout << "Whaccu wanna du? Press 1 to add people. More Functionality coming later...\n";
    std::cin >> valinta;
    std::cout << "Okay, i gatchu homie.\n";

    if (valinta == 1) { //Ensimmainen valinta. Tama lisaa joko tyontekija tai student olion omaan vectoriinsa.

        std::cout << "Whaccu wanna add homie? \n Press 1 for dat employee, press 2 for studentz \n\n";
        std::cin >> valinta2;

        //T‰h‰n rakentuu joko employee tai student valinta

        if (valinta2 == 1) { //Talla lisataan vectoriin haluttu maara employee tyypin olioita
            std::cout << "How many of dem employees wouldzu like to pop in this bad boy now huh?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) { // tama antaa lisata halutun maaran oliota vectoriin
                std::cout << "\nPlease state the needed information now.\n";
                std::cout << "\nGimme the fools first name.\n";
                std::cin >> etunimi;
                std::cout << "\nOkay, now gimme da fools surname homie ma boy we on a roll.\n";
                std::cin >> sukunimi;
                std::cout << "\nYo how old this fool?? He sound like a baby!\n";
                std::cin >> ika;
                std::cout << "\nOh he i c how it is. You know what the dudes social security number is?\n";
                std::cin >> hetu;
                std::cout << "\nThats good thats good. But fo real does the dood have a employee ID?\n";
                std::cin >> tyoMiasNumero;
                std::cout << "\nDat dood sound like a sick do0d. But how much green cash money is the dood gonna make?? \n";
                std::cin >> gibMoney;
                VectorOfTyoObjects.push_back(new tyontekija(tyoMiasNumero, etunimi, sukunimi, hetu, gibMoney, ika)); // lisaa uuden tyontekija olion vectoriin
            } // olioiden lisaaminen loppuu
            //std::cout << "\n There are " << VectorOfTyoObjects.size() << " Object in the vector. \n";
            //VectorOfTyoObjects[1]->printHenkiloEtuNimi();
        }else{ //Talla lisataan vectoriin haluttu maara opiskelija olioita
            std::cout << "How many Students would you like to add now?\n\n";
            std::cin >> lukumaara;
            for (int i=0; i<lukumaara; i++) { // tama antaa lisata halutun maaran oliota vectoriin
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

                VectorOfKouluObjects.push_back(new opiskelija(kouluMiasNumero, etunimi, sukunimi, hetu, ika)); // lisaa uuden tyontekija olion vectoriin
        }

        }
        //T‰h‰n loppuu employy tai student valinta

    }else { // t‰h‰n toiminnallisuutta jota ei ole viel‰ suunniteltu t‰h‰n h‰t‰‰n? Ehk‰ poista j‰sen?

        std::cout << "\n\nHomie my mate dude i don't have dat functionality yet, gimme a minute .\n\n";
        goto alku;
    }



}

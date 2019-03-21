//
//  main.c
//  bankoluovutus
//

//
//

#include <stdio.h>
#include <string.h>
#include <math.h>

void lueRoskat(void);


int main(void){

    FILE * tili;

    double valiNosto,
    lisaa,
    toiminta,
    tilinSaldo = 0.0;

    int valinta = 0,
    yritys = 1,
    montakoViisi,
    montakoKaksi,
    montakoKaksi1,
    montakoKaksi2,
    paljonkoOikeastiNostat,
    nostoMaara = 0,
    nostoMaara2 = 0;

    char tilinumero[250],
    pinkoodi[250],
    tarkistusPin[250];


    // Main alkaa ja pyytaa tilinumeron ja samalla korjaa siita rivinvaihdot

havisit:

    printf("\nAnna tilinumero > ");

    fgets(tilinumero, 50, stdin);

    if(tilinumero[strlen(tilinumero) -1] == '\n') {

        tilinumero[strlen(tilinumero) -1] = '\0';

    }else{

        lueRoskat();
    }

    // Liittää pyydettyyn tilinumeroon .tili paatteen


    strcat(tilinumero, ".tili");


    // Tarkistaa onnistuuko tilin avaaminen


    if((tili = fopen(tilinumero, "r+")) != NULL) {

        printf("\nOlkaa hyva ja syottakaa PIN-koodi\n");

        fgets(pinkoodi, 50, stdin);


        /*while loopin avulla pidetaan kirjaa siita, kuinka monta yritysta pin koodiin on kohdistunut. 3 yritysta ja looppi koko ohjelmoineen katkeaa*/


        while (yritys <= 4) {

            if (yritys == 4) {

                return 0;

            }
            if(pinkoodi[strlen(pinkoodi)-1] == '\n') {

                pinkoodi[strlen(pinkoodi)-1] = '\0';

            }else{

                lueRoskat();

            }

            fgets( tarkistusPin, 50, tili );


            if(tarkistusPin[strlen(tarkistusPin)-1] == '\n') {

                tarkistusPin[strlen(tarkistusPin)-1] = '\0';
            }


            if(tarkistusPin[strlen(tarkistusPin)-1] == '\r') {

                tarkistusPin[strlen(tarkistusPin)-1] = '\0';
            }

            //Ylla olevat vaihtaa piilomerkkeja jos tarvii, alla oleva vertaa pinkoodit

            if(strcmp(pinkoodi, tarkistusPin)  == 0) {

                printf("\nPin-koodi Ok\n\n______________\n\n");

                goto kaikki1;

            }else{

                printf("\nVaara pin-koodi, yritathan uudelleen\n");

                yritys++;
                //yritys++ pitaa silmalla ja lisaa yrityksia
            }
        }


    } else {

        printf("\nTilinne on suljettu, olkaa hyva ja ottakaa yhteytta pankkiinne\n");

    }

    //estaa paasyn menuun, jos tili ei aukea vaaran pin-koodin takia.
    goto havisit;

    /*Tasta alkaa itse automaatin paatoiminnot: nosto, talleta, saldo, lopeta. Switchi hoitaa vaihdot */

kaikki1:

    printf("\nValitse toiminto:\n\n1 - Nosto\n2 - Talleta\n3 - Saldo\n4 - Lopeta\n\nValintasi: ");
    scanf("%d", &valinta);

    switch (valinta) {

            /*Noston valinta ohjaa switchin tanne. Switchien lopussa olevat goto kaikki1 ohjaa ohjelman takaisin kysymaan mita asiakas haluaisi tehda.*/

        case 1:

            tili = fopen(tilinumero, "r+");
            fscanf( tili, "%lf%lf", &toiminta, &tilinSaldo);
            printf("\nPaljonko haluaisit nostaa? Minimi on 20 euroa\n");
            scanf("%d", &nostoMaara);

            /*tasta alkaa algoritmi, jolla maaritetaan montako mitakin setelia asiakas saa. Lyhyesti alun 30, 50, 70, 90 euron erikoisuuksia lukuunottamatta algoritmi katsoo riittaako tilin varat. Jos kylla niin algoritmi laskee ensin montako 50 euron setelia asiakas saa. Jos 50 setelien maara on pariton, kuten esimerkiksi 260 euron tapauksessa, algoritmi vahentaa yhden 50 setelin noston mahdollistamiseksi. Eli asiakas saisi 200 euroa neljana viisikymppisena ja 60 euroa kolmena kaksikymppisena. 250 eli 50 jaollissa tapauksissa suoraan vain jaetaan montako 50 saa.*/

            if (nostoMaara > tilinSaldo) {

                printf("\nNostomaara ylittaa tilinne saldon\n");
            }else{

                if (nostoMaara < 20 || nostoMaara == 30) {

                    printf("\nValitsemanne noston maara alittaa pienimman mahdollisen arvon, olette valinneet nostomaaraksi 30 euroa tai kaytitte kirjaimia. Automaatista on mahdollista nostaa vahintaan 20 euroa ja vain numeroita kayttaen.\n");
                    fseek(stdin,0,SEEK_END);
                    goto kaikki1;
                }else{
                    if (nostoMaara == 50) {

                        tilinSaldo -= 50;

                        fseek(tili, 0, SEEK_SET);

                        fprintf(tili, "%s\n\n%f", tarkistusPin, tilinSaldo);

                        fclose(tili);

                        fseek(stdin,0,SEEK_END);

                        printf("\nSaat 1 50 euron setelia ja 0 20 euron setelia\n");
                        goto kaikki1;
                    }
                    if (nostoMaara == 70) {

                        tilinSaldo -= 70;

                        fseek(tili, 0, SEEK_SET);

                        fprintf(tili, "%s\n\n%f", tarkistusPin, tilinSaldo);

                        fclose(tili);

                        fseek(stdin,0,SEEK_END);

                        printf("\nSaat 1 50 euron setelia ja 1 20 euron setelia\n");
                        goto kaikki1;
                    }
                    if (nostoMaara == 90) {

                        tilinSaldo -= 90;

                        fseek(tili, 0, SEEK_SET);

                        fprintf(tili, "%s\n\n%f", tarkistusPin, tilinSaldo);

                        fclose(tili);

                        fseek(stdin,0,SEEK_END);

                        printf("\nSaat 1 50 euron setelia ja 2 20 euron setelia\n");
                        goto kaikki1;
                    }

                    //tapaus nostomaara on 50 jaollinen algoritmi

                    nostoMaara2 = nostoMaara / 50;

                    if (nostoMaara2 % 2 != 0) {

                        montakoViisi = nostoMaara/50;

                        montakoKaksi = 0;

                        paljonkoOikeastiNostat = (montakoKaksi * 20) + (montakoViisi * 50);

                        tilinSaldo -= paljonkoOikeastiNostat;

                        fseek(tili, 0, SEEK_SET);

                        fprintf(tili, "%s\n\n%f", tarkistusPin, tilinSaldo);

                        fclose(tili);

                        fseek(stdin,0,SEEK_END);

                        printf("\nSaat %d 50 euron setelia ja %d 20 euron setelia\n", montakoViisi, montakoKaksi);
                        goto kaikki1;


                    }

                    //tapaus esim 1230 euroa algoritmi

                    if (nostoMaara % 20 == 10) {

                        valiNosto = nostoMaara/50;

                        montakoViisi = floor(valiNosto);

                        montakoViisi = montakoViisi -1;

                        montakoKaksi1 = montakoViisi * 50;

                        montakoKaksi2 = (nostoMaara - montakoKaksi1);

                        montakoKaksi = montakoKaksi2 / 20;



                    }else{

                    valiNosto = nostoMaara/50;

                    montakoViisi = floor(valiNosto);
                        // muut tapaukset.

                    if (montakoViisi % 2 != 0) {

                        montakoViisi = montakoViisi - 1;

                        montakoKaksi1 = montakoViisi * 50;

                        montakoKaksi2 = (nostoMaara - montakoKaksi1);

                        montakoKaksi = montakoKaksi2 / 20;


                    }
                    }

                    montakoKaksi1 = montakoViisi * 50;

                    montakoKaksi2 = (nostoMaara - montakoKaksi1);

                    montakoKaksi = montakoKaksi2 / 20;

                    paljonkoOikeastiNostat = (montakoKaksi * 20) + (montakoViisi * 50);

                    tilinSaldo -= paljonkoOikeastiNostat;

                    fseek(tili, 0, SEEK_SET);

                    fprintf(tili, "%s\n\n%f", tarkistusPin, tilinSaldo);

                    fclose(tili);

                    fseek(stdin,0,SEEK_END);

                    printf("\nSaat %d 50 euron setelia ja %d 20 euron setelia\n", montakoViisi, montakoKaksi);
                }

            }
            goto kaikki1;


            /* case 2 on tapaus, jossa rahaa talletetaan asiakkaan tilille. fseek ja fprintf hoitavat tiedoston paivittamisen rahatilanteen yllapitamiseksi.*/

        case 2:

            tili = fopen(tilinumero, "r+");

            fscanf( tili, "%lf%lf", &toiminta, &tilinSaldo);

            printf("\nPaljonko haluaisit talletaa?\n");

            lisaa = 0.0;

            scanf("%lf", &lisaa);

            tilinSaldo += lisaa;

            fseek(tili, 0, SEEK_SET);

            //1234 osuus alla olevasta on pin koodi, joka aina lisataan tiedostoon uudestaan...

            fprintf(tili, "%s\n\n%lf", tarkistusPin, tilinSaldo);

            fclose(tili);

            fseek(stdin,0,SEEK_END);

            goto kaikki1;



            //case 3 kertoo vain saldon ja ohjaa takaisin paavalikkoon

        case 3:

            tili = fopen(tilinumero, "r");

            fscanf(tili, "%lf%lf", &toiminta, &tilinSaldo);

            printf("\nTilinne saldo on %f euroa\n", tilinSaldo);

            fclose(tili);

            fseek(stdin,0,SEEK_END);

            goto kaikki1;



            //case 4 lopetta ohjelman ja sulkee tiedoston

        case 4:

            printf("\nKiitos hei hei\n");

            fclose(tili);

            break;

        default:

            printf("\nVaara valinta, vain numerot 1, 2 ,3 ,4 toimivat\n");
            fseek(stdin,0,SEEK_END);
            goto kaikki1;
    }

    //havisit estamassa menun esiintuloa siinatapauksessa, etta tili ei aukea
    return 0;
}

// lueRoskat ohjelma joka korjaa nappaimiston enter
//painalluksia.

void lueRoskat(void){

    while(fgetc(stdin) != '\n');

}






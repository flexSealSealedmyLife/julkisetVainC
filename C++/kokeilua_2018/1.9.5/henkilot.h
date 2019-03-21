#include <string>
#include <vector>

/*!Kantaluokka */


class henkilot {

	public:
        henkilot();
        ~henkilot();
		virtual void printInfo();
		virtual std::string getHetu();
		virtual void muokkaaTietoja();
        virtual std::string getEtuNimi();
        virtual std::string getSukunimi();
        virtual std::string getPalkka();
        virtual std::string getNum();
        virtual std::string getIka();
    protected:
        std::string testi = "";
};

/*! Henkiloluokan aliluokka. */

class tyontekija: public henkilot {

    public:
        tyontekija(std::string henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, std::string palkanmaara, std::string henkiloIka);
        ~tyontekija();
        void printInfo();
        std::string getHetu();
        void muokkaaTietoja();
        std::string getEtuNimi();
        std::string getSukunimi();
        std::string getPalkka();
        std::string getNum();
        std::string getIka();
    protected:
        std::string henkiloNumero;
        std::string palkka;
        std::string henkiloHetu;
		std::string etuNimi;
		std::string sukuNimi;
		std::string henkiloSukunimi;
		std::string valinta;
		std::string ika;

};

/*! Henkiloluokan aliluokka */

class opiskelija: public henkilot {

    public:
        opiskelija(std::string opiskelijaNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string henkiloIka, std::string hetu);
        ~opiskelija();
        void printInfo();
        std::string getHetu();
        void muokkaaTietoja();
        std::string getEtuNimi();
        std::string getSukunimi();
        std::string getNum();
        std::string getIka();
    protected:
        std::string opiskelijaNumero;
        std::string henkiloHetu;
		std::string etuNimi;
		std::string sukuNimi;
		std::string henkiloSukunimi;
		std::string valinta;
		std::string ika;

};

/*! Kaikki tyo tehdaan taalla. Singleton design patternin mukainen luokka. Toteuttaa samalla myos facade ja prototype design patternit.!*/
class Singleton
{
private:
    static Singleton* instance; /*! Instanssi tallennetaan tahan !*/
    Singleton(); /*! Privaatte constructori!*/
    int lukumaara, tuntimaaraInt, tuntipalkkaInt = 0; /*! Muuttuja joka seuraa kayttajan toiveita ja kaytetaan myos for loopeissa seka vektorin koon seurantaan. Mukana myos kuukausipalkkan laskuun tarvittavia muuttujia */
    float tuntimaarafloat, tuntipalkkafloat = 0.0; /*! Henkilon kuukausipalkan laskuun tarvittavia muuttujia !*/
    std::string valinta2, hetu, vertausHetu, etunimi, ika, tyoMiasNumero, gibMoney, sukunimi, kouluMiasNumero = "lammas"; /*! Henkilon luomiseen kaytettavia muuttujia*/
    std::vector<henkilot *> VectorOfObjects; /*! Vektori johon kaikki oliot tallennetaan !*/

public:
    static Singleton* getInstance();
    template <class T> T laskePalkka(T n1, T n2){    T tulos;
    tulos = (n1 * n2) * 20;
    return (tulos);};
    void printInfo();
    void muokkaaTietoja();
    std::string getHetu();
    void clone();
    void addObjects();
    void poistaVektori();
    void montakoVektori();
    void etsiOlio();
    void lasketaanPalkka();
    void tervetuloa();
    void tutkiVektori();
};



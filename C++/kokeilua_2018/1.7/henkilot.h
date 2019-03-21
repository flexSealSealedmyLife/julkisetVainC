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
    protected:
        std::string henkiloHetu;
		std::string etuNimi;
		std::string sukuNimi;
		std::string henkiloSukunimi;
		std::string valinta;
		std::string ika;

};

/*! Henkiloluokan aliluokka. */

class tyontekija: public henkilot {

    public:
        tyontekija(std::string henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, std::string palkanmaara, std::string henkiloIka);
        ~tyontekija();
        void printInfo();
        std::string getHetu();
        void muokkaaTietoja();
    protected:
        std::string henkiloNumero;
        std::string palkka;

};

/*! Henkiloluokan aliluokka */

class opiskelija: public henkilot {

    public:
        opiskelija(std::string opiskelijaNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string henkiloIka, std::string hetu);
        ~opiskelija();
        void printInfo();
        std::string getHetu();
        void muokkaaTietoja();
    protected:

        std::string opiskelijaNumero;

};


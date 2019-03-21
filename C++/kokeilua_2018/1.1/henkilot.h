#include <string>
#include <vector>

class henkilot {

	public:
		henkilot();
		~henkilot();
		virtual void printInfo();
    protected:
        std::string henkiloHetu;
		std::string etuNimi;
		std::string sukuNimi;
		std::string henkiloSukunimi;
		int ika;



};

class tyontekija: public henkilot {

    public:
        tyontekija(int henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, float palkanmaara, int henkiloIka);
        ~tyontekija();
        void printInfo();
    protected:
        int henkiloNumero;
        int palkka;

};

class opiskelija: public henkilot {

    public:
        opiskelija(int opiskelijaNum, std::string henkiloEtunimi, std::string henkiloSukunimi, int henkiloIka, std::string hetu);
        ~opiskelija();
        void printInfo();
    protected:

        int opiskelijaNumero;

};

/*T‰nne pit‰‰ lis‰t‰ virtuaaliset classit, ei*/

#include <string>
#include <vector>

class henkilot {

	public:
		henkilot();
		~henkilot();
    protected:
        std::string henkiloHetu;
		std::string etuNimi;
		std::string sukuNimi;
		std::string henkiloSukunimi;
		int ika;

};

class tyontekija:henkilot {

    public:
        tyontekija(int henkiloNum, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, float palkanmaara, int henkiloIka);
        ~tyontekija();
        std::string printHenkiloHetu();
        float printPalkka();
        std::string printHenkiloEtuNimi();
    protected:
        int henkiloNumero;
        int palkka;


};

class opiskelija:henkilot {

    public:
        opiskelija(int opiskelijaNumero, std::string henkiloEtunimi, std::string henkiloSukunimi, std::string hetu, int henkiloIka);
        ~opiskelija();
        int printOpiskelijaNumero();
        std::string printHenkiloEtuNimi();
    protected:
        int opiskelijaNumero;


};

/*T‰nne pit‰‰ lis‰t‰ virtuaaliset classit, ei

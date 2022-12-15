#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Czlowiek.h"
#include "oceny.h"

class Pracownik:public Czlowiek
{
    public:
        Pracownik(string alogin, string aimie, string anazwisko);
        Pracownik(string file_name, string alogin); //ten konstruktor pobiera dane z pliku
        class oceny_studenta: public oceny{
            bool dodanie_oceny(int ocena, int semestr);
        };
        bool sprawdz_oceny(string login);
        void display();
    protected:

    private:
};

#endif // PRACOWNIK_H

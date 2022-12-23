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
        int sprawdz_ocene(string file_name, string login, string przedmiot, int semestr);
        string sprawdzenie_grupy_student(string file_name, string alogin);
        bool dodaj_ocene(string file_name, string alogin, int ocena, int semestr);
        bool dodaj_studenta(string alogin, string ahaslo, string grupa, string wydzial, string aimie, string anazwisko, string semestr);
        void display();
    protected:

    private:
};

#endif // PRACOWNIK_H

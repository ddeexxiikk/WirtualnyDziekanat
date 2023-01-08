#ifndef STUDENT_H
#define STUDENT_H
#include "Czlowiek.h"
#include "oceny.h"
#include "Plan_zajec.h"
#include <map>

class Student : public Czlowiek
{
    public:
        Student(string alogin, string aimie, string anazwisko, string akierunek, int asemestr);
        Student(string file_name, string login); //ten konstruktor pobiera dane z pliku
        void display();
        string sprawdzenie_grupy();
        void wyswietl_plan();
        vector<string> sprawdz_liste_ksiazek();

        class Ocena
        {
        public:
            Ocena(string aprzedmiot, int asemestr, int aocena)
                : przedmiot(aprzedmiot), semestr(asemestr), ocena(aocena)
            {} 
            
            string przedmiot;
            int semestr;
            int ocena;
        };

        vector<Ocena> sprawdz_oceny(int asemestr);

    protected:

    private:
        bool wczytaj_ksiazki();
        bool wczytaj_oceny();
        vector<string> lista_ksiazek;
        vector<Ocena> oceny;
        string kierunek, grupa;
        int semestr;
        Plan_zajec plan;
};

#endif // STUDENT_H

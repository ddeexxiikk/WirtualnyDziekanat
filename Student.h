#ifndef STUDENT_H
#define STUDENT_H
#include "Czlowiek.h"
#include "Ocena.h"
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
        vector<Ocena> sprawdz_oceny(int asemestr);
        vector<pair<int, Ocena>> sprawdz_oceny_w_calym_toku_studiow();

        void wyswietl_informacje() override;

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

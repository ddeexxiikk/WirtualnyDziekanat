#ifndef STUDENT_H
#define STUDENT_H
#include "Czlowiek.h"
#include "oceny.h"
#include "Plan_zajec.h"
#include <map>
#include <utility>

class Student : public Czlowiek
{
    public:
        Student(string alogin, string aimie, string anazwisko, string akierunek, int asemestr);
        Student(string file_name, string login); //ten konstruktor pobiera dane z pliku
        class oceny_studenta: public oceny{
            bool dodanie_oceny(int ocena, int semestr);
        };
        void display();
        string sprawdzenie_grupy();
        void wyswietl_plan();

    protected:

    private:
        string kierunek, grupa;
        int semestr;
        map<string, oceny_studenta>przedmioty;
        Plan_zajec plan;
};

#endif // STUDENT_H

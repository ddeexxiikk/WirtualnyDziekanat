#ifndef STUDENT_H
#define STUDENT_H
#include "Czlowiek.h"
#include "oceny.h"
#include <map>

class Student : public Czlowiek
{
    public:
        Student(string alogin, string aimie, string anazwisko, string akierunek, int arok);
        class oceny_studenta: public oceny{
            bool dodanie_oceny(int ocena, int semestr);
        };

    protected:

    private:
        string kierunek;
        int rok;
        map<string, oceny_studenta>przedmioty;

};

#endif // STUDENT_H

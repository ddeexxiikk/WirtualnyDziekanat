#ifndef STUDENT_H
#define STUDENT_H
#include "Czlowiek.h"
#include "oceny.h"
#include <map>

class Student : public Czlowiek
{
    public:
        Student(string alogin, string aimie, string anazwisko, string akierunek, int asemestr);
        Student(string file_name, string login); //ten konstruktor pobiera dane z pliku

        class oceny_studenta: public oceny{
            bool dodanie_oceny(int ocena, int semestr);
        };

        void display();

    protected:

    private:
        string kierunek, grupa;
        int semestr;
        map<string, oceny_studenta>przedmioty;
};

#endif // STUDENT_H

#include "Student.h"

Student::Student(string alogin, string aimie, string anazwisko, string akierunek, int arok):Czlowiek(alogin, aimie, anazwisko)
{
    //ctor
    rok=arok;
    kierunek=akierunek;
    //this.Czlowiek(*alogin, *aimie, *anazwisko);
}

bool Student::oceny_studenta::dodanie_oceny(int ocena, int semestr)
{
    return false;
}

#include "Pracownik.h"

Pracownik::Pracownik(string alogin, string aimie, string anazwisko):Czlowiek(alogin, aimie, anazwisko)
{
    //ctor
    //this.Czlowiek(*alogin, *aimie, *anazwisko);
}

bool Pracownik::oceny_studenta::dodanie_oceny(int ocena, int semestr)
{
    this->oceny_koncowe[semestr]=ocena;
    return true;
}

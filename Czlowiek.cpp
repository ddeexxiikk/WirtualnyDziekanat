#include "Czlowiek.h"
#include <string>

using namespace std;

    Czlowiek::Czlowiek(string * alogin, string * aimie, string * anazwisko, int * apoziom_dostepu)
    {
        imie = *aimie;
        nazwisko = *anazwisko;
        poziom_dostepu = *apoziom_dostepu;
        login = *alogin;
    };

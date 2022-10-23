#include "Czlowiek.h"
#include <iostream>
#include <string>

using namespace std;

    Czlowiek::Czlowiek(string aLogin, string aImie, string aNazwisko, int aPoziom_dostepu)
    {
        imie = aImie;
        nazwisko = aNazwisko;
        poziom_dostepu = aPoziom_dostepu;
        login = aLogin;
    };

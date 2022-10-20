#include "Czlowiek.h"
#include <iostream>
#include <string>

using namespace std;

    Czlowiek::Czlowiek(string aImie, string aNazwisko, int aPoziom_dostepu)
    {
        imie = aImie;
        nazwisko = aNazwisko;
        poziom_dostepu = aPoziom_dostepu;
    };

    void Czlowiek::Powitanie()
    {
        cout << "Witaj " << imie << " " << nazwisko << endl;
        cout << "Twoj poziom dostepu to: " << poziom_dostepu << endl;
    };

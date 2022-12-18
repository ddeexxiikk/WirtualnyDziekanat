#ifndef WIRTUALNYDZIEKANAT_CZLOWIEK_H
#define WIRTUALNYDZIEKANAT_CZLOWIEK_H
#include <string>

using namespace std;

class Czlowiek {
    protected:
        string login, imie, nazwisko;
        int poziom_dostepu;

    public:
        Czlowiek(string alogin, string aimie, string anazwisko);
};

#endif

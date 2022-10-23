#ifndef WIRTUALNYDZIEKANAT_CZLOWIEK_H
#define WIRTUALNYDZIEKANAT_CZLOWIEK_H
#include <string>

using namespace std;

class Czlowiek {
    private:
        string login, imie, nazwisko;
        int poziom_dostepu;

    public:
        Czlowiek(string * alogin, string * aimie, string * anazwisko, int * apoziom_dostepu);
};

#endif

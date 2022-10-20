#ifndef WIRTUALNYDZIEKANAT_CZLOWIEK_H
#define WIRTUALNYDZIEKANAT_CZLOWIEK_H
#include <string>

using namespace std;

class Czlowiek {
    private:
        string imie, nazwisko;
        int poziom_dostepu;
    public:
        Czlowiek(string aImie, string aNazwisko, int aPoziom_dostepu);
        void Powitanie();
};

#endif

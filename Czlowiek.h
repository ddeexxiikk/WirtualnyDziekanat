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
        void zmien_haslo(string file_name, string nowe_haslo);
        virtual void wyswietl_informacje()=0;
};

#endif

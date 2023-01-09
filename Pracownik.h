#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Czlowiek.h"
#include "Ocena.h"
#include "Plan_zajec.h"

class Pracownik:public Czlowiek
{
    public:
        Pracownik(string alogin, string aimie, string anazwisko);
        Pracownik(string file_name, string alogin); //ten konstruktor pobiera dane z pliku
        int sprawdz_ocene(string file_name, string login, string przedmiot, int semestr);
        string sprawdzenie_grupy_student(string file_name, string alogin);
        void dodaj_ocene(string alogin, string aprzedmiot, int semestr, double ocena);
        void dodaj_studenta(string alogin, string ahaslo, string grupa, string wydzial, string aimie, string anazwisko, string semestr);
        void usun_studenta(string alogin, string aimie, string anazwisko);
        bool sprawdz_plan_zajec_studenta(string akierunek, string agrupa);
        int dodaj_ksiazke_studentowi(string alogin, string atytul);
        int usun_ksiazke_studentowi(string alogin, string atytul);
        void dodaj_plan_zajec(string kierunek, string grupa, Plan_zajec::lekcja lekcja);
        void wyswietl_informacje() override;
        
    protected:

    private:
        int _stoi(const string& str, size_t* pos, int base);
};

#endif // PRACOWNIK_H

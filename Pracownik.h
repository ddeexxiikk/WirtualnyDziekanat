#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Czlowiek.h"
#include "Ocena.h"
#include "Plan_zajec.h"
#include <map>

class Pracownik:public Czlowiek
{
    public:
        Pracownik(string alogin, string aimie, string anazwisko);
        Pracownik(string file_name, string alogin); //ten konstruktor pobiera dane z pliku
        int sprawdz_ocene(string file_name, string login, string przedmiot, int semestr);
        vector<Ocena> sprawadz_oceny_z_calego_semestru(string file_name, string login, int semestr);
        vector<pair<int, Ocena>> sprawdz_oceny_z_calego_toku_studiow(string file_name, string login);
        string sprawdzenie_grupy_student(string file_name, string alogin);
        void dodaj_ocene(string alogin, string aprzedmiot, int semestr, double ocena);
        void dodaj_studenta(string alogin, string ahaslo, string grupa, string wydzial, string aimie, string anazwisko, string semestr);
        int usun_studenta(string alogin, string aimie, string anazwisko);
        bool sprawdz_plan_zajec_studenta(string akierunek, string agrupa);
        int dodaj_ksiazke_studentowi(string alogin, string atytul);
        int usun_ksiazke_studentowi(string alogin, string atytul);
        int usun_wszystkie_ksiazki_studenta(string alogin);
        int usun_wszystkie_oceny_studenta(string alogin);
        void dodaj_plan_zajec(string kierunek, string grupa, Plan_zajec::lekcja lekcja);
        void wyswietl_informacje() override;
        
    protected:

    private:
        int _stoi(const string& str, size_t* pos, int base);
};

#endif // PRACOWNIK_H

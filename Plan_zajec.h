#ifndef PLAN_ZAJEC_H
#define PLAN_ZAJEC_H
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Plan_zajec
{
    public:
        /*
            lekcja - wewnêtrzna klasa reprezentuj¹ca pojedyncze zajêcia w tygodniu
            display() - wyœwietla dane o lekcjach
        */
        Plan_zajec() = default;
        void import(string nazwa_pliku, string kierunek, string agrupa);
        class lekcja
        {
            public:
            string tytul, sala, prowadzacy;
            int dzien; //dzieñ tygodnia od 1 - poniedzia³ek do 7 - niedziela
            int godzina_rozpoczecia, minuta_rozpoczecia;
            int czas_trwania; //w minutach
            lekcja(string atytul, string asala, string aprowadzacy, int adzien, int a_godz, int a_min, int a_czas)
            {
                tytul=atytul;
                sala=asala;
                prowadzacy=aprowadzacy;
                dzien=adzien;
                godzina_rozpoczecia=a_godz;
                minuta_rozpoczecia=a_min;
                czas_trwania=a_czas;
            }
            string display_time(int czas)
            {
                return (czas<10?"0":"")+to_string(czas);
            }
            string display()
            {
                const string dni_tygodnia[7] = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela" };
                int minuta_zakonczenia=(minuta_rozpoczecia+czas_trwania)%60;
                int godzina_zakonczenia=godzina_rozpoczecia+(minuta_rozpoczecia+czas_trwania)/60;
                return tytul+" Sala: "+sala+" Prowadzacy: "+prowadzacy+" Dzien: "+dni_tygodnia[dzien-1]+" Godzina: "+display_time(godzina_rozpoczecia)+":"
                +display_time(minuta_rozpoczecia)+"-"+display_time(godzina_zakonczenia)+":"+display_time(minuta_zakonczenia);
            }
        };
        void display();
    protected:
        vector<lekcja> zajecia;
    private:
};

#endif // PLAN_ZAJEC_H

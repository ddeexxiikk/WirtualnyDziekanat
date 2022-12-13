#ifndef PLAN_ZAJEC_H
#define PLAN_ZAJEC_H
#include <vector>
#include <iostream>

using namespace std;

class Plan_zajec
{
    public:
        /*
            lekcja - wewnêtrzna klasa reprezentuj¹ca pojedyncze zajêcia w tygodniu
            display() - wyœwietla dane o lekcjach
        */
        Plan_zajec(string nazwa_pliku, string kierunek, string agrupa);
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
            string display()
            {
                int minuta_zakonczenia=(minuta_rozpoczecia+czas_trwania)%60;
                int godzina_zakonczenia=godzina_rozpoczecia+(minuta_rozpoczecia+czas_trwania)/60;
                return tytul+" Sala: "+sala+" Prowadzacy: "+prowadzacy+" Godzina: "+to_string(godzina_rozpoczecia)+":"
                +to_string(minuta_rozpoczecia)+"-"+to_string(godzina_zakonczenia)+":"+to_string(minuta_zakonczenia);
            }
        };
        void display();
    protected:
        vector<lekcja> zajecia;
    private:
};

#endif // PLAN_ZAJEC_H

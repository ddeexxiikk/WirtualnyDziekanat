#include "Plan_zajec.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

Plan_zajec::Plan_zajec(string nazwa_pliku, string akierunek, string agrupa)
{
    /*
        Ten konstruktor dostaje nazwe pliku z danymi i szuka wszystkich zajêæ dotycz¹cych danej grupy na danym kierunku
        Przy znalezieniu takich zajêæ tworzy obiekt klasy wewnêtrznej lekcja i dodaje j¹ do wektora przecowuj¹cego plan zajêæ
        Pod koniec sortuje zajęcia tak żeby były od poniedziałku do piątku po kolei
    */
    ifstream plan;
    plan.open(nazwa_pliku.c_str());
    string temp_kierunek, temp_grupa, temp_tytul, temp_sala, temp_prowadzacy;
    int temp_dzien, temp_godz, temp_min, temp_czas;
    if(plan.good())
    {
        while(plan>>temp_kierunek>>temp_grupa>>temp_tytul>>temp_sala>>temp_prowadzacy>>temp_godz>>temp_min>>temp_czas)
        {
            if(temp_kierunek==akierunek&&temp_grupa==agrupa)
            {
                lekcja nowa(temp_tytul, temp_sala, temp_prowadzacy, temp_dzien, temp_godz, temp_min, temp_czas);
                zajecia.push_back(nowa);
            }
        }
    }
    plan.close();
    sort(zajecia.begin(), zajecia.end(), [ ](const lekcja &zajecia1, const lekcja &zajecia2)
        {
            int czas1=(24*zajecia1.dzien+zajecia1.godzina_rozpoczecia)*60+zajecia1.minuta_rozpoczecia;
            int czas2=(24*zajecia2.dzien+zajecia2.godzina_rozpoczecia)*60+zajecia2.minuta_rozpoczecia;
            return czas1<czas2;
        });
}

void Plan_zajec::display()
{
    for(lekcja i : zajecia) cout<<i.display()<<endl;
}

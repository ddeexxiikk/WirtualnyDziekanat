#include "Plan_zajec.h"
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include "Wyjatki.h"
using namespace std;

void Plan_zajec::import(string nazwa_pliku, string akierunek, string agrupa)
{
    /*
        Ten konstruktor dostaje nazwe pliku z danymi i szuka wszystkich zajêæ dotycz¹cych danej grupy na danym kierunku
        Przy znalezieniu takich zajêæ tworzy obiekt klasy wewnêtrznej lekcja i dodaje j¹ do wektora przecowuj¹cego plan zajêæ
        Pod koniec sortuje zajęcia tak żeby były od poniedziałku do piątku po kolei
    */
    ifstream plan;
    plan.open(nazwa_pliku.c_str());
    string temp_kierunek, temp_grupa, temp_tytul, temp_sala, temp_prowadzacy;
    string temp_dzien, temp_godz, temp_min, temp_czas;
    if(plan.good())
    {
        string line;
        while(getline(plan, line))
        {
            istringstream csvStream(line);
            getline(csvStream, temp_kierunek, ';');
            getline(csvStream, temp_grupa, ';');
            getline(csvStream, temp_tytul, ';');
            getline(csvStream, temp_sala, ';');
            getline(csvStream, temp_prowadzacy, ';');
            getline(csvStream, temp_godz, ';');
            getline(csvStream, temp_min, ';');
            getline(csvStream, temp_czas, ';');
            getline(csvStream, temp_dzien, ';');
            if(temp_grupa == agrupa && temp_kierunek == akierunek)
            {
                lekcja nowa(temp_tytul, temp_sala, temp_prowadzacy, stoi(temp_dzien), stoi(temp_godz), stoi(temp_min), stoi(temp_czas));
                zajecia.push_back(nowa);
            }
        }
    }
    else
    {
        plan.close();
        throw BladPliku(string("blad pliku - " + nazwa_pliku).c_str());
    }
    plan.close();
    sort(zajecia.begin(), zajecia.end(), [ ](const lekcja &zajecia1, const lekcja &zajecia2)
        {
            int czas1=(24*zajecia1.dzien+zajecia1.godzina_rozpoczecia)*60+zajecia1.minuta_rozpoczecia;
            int czas2=(24*zajecia2.dzien+zajecia2.godzina_rozpoczecia)*60+zajecia2.minuta_rozpoczecia;
            return czas1<czas2;
        });
}

void Plan_zajec::display(string grupa)
{
    for(lekcja i : zajecia) cout<<i.display()<<endl;
}

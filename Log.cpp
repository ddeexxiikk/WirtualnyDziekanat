#include "Log.h"
#include <fstream>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Wyjatki.h"

Log::Log()
{
    auto data = time(nullptr);
    auto tmp = *localtime(&data);
    ostringstream oss;
    oss << put_time(&tmp, "%d-%m-%Y %H-%M-%S");
    nazwa_pliku = "logi\\" + oss.str();
    
   
    ofstream plik;
    plik.open(nazwa_pliku.c_str());
    if(!plik.good())
    {
        plik.close();
        throw BladPliku(string("blad pliku - " + nazwa_pliku).c_str());
    }
    plik << "Data urochomienia programu: " << oss.str() << endl;
    plik.close();
}

void Log::zapisz_akcje(string wiadomosc)
{
    auto data = time(nullptr);
    auto tmp = *localtime(&data);
    ostringstream oss;
    oss << put_time(&tmp, "%d-%m-%Y %H-%M-%S");

    ofstream plik;
    plik.open(nazwa_pliku, ios::app);
    if(!plik.good())
    {
        plik.close();
        throw BladPliku(string("blad pliku - " + nazwa_pliku).c_str());
    }

    plik << oss.str() << " >> " << wiadomosc << endl;
    plik.close();
}
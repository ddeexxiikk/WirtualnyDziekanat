#include "Log.h"
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>

Log::Log()
{
    auto data = time(nullptr);
    auto tmp = *localtime(&data);
    ostringstream oss;
    oss << put_time(&tmp, "%d-%m-%Y %H-%M-%S");
    nazwa_pliku = "logi\\" + oss.str();
    
    try
    {
        ofstream plik;
        plik.open(nazwa_pliku.c_str());
        plik << "Data urochomienia programu: " << oss.str() << endl;
        plik.close();
    }
    catch(const ofstream::failure& e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Log::zapisz_akcje(string wiadomosc)
{
    auto data = time(nullptr);
    auto tmp = *localtime(&data);
    ostringstream oss;
    oss << put_time(&tmp, "%d-%m-%Y %H-%M-%S");

    ofstream plik;
    plik.open(nazwa_pliku, ios::app);
    if(!plik.good())
    {
        return false;
    }

    plik << oss.str() << " >> " << wiadomosc << endl;
    plik.close();
    return true;
}
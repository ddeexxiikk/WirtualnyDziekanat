#ifndef LOG_H
#define LOG_H

using namespace std;
#include <string>

class Log
{
public:
    Log();
    bool zapisz_akcje(string wiadomosc);

private:
    string nazwa_pliku;
};

#endif
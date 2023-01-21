#ifndef OCENA_H
#define OCENA_H

using namespace std;

#include <string>

class Ocena
{
public:
    Ocena(string aprzedmiot, int asemestr, int aocena) : przedmiot(aprzedmiot), semestr(asemestr), ocena(aocena){}
            
    string przedmiot;
    int semestr;
    int ocena;
};

#endif // OCENA_H

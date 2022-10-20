#include "PolaczenieZBazaSQL.h"
#include <iostream>
#include <string>

using namespace std;

void PolaczenieZBazaSQL()
{
    //Proces Łączenia z Bazą SQL
    //Trzeba go zrobić

    //Jeśli się udało
    cout << "Polaczono z baza danych" << endl;

    //Jeśli się nie udało
    cout << "Brak polaczenia z baza danych" << endl;
};

string LoginZBazySQL()
{
    string PoprawnyLogin;
    //Proces Pobierania Loginu z Bazy SQL
    //Trzeba go zrobić

    bool Proces;

    if(Proces) //Jeśli się udało
    {
        PoprawnyLogin = "Login";
        return PoprawnyLogin;
    }
    else //Jeśli się nie udało
    {
        PoprawnyLogin = "BlednyLogin";
        return PoprawnyLogin;
    }
};

string HasloZBazySQL()
{
    string PoprawneHaslo;
    //Proces Pobierania Hasła z Bazy SQL
    //Trzeba go zrobić

    bool Proces;

    if(Proces) //Jeśli się udało
    {
        PoprawneHaslo = "Login";
        return PoprawneHaslo;
    }
    else //Jeśli się nie udało
    {
        PoprawneHaslo = "BlednyLogin";
        return PoprawneHaslo;
    }
};

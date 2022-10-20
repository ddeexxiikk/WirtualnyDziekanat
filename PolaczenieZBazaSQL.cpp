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
    //Proces Pobierania Loginu z Bazy SQL
    //Trzeba go zrobić


    //Jeśli się udało
    string PoprawnyLogin = "Login";
    return PoprawnyLogin;

    //Jeśli się nie udało
    string PoprawnyLogin = nullptr;
    return PoprawnyLogin;
};

string HasloZBazySQL()
{
    //Proces Pobierania Hasła z Bazy SQL
    //Trzeba go zrobić


    //Jeśli się udało
    string PoprawneHaslo = "Haslo";
    return PoprawneHaslo;

    //Jeśli się nie udało
    string PoprawneHaslo = nullptr;
    return PoprawneHaslo;
};

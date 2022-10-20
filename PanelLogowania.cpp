#include "PanelLogowania.h"
#include <iostream>
#include <string>

using namespace std;

void PanelLogowania()
{
    string login, haslo;
    cout << "Podaj login: ";
    cin >> login;
    cout << "Podaj haslo: ";
    cin >> haslo;
    if(CzyPoprawnyUzytkownik(login, haslo))
        cout << "Zalogowano poprawnie,\nZaraz przejdziemy dalej..." << endl;
    else
        cout << "Niepoprawny login lub hasło" << endl;
}

bool CzyPoprawnyUzytkownik(string aLogin, string aHaslo)
{
    string PoprawnyLogin /*= Login ZBazySQL*/;
    string PopraweneHaslo /*= Haslo ZBazySQL*/;
    if(aLogin == PoprawnyLogin && aHaslo == PopraweneHaslo)
        return true;
    else
        return false;
}

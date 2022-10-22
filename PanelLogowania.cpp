#include "PanelLogowania.h"
#include "PolaczenieZBazaSQL.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

bool PanelLogowania(string * aLoginUzytkownika)
{
    static int licznik_logowan;
    if(licznik_logowan == 3)
    {
        cout << "Przekroczono limit logowan" << endl;
        return false;
    }

    string login, haslo;
    cout << "Podaj login: ";
    cin >> login;
    cout << "Podaj haslo: ";
    cin >> haslo;
    if(CzyPoprawnyUzytkownik(login, haslo))
    {
        //Uzytkownik jest poprawny i przechodzimy dalej po 3 sekundach
        cout << "Zalogowano poprawnie,\nZaraz przejdziemy dalej..." << endl;
        Sleep(3000);
        *aLoginUzytkownika = login;

        //Zwraca TRUE i przechodzimy do Panelu Studenta/Pracownika
        return true;
    }
    else
    {
        //Jeśli użytkownik poda zły login lub hasło, system wyświetli tą informację
        cout << "Niepoprawny login lub hasło" << endl;
        cout << "Spróbuj ponownie..." << endl;

        //Czeka 2 sekundy, czyści ekran i ładuje proces logowania od początku
        Sleep(2000);
        system("CLS");
        licznik_logowan++;
        PanelLogowania(nullptr);
    }
}

bool CzyPoprawnyUzytkownik(string aLogin, string aHaslo)
{
    string LoginPoprawny = LoginZBazySQL(); /*Trzeba go dopiero pobrac z bazy i podmienic prosto do IF'a*/
    string HasloPoprawne = HasloZBazySQL(); /*Trzeba je dopiero pobrac z bazy i podmienic prosto do IF'a*/

    if(aLogin == LoginPoprawny && aHaslo == HasloPoprawne)
        return true;
    else
        return false;
}
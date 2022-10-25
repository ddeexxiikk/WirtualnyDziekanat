#include "PanelLogowania.h"
#include "PolaczenieZBazaSQL.h"
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

/*  Funkcja PanelLogowania() wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość BOOL, jaką ona zwróci*/
bool PanelLogowania(string * alogin_uzytkownika)
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
        *alogin_uzytkownika = login;

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

/*  Funkcja CzyPoprawnyUzytkownik() łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, je do danych z bazy i zwraca TRUE jeśli dane są poprawne, w przeciwnym wypadku zwraca FALSE*/
bool CzyPoprawnyUzytkownik(string alogin, string ahaslo)
{
    string login_poprawny = poprawny_login_z_bazy_SQL(); /*Trzeba go dopiero pobrac z bazy i podmienic prosto do IF'a*/
    string haslo_poprawne = poprawne_haslo_z_bazy_SQL(); /*Trzeba je dopiero pobrac z bazy i podmienic prosto do IF'a*/

    if(alogin == login_poprawny && ahaslo == haslo_poprawne)
        return true;
    else
        return false;
}
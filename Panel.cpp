#include "Panel.h"
#include "PolaczenieZBazaSQL.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

/*  Funkcja PanelLogowania() wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość BOOL, jaką ona zwróci*/
bool PanelLogowania(string * alogin_uzytkownika)
{
    if(!polaczenie_z_baza_SQL())
        return false;

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
    bool status = false;

    //Tworze plik, w którym prześlę login i hasło do skryptu Pythona
    fstream plik1;
    plik1.open("login.txt", ios::out);

    if(plik1.good())
    {
        //Wpisanie do pliku danych
        plik1 << alogin << endl;
        plik1 << ahaslo<< endl;
        plik1.close();

        //Wywołanie skryptu Pythona
        system("python3.6 CzyPoprawnyUzytkownik.py");


        //Odczytanie danych z drugiego pliku
        fstream plik2;
        plik2.open("wynik.txt", ios::in);
        if(plik2.good())
        {
            //Odczytanie danych i zmiana statusu


            plik2.close();
        }
        else
        {
            plik1.close();
            plik2.close();
            return false;
        }
    }
    else
    {
        plik1.close();
        return false;
    }


    if(status)
        return true;
    else
        return false;
}
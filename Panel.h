#ifndef WIRTUALNYDZIEKANAT_PANEL_H
#define WIRTUALNYDZIEKANAT_PANEL_H
#include <string>

using namespace std;

/*  Funkcja wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość BOOL, jaką ona zwróci*/
bool PanelLogowania(string * alogin_uzytkownika);

/*  Funkcja łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, je do danych z bazy i zwraca TRUE jeśli dane są poprawne, w przeciwnym wypadku zwraca FALSE*/
bool CzyPoprawnyUzytkownik(string alogin, string ahaslo);

#endif
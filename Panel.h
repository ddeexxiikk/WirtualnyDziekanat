#ifndef WIRTUALNYDZIEKANAT_PANEL_H
#define WIRTUALNYDZIEKANAT_PANEL_H
#include <string>

using namespace std;

/*  Funkcja wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość jaką ona zwróci
    w zależności od tego tworzy obiekt Student lub Pracownik w obiekcie przekazanym w argumencie
    oraz zwraca int będący poziomem dostępu użytkownika
*/
int PanelLogowania(void *&obiekt);

/*  Funkcja łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, znajduje poprawne dane logowania w pliku tekstowym i porówuje z podnymi.
    Zwraca poziom dostępu użytkownika lub 0 jeżeli dane są niepoprawne
*/
int CzyPoprawnyUzytkownik(string alogin, string ahaslo);

#endif

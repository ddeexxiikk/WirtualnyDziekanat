#ifndef WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#define WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#include "Czlowiek.h"
#include <string>

using namespace std;

//Login i haslo do bazy danych, aby pobierac te dane z tych zmiennych
//string LoginDoBazyDanychSQL;
//string HasloDoBazyDanychSQL;

string LoginZBazySQL();
string HasloZBazySQL();

bool PolaczenieZBazaSQL();

bool ZmianaHaslaPrzezStudenta();
bool ZmianaHaslaPrzezPracownika();

string PokazNumerStudenta(string * aLoginUzytkownika);
string PokazNumerStudentaPracownik();

bool DodanieStudenta();
bool UsuniecieStudenta();

void ZobaczenieOcenStudent();
void ZobaczenieOcenPracownik();
bool DodanieOceny();

void SprawdzenieGrupyStudent();
void SprawdzenieGrupyPracownik();

void SprawdzenieKsiazekStudent();
void SprawdzenieKsiazekPracownik();
bool DodanieKsiazki();
bool UsuniecieKsiazki();

void SprawdzeniePlanuZajec();
void SprawdzeniePlanuZajecPracownik();

void PrzegladniecieOgloszenStudent();
void PrzegladniecieOgloszenPracownik();
bool DodanieOgloszen();
bool UsuniecieOgloszen();

#endif

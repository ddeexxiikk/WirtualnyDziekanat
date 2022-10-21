#ifndef WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#define WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#include "Czlowiek.h"
#include <string>

using namespace std;

//Wstawic login i haslo do bazy SQL
//string LoginDoBazyDanych = LOGIN,
//HasloDoBazyDanych = HASLO;

string LoginZBazySQL();
string HasloZBazySQL();

bool PolaczenieZBazaSQL();

bool ZmianaHaslaPrzezStudenta();
bool ZmianaHaslaPrzezPracownika();

string PokazNumerStudenta();
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

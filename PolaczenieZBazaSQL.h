#ifndef WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#define WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#include "Czlowiek.h"
#include <string>

using namespace std;

string LoginDoBazyDanych, HasloDoBazyDanych;

string LoginZBazySQL();
string HasloZBazySQL();

bool PolaczenieZBazaSQL();

bool ZmianaHaslaPrzezStudenta();
bool ZmianaHaslaPrzezPracownika();
bool ZmianaHaslaPrzezAdmina();

string PokazNumerStudenta();
string PokazNumerStudentaPracownik(string aImie, string aNazwisko);

bool DodanieStudenta();
bool UsuniecieStudenta(string NrStudenta);
bool DodaniePracownika();

void ZobaczenieOcenStudent();
void ZobaczenieOcenPracownik(string NrStudenta);
bool DodanieOceny(string NrStudenta);

void SprawdzenieGrupyStudent();
void SprawdzenieGrupyPracownik(string NrStudenta);

void SprawdzenieKsiazekStudent();
void SprawdzenieKsiazekPracownik(string NrStudenta);

void SprawdzeniePlanuZajec();
void SprawdzeniePlanuZajecPracownik(string NrStudenta);

void PrzegladniecieOgloszenStudent();
void PrzegladniecieOgloszenPracownik();
bool DodanieOgloszen();
bool UsuniecieOgloszen(string NrOgloszenia);

#endif

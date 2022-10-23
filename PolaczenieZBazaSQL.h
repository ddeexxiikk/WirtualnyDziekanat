#ifndef WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#define WIRTUALNYDZIEKANAT_POLACZENIEZBAZASQL_H
#include "Czlowiek.h"
#include <string>

using namespace std;

string poprawny_login_z_bazy_SQL();
string poprawne_haslo_z_bazy_SQL();

bool polaczenie_z_baza_SQL();

bool zmiana_hasla_przez_studenta();
bool zmiana_hasla_przez_pracownika();

string pokaz_numer_student(string * alogin_uzytkownika);
string pokaz_numer_studenta_pracownik();

bool dodanie_studenta();
bool usuniecie_studenta();

void zobaczenie_ocen_student();
void zobaczenie_ocen_studenta_pracownik();
bool dodanie_oceny();

void sprawdzenie_grupy_student();
void sprawdzenie_grupy_studenta_pracownik();

void sprawdzenie_ksiazek_student();
void sprawdzenie_ksiazek_studenta_pracownik();
bool dodanie_ksiazki();
bool usuniecie_ksiazki();

void sprawdzenie_planu_zajec_student();
void sprawdzenie_planu_zajec_studenta_pracownik();

void przegladniecie_ogloszen();
bool dodanie_ogloszen();
bool usuniecie_ogloszen();

#endif

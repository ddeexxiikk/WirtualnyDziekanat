#ifndef WIRTUALNYDZIEKANAT_PANELLOGOWANIA_H
#define WIRTUALNYDZIEKANAT_PANELLOGOWANIA_H
#include <string>

using namespace std;

bool PanelLogowania(string * alogin_uzytkownika);

bool CzyPoprawnyUzytkownik(string alogin, string ahaslo);

#endif
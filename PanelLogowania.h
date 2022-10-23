#ifndef WIRTUALNYDZIEKANAT_PANELLOGOWANIA_H
#define WIRTUALNYDZIEKANAT_PANELLOGOWANIA_H
#include <string>

using namespace std;

bool PanelLogowania(string * aLoginUzytkownika);

bool CzyPoprawnyUzytkownik(string aLogin, string aHaslo);

#endif
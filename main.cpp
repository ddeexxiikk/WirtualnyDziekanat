#include "Panel.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Pracownik.h"
#include "Log.h"
#include "Plan_zajec.h"

using namespace std;

int main()
{
    Log log;
    cout << "Witaj w Wirtualnym Dziekanacie" << endl;
    cout << "Zaloguj sie aby przejsc dalej..." << endl;
    void *obiekt;
    int poziom_dostepu=PanelLogowania(obiekt, log);
    int opcja;
    bool result = true;
    while(result)
    {
        opcja=wyswietlanie_menu(poziom_dostepu);
        result=obsluz_opcje(opcja, obiekt, log);
    }
    if(!log.zapisz_akcje("zakonczono dzialanie programu")) return 1;
    delete obiekt;
    return 0;
}

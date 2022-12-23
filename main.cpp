#include "Panel.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Pracownik.h"

#include "Plan_zajec.h"

using namespace std;

int main()
{
    cout << "Witaj w Wirtualnym Dziekanacie" << endl;
    cout << "Zaloguj sie aby przejsc dalej..." << endl;
    void *obiekt;
    int poziom_dostepu=PanelLogowania(obiekt);
    int opcja;
    bool result;
    while(true)
    {
        opcja=wyswietlanie_menu(poziom_dostepu);
        result=obsluz_opcje(opcja, obiekt);
    }
    delete obiekt;
    return 0;
}

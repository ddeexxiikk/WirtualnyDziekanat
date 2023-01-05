#include "Panel.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include "Student.h"
#include "Pracownik.h"
#include "Log.h"
#include "Plan_zajec.h"
#include "Wyjatki.h"

using namespace std;

int main()
{
    try
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
        log.zapisz_akcje("zakonczono dzialanie programu");
        delete obiekt;
        return 0;
    }
    catch(const BladPliku& e)
    {
        cerr << e.what() << endl;
    }
}

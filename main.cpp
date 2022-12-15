#include "Panel.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
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
    if(poziom_dostepu==1) ((Student*)obiekt)->display();
    if(poziom_dostepu==2) ((Pracownik*)obiekt)->display();
    delete obiekt;
    return 0;
}

#include "PolaczenieZBazaSQL.h"
#include "PanelLogowania.h"
#include "Czlowiek.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Witaj w Wirtualnym Dziekanacie" << endl;
    cout << "Zaloguj sie aby przejsc dalej..." << endl;

    //Proces logowania
    if(PanelLogowania())
    {
        //Uzytkownik jest poprawny i czekamy 1s
        cout << "Zalogowano poprawnie,\nZaraz przejdziemy dalej..." << endl;
        Sleep(1000);
    }
    else
        //Jeśli użytkownik więcej niż 3 pomyli się przy logowaniu, program się wyłączy
        exit(0);

    //Od tego momentu możemy przejść do profilu Studenta/Pracownika
    //Mozecie tutaj wrzucic funkcje profilow
    //W tym momencie jestem w stanie tylko sprawdzic czy dziala logowanie na sztywne dane, bo jeszcze nie stworzyłem bazy danych

    return 0;
}

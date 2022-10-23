#include "PanelLogowania.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Witaj w Wirtualnym Dziekanacie" << endl;
    cout << "Zaloguj sie aby przejsc dalej..." << endl;

    //Zmienna string przechowywuje przez cały czas działania programu, login użytkownika w pamięci RAM
    string LoginUzytkownikaWMainie;

    //Proces logowania
    if(PanelLogowania(&LoginUzytkownikaWMainie))
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

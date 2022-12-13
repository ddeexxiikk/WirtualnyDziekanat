#include "Panel.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Witaj w Wirtualnym Dziekanacie" << endl;
    cout << "Zaloguj sie aby przejsc dalej..." << endl;

    //Zmienna string przechowywuje przez cały czas działania programu, login użytkownika w pamięci RAM
    string login_uzytkownika_w_mainie;

    //Proces logowania
    if(PanelLogowania(&login_uzytkownika_w_mainie))
    {
        //Uzytkownik jest poprawny i czekamy 1s
        cout << "Zalogowano poprawnie,\nZaraz przejdziemy dalej..." << endl;
        Sleep(1000);

        //Od tego momentu możemy przejść do profilu Studenta/Pracownika
        //Mozecie tutaj wrzucic funkcje klas Studenta i Pracownika
        //W tym momencie jestem w stanie tylko sprawdzic czy dziala logowanie na sztywne dane

    }
    else //Jeśli użytkownik więcej niż 3 pomyli się przy logowaniu lub nie będzie połączenia z bazą
    // program się wyłączy
    {
        cout << "Blad logowania, program sie wyłączy" << endl;
        Sleep(2000);
        exit(0);
    }

    return 0;
}

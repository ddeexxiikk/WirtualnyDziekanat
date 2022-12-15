#include "Panel.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "Student.h"
#include "Pracownik.h"

using namespace std;

/*  Funkcja wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość jaką ona zwróci
    w zależności od tego tworzy obiekt Student lub Pracownik w obiekcie przekazanym w argumencie
    oraz zwraca int będący poziomem dostępu użytkownika
*/
int PanelLogowania(void *&obiekt)
{
    static int counter=0;
    if(counter==3) exit(1);
    string login, password;
    cout<<"Podaj login: ";
    cin>>login;
    cout<<"Podaj haslo: ";
    cin>>password;
    int result=CzyPoprawnyUzytkownik(login, password);
    if(result!=0)
    {
        if(result==1) obiekt = new Student("Student data.txt", login);
        if(result==2) obiekt = new Pracownik("Worker data.txt", login);
        return result;
    }
    counter++;
    system("cls");
    Sleep(500);
    cout<<"Niepoprawne haslo lub login, sprobuj ponownie"<<endl;
    PanelLogowania(obiekt);
}

/*  Funkcja łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, znajduje poprawne dane logowania w pliku tekstowym i porówuje z podnymi.
    Zwraca poziom dostępu użytkownika lub 0 jeżeli dane są niepoprawne
*/
int CzyPoprawnyUzytkownik(string alogin, string ahaslo)
{
    ifstream logowanie;
    logowanie.open("Users.txt");
    string temp_login, temp_password;
    int access_lvl;
    while(logowanie>>temp_login>>temp_password>>access_lvl)
    {
        if(temp_login==alogin&&temp_password==ahaslo)
        {
            logowanie.close();
            return access_lvl;
        }
    }
    logowanie.close();
    return 0;
}

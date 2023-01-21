#include "Czlowiek.h"
#include <fstream>
#include <iostream>
#include "Wyjatki.h"

using namespace std;

Czlowiek::Czlowiek(string alogin, string aimie, string anazwisko)
{
    imie = aimie;
    nazwisko = anazwisko;
    login = alogin;
};

void Czlowiek::zmien_haslo(string file_name, string nowe_haslo)
{
    ifstream dane;
    ofstream temp;
    dane.open(file_name.c_str());
    temp.open("temp.txt");
    if(!dane.good())
    {
        dane.close();
        throw BladPliku(string("blad pliku - " + file_name).c_str());
    }
    if(!temp.good())
    {
        temp.close();
        throw BladPliku("blad pliku - temp.txt");
    }
    string temp_login, temp_password;
    int access_lvl;
    while(dane>>temp_login>>temp_password>>access_lvl)
    {
        if(temp_login==login) temp_password=nowe_haslo;
        temp<<temp_login<<" "<<temp_password<<" "<<access_lvl<<endl;
    }
    dane.close();
    temp.close();
    remove(file_name.c_str());
    rename("temp.txt", file_name.c_str());
}

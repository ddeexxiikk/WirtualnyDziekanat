#include "Pracownik.h"
#include <fstream>
#include <iostream>

Pracownik::Pracownik(string alogin, string aimie, string anazwisko):Czlowiek(alogin, aimie, anazwisko)
{
    //ctor
    //this.Czlowiek(*alogin, *aimie, *anazwisko);
}

Pracownik::Pracownik(string file_name, string alogin):Czlowiek("", "", "")
{
    ifstream data;
    data.open(file_name.c_str());
    string temp_login, temp_imie, temp_nazwisko;
    while(data>>temp_login>>temp_imie>>temp_nazwisko)
    {
        if(temp_login==alogin)
        {
            imie=temp_imie;
            nazwisko=temp_nazwisko;
            login=alogin;
            //cout<<temp_imie<<" "<<temp_nazwisko<<" "<<temp_login<<endl;
        }
    }
    data.close();
}

bool Pracownik::oceny_studenta::dodanie_oceny(int ocena, int semestr)
{
    this->oceny_koncowe[semestr]=ocena;
    return true;
}

void Pracownik::display()
{
    cout<<"Pracownik: "<<imie<<" "<<nazwisko<<endl;
}

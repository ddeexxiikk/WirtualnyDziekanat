#include "Student.h"
#include <fstream>
#include <iostream>

Student::Student(string alogin, string aimie, string anazwisko, string akierunek, int asemestr):Czlowiek(alogin, aimie, anazwisko)
{
    //ctor
    semestr=asemestr;
    kierunek=akierunek;
}

Student::Student(string file_name, string alogin):Czlowiek("", "", "")
{
    cout<<"Stworzony student"<<imie<<" "<<nazwisko<<endl;

    ifstream data;
    data.open(file_name.c_str());
    string temp_login, temp_imie, temp_nazwisko, temp_kierunek, temp_grupa;
    int temp_semestr;

    while(data>>temp_login>>temp_imie>>temp_nazwisko>>temp_kierunek>>temp_grupa>>temp_semestr)
    {
        if(temp_login==alogin)
        {
            imie=temp_imie;
            nazwisko=temp_nazwisko;
            login=alogin;
            kierunek=temp_kierunek;
            grupa=temp_grupa;
            semestr=temp_semestr;
        }
    }
    data.close();
}

bool Student::oceny_studenta::dodanie_oceny(int ocena, int semestr)
{
    return false;
}

void Student::display()
{
    cout<<"Student: "<<imie<<" "<<nazwisko<<endl;
}

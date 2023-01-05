#include "Student.h"
#include <fstream>
#include <iostream>
#include "Wyjatki.h"

Student::Student(string alogin, string aimie, string anazwisko, string akierunek, int asemestr):Czlowiek(alogin, aimie, anazwisko)
{
    //ctor
    semestr=asemestr;
    kierunek=akierunek;
}
Student::Student(string file_name, string alogin):Czlowiek("", "", "")
{
    ifstream data;
    data.open(file_name.c_str());
    if(!data.good())
    {
        data.close();
        throw BladPliku("blad pliku - " + file_name);
    }
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
    plan.import("Plan zajec.txt", kierunek, grupa);
    //plan("Plan zajec test.txt", kierunek, grupa);
}

bool Student::oceny_studenta::dodanie_oceny(int ocena, int semestr)
{
    return false;
}

void Student::display()
{
    cout<<"Student: "<<imie<<" "<<nazwisko<<endl;
}

string Student::sprawdzenie_grupy()
{
    return grupa;
}

void Student::wyswietl_plan()
{
    plan.display();
}

#include "Pracownik.h"
#include <fstream>
#include <iostream>
#include <sstream>

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

string Pracownik::sprawdzenie_grupy_student(string file_name, string alogin)
{
    ifstream data;
    data.open(file_name.c_str());
    string temp;
    while(data>>temp)
    {
        if(temp==alogin)
        {
            data>>temp>>temp>>temp>>temp;
            data.close();
            return temp;
        }
    }
    data.close();
    return "Nie znaleziono studenta";
}

bool Pracownik::oceny_studenta::dodanie_oceny(int ocena, int semestr)
{
    //this->oceny_koncowe[semestr]=ocena;
    return true;
}

void Pracownik::display()
{
    cout<<"Pracownik: "<<imie<<" "<<nazwisko<<endl;
}

bool Pracownik::dodaj_ocene(string file_name, string alogin, int ocena, int semestr)
{
    ofstream data;
    data.open(file_name.c_str());
    //data<<
    data.close();
    return true;
}

int Pracownik::sprawdz_ocene(string file_name, string alogin, string przedmiot, int semestr)
{
    ifstream data;
    data.open(file_name.c_str());
    if(data.good())
    {
        string line, temp_login, temp_przedmiot, temp_semestr, temp_ocena;
        while(getline(data, line))
        {
            istringstream csvStream(line);
            getline(csvStream, temp_login, ';');
            getline(csvStream, temp_przedmiot, ';');
            getline(csvStream, temp_semestr, ';');
            getline(csvStream, temp_ocena, ';');
            if(temp_login==alogin&&temp_przedmiot==przedmiot&&stoi(temp_semestr)==semestr)
            {
                data.close();
                return stoi(temp_ocena);
            }
        }
        //jeœli nie znaleziono oceny z danego przedmiotu i danego semestru to zwraca 0
        data.close();
        return 0;
    }
    //jeœli nie uda³o siê otworzyæ pliku to zwraca -1
    data.close();
    return -1;
}

bool Pracownik::dodaj_studenta(string alogin, string ahaslo, string grupa, string wydzial, string aimie, string anazwisko, string semestr)
{
    ofstream logowanie;
    logowanie.open("Users.txt", ios::app);
    if(!logowanie.good())
    {
        logowanie.close();
        return false;
    }
    logowanie<<endl<<alogin<<" "<<ahaslo<<" 1"<<endl;
    logowanie.close();
    ofstream dane;
    dane.open("Student data.txt", ios::app);
    if(!dane.good())
    {
        dane.close();
        return false;
    }
    dane<<endl<<alogin<<" "<<aimie<<" "<<anazwisko<<" "<<wydzial<<" "<<grupa<<" "<<semestr<<endl; // dodać semestr
    dane.close();
    return true;
}

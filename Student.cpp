#include "Student.h"
#include <fstream>
#include <iostream>
#include "Wyjatki.h"
#include <string>
#include <sstream>
#include <algorithm>

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
        throw BladPliku(string("blad pliku - " + file_name).c_str());
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
    plan.import("baza\\Plan Zajec.txt", kierunek, grupa);
    wczytaj_ksiazki();
    wczytaj_oceny();
    //plan("Plan zajec test.txt", kierunek, grupa);
}

bool Student::wczytaj_ksiazki()
{
    ifstream plik;
    plik.open("baza\\Ksiazki Studentow.txt");
    if(!plik.good())
    {
        plik.close();
        throw BladPliku(string("blad pliku - Ksiazki Studentow.txt").c_str());
    }

    string linia, login_temp;

    while(getline(plik, linia))
    {
        size_t pierwsza_spacja = linia.find_first_of(' ');
        login_temp = linia.substr(0, pierwsza_spacja);
        if(login_temp == login)
        {
            lista_ksiazek.push_back(linia.substr(pierwsza_spacja));
        }
    }

    plik.close();
    return true;
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

vector<string> Student::sprawdz_liste_ksiazek()
{
    return lista_ksiazek;
}

bool Student::wczytaj_oceny()
{
    ifstream data;
    data.open("baza\\Oceny.txt");
    string line, temp_login, temp_przedmiot, temp_semestr, temp_ocena;
    if(!data.good())
    {
        data.close();
        throw BladPliku("blad pliku - Oceny.txt");
    }
        
    while(getline(data, line))
    {
        istringstream csvStream(line);
        getline(csvStream, temp_login, ';');
        getline(csvStream, temp_przedmiot, ';');
        getline(csvStream, temp_semestr, ';');
        getline(csvStream, temp_ocena, ';');
        if(temp_login==login)
        {
             oceny.push_back(Ocena(temp_przedmiot, stoi(temp_semestr), stoi(temp_ocena)));
        }
    }
    data.close();
    return true;
}

vector<pair<int, Ocena>> Student::sprawdz_oceny_w_calym_toku_studiow()
{
    vector<pair<int, Ocena>> temp;
    vector<Ocena> temp_oceny;
    ifstream data;
    data.open("baza\\Oceny.txt");
    if(!data.good())
    {
        data.close();
        throw BladPliku(string("blad pliku - baza\\Oceny.txt").c_str());
    }

    string line, temp_login, temp_przedmiot, temp_semestr, temp_ocena;
    while(getline(data, line))
    {
        istringstream csvStream(line);
        getline(csvStream, temp_login, ';');
        getline(csvStream, temp_przedmiot, ';');
        getline(csvStream, temp_semestr, ';');
        getline(csvStream, temp_ocena, ';');
        if(login == temp_login)
        {
            temp_oceny.push_back(Ocena(temp_przedmiot, stoi(temp_semestr), stoi(temp_ocena)));
        }
    }

    sort(temp_oceny.begin(), temp_oceny.end(), 
    [](const Ocena& o1, const Ocena& o2)
    {
        if(o1.ocena > o2.ocena)
        {
            return true;
        }
        else
        {
            return false;
        }
    });
    
    for(std::size_t i = 0; i < temp_oceny.size(); i++)
    {
       temp.push_back(make_pair(temp_oceny.at(i).semestr, temp_oceny.at(i)));
    }

    data.close();
    return temp;
}

vector<Ocena> Student::sprawdz_oceny(int asemestr)
{
    vector<Ocena> temp;
    for(const auto& e: oceny)
    {
        if(e.semestr == asemestr)
        {
            temp.push_back(e);
        }
    }

    return temp;
}

void Student::wyswietl_informacje()
{
    cout << "Student: " << imie << " " << nazwisko << endl;
}

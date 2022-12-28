#include "Pracownik.h"
#include "Plan_zajec.h"
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

bool Pracownik::dodaj_ocene(string alogin, string aprzedmiot, int semestr, double ocena)
{
    ofstream data;
    data.open("grades.txt", ios::app);
    if(!data.good())
    {
        data.close();
        return false;
    }
    data << alogin << ";" << aprzedmiot << ";" << semestr << ";" << ocena << '\n';
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

bool Pracownik::usun_studenta(string alogin, string aimie, string anazwisko)
{
    string line;
    string plik;
    string templogin;
    string tempimie;
    string tempnazwisko;
    string tempdostep;

    ifstream data_odczyt;
    data_odczyt.open("Student data.txt");
    if(!data_odczyt.good())
    {
        data_odczyt.close();
        return false;
    }
 
    while(getline(data_odczyt, line))
    {
        size_t pierwsza_spacja = line.find(' ');
        if(pierwsza_spacja != string::npos)
        {
            templogin = line.substr(0, pierwsza_spacja);
            tempimie = line.substr(pierwsza_spacja, line.find(' '));
        }

        size_t druga_spacja = line.find(pierwsza_spacja, ' ');
        if(druga_spacja != string::npos)
        {
            tempnazwisko = line.substr(druga_spacja, line.find(' '));
        }
    
        if(stoi(alogin) != stoi(templogin) && aimie != tempimie && anazwisko != tempnazwisko)
        {
            plik += line + '\n';
        }
    }
    data_odczyt.close();

    ofstream data_zapis;
    data_zapis.open("Student data.txt", ios::trunc);
    if(!data_zapis.good())
    {
        data_zapis.close();
        return false;
    }
    data_zapis << plik;
    data_zapis.close();


    plik.clear();
    line.clear();
    ifstream users_odczyt;
    users_odczyt.open("Users.txt");  
    if(!users_odczyt.good())
    {
        users_odczyt.close();
        return false;
    }
    while(getline(users_odczyt, line))
    {
        size_t pierwsza_spacja = line.find(' ');

        if(pierwsza_spacja != string::npos)
        {
            templogin = line.substr(0, pierwsza_spacja);
        }

        tempdostep = line.at(line.size() - 1);

        if(stoi(alogin) != stoi(templogin) || stoi(tempdostep) == 2)
        {   
            plik += line + '\n';
        }
    }
    users_odczyt.close();

    ofstream users_zapis;
    users_zapis.open("Users.txt", ios::trunc);
    if(!users_zapis.good())
    {
        users_zapis.close();
        return false;
    }
    users_zapis << plik;
    users_zapis.close();

    return true;
}

bool Pracownik::sprawdz_plan_zajec_studenta(string akierunek, string agrupa)
{
    Plan_zajec plan;
    plan.import("Plan zajec.txt", akierunek, agrupa);
    plan.display();

    return true;
}

int Pracownik::dodaj_ksiazke_studentowi(string alogin, string atytul)
{
    ifstream ksiazki_odczyt;
    ksiazki_odczyt.open("ListaKsiazek.txt");
    if(!ksiazki_odczyt.good())
    {
        ksiazki_odczyt.close();
        return -1;
    }

    string plik;
    string line;
    string temptytul;
    string tempilosc;
    bool czy_dostepna = false;
    while(getline(ksiazki_odczyt, line))
    {
        size_t pierwsza_spacja = line.find_last_of(' ');

        if(pierwsza_spacja != string::npos)
        {
            temptytul = line.substr(0, pierwsza_spacja);
            tempilosc = line.substr(pierwsza_spacja + 1);
        }
        if(temptytul == atytul && stoi(tempilosc) != 0)
        {
            int nowa_ilosc = stoi(tempilosc) - 1;
            line.clear();
            line = temptytul + " " + to_string(nowa_ilosc);
            czy_dostepna = true;
        }

        plik += line + '\n';
    }

    ksiazki_odczyt.close();
    if(!czy_dostepna)
    {
        return 1;
    }

    ofstream ksiazki_zapis;
    ksiazki_zapis.open("ListaKsiazek.txt", ios::trunc);
    if(!ksiazki_zapis.good())
    {
        ksiazki_zapis.close();
        return -1;
    }
    ksiazki_zapis << plik;
    ksiazki_zapis.close();

    ofstream ksiazki;
    ksiazki.open("ksiazki studentow.txt", ios::app);
    if(!ksiazki.good())
    {
        ksiazki.close();
        return -1;
    }

    ksiazki << alogin << " " << atytul << endl;
    ksiazki.close();
    return 0;
}

bool Pracownik::usun_ksiazke_studentowi(string alogin, string atytul)
{
    ifstream ksiazki_odczyt;
    ksiazki_odczyt.open("ksiazki studentow.txt");
    if(!ksiazki_odczyt.good())
    {
        ksiazki_odczyt.close();
        return false;
    }

    string plik;
    string line;
    string temptytul;
    string tempilosc;
    while(getline(ksiazki_odczyt, line))
    {
        size_t pierwsza_spacja = line.find(' ');

        if(pierwsza_spacja != string::npos)
        {
            temptytul = line.substr(pierwsza_spacja + 1);
        }
        if(temptytul != atytul)
        {
            plik += line + '\n';
        }
    }
    ksiazki_odczyt.close();

    ofstream ksiazki_zapis;
    ksiazki_zapis.open("ksiazki studentow.txt", ios::trunc);
    if(!ksiazki_zapis.good())
    {
        ksiazki_zapis.close();
        return false;
    }
    ksiazki_zapis << plik;
    ksiazki_zapis.close();

    ifstream lista_ksiazek_odczyt;
    lista_ksiazek_odczyt.open("ListaKsiazek.txt");
    if(!lista_ksiazek_odczyt.good())
    {
        lista_ksiazek_odczyt.close();
        return false;
    }

    plik.clear();
    line.clear();
    while(getline(lista_ksiazek_odczyt, line))
    {
        size_t pierwsza_spacja = line.find_last_of(' ');

        if(pierwsza_spacja != string::npos)
        {
            temptytul = line.substr(0, pierwsza_spacja);
            tempilosc = line.substr(pierwsza_spacja + 1);
        }
        if(temptytul == atytul && stoi(tempilosc) != 0)
        {
            int nowa_ilosc = stoi(tempilosc) + 1;
            line.clear();
            line = temptytul + " " + to_string(nowa_ilosc);
        }

        plik += line + '\n';
    }
    lista_ksiazek_odczyt.close();

    ofstream lista_ksiazek_zapis;
    lista_ksiazek_zapis.open("ListaKsiazek.txt", ios::trunc);
    if(!lista_ksiazek_zapis.good())
    {
        lista_ksiazek_zapis.close();
        return false;
    }

    lista_ksiazek_zapis << plik;
    lista_ksiazek_zapis.close();
    return true;
}

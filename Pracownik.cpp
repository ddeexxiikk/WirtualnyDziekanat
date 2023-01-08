#include "Pracownik.h"
#include "Plan_zajec.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Log.h"
#include "Wyjatki.h"

#define TEST_WYJATKOW false

Pracownik::Pracownik(string alogin, string aimie, string anazwisko):Czlowiek(alogin, aimie, anazwisko)
{
    //ctor
    //this.Czlowiek(*alogin, *aimie, *anazwisko);
}

Pracownik::Pracownik(string file_name, string alogin):Czlowiek("", "", "")
{
    ifstream data;
    data.open(file_name.c_str());
    if(!data.good())
    {
        data.close();
        throw BladPliku(string("blad pliku - " + file_name).c_str());
    }
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

int Pracownik::_stoi(const string& str, size_t* pos = 0, int base = 10)
{
    try 
    {
        int temp = stoi(str, pos, base);
        return temp;
    }
    catch (const invalid_argument& ia) 
    {
        return 0;
    }
    catch (const out_of_range& oor) 
    {
        return 0;
    }
    catch (const exception& e)
    {
        return 0;
    }
}

string Pracownik::sprawdzenie_grupy_student(string file_name, string alogin)
{
    ifstream data;
    data.open(file_name.c_str());
    if(!data.good())
    {
        data.close();
        throw BladPliku(string("blad pliku - " + file_name).c_str());
    }
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

void Pracownik::wyswietl_informacje()
{
    cout << "Pracownik: " << imie << " " << nazwisko << endl;
}

void Pracownik::dodaj_ocene(string alogin, string aprzedmiot, int semestr, double ocena)
{
    ofstream data;
    data.open("baza\\Oceny.txt", ios::app);
    if(!data.good())
    {
        data.close();
        throw BladPliku("blad pliku - Oceny.txt");
    }
    data << alogin << ";" << aprzedmiot << ";" << semestr << ";" << ocena;
    data.close();
}

int Pracownik::sprawdz_ocene(string file_name, string alogin, string przedmiot, int semestr)
{
    #if TEST_WYJATKOW
        throw BladPliku("test wyjatkow - blad pliku - " + file_name);
    #endif

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
            if(temp_login==alogin&&temp_przedmiot==przedmiot&&_stoi(temp_semestr)==semestr)
            {
                data.close();
                return _stoi(temp_ocena);
            }
        }
        //jeœli nie znaleziono oceny z danego przedmiotu i danego semestru to zwraca 0
        data.close();
        return 0;
    }
    //jeœli nie uda³o siê otworzyæ pliku to zwraca -1
    data.close();
    throw BladPliku(string("blad pliku - " + file_name).c_str());
}

void Pracownik::dodaj_studenta(string alogin, string ahaslo, string grupa, string wydzial, string aimie, string anazwisko, string semestr)
{
    ofstream logowanie;
    logowanie.open("baza\\Uzytkownicy.txt", ios::app);
    if(!logowanie.good())
    {
        logowanie.close();
        throw BladPliku("blad pliku - Uzytkownicy.txt");
    }
    logowanie<<endl<<alogin<<" "<<ahaslo<<" 1";
    logowanie.close();
    ofstream dane;
    dane.open("baza\\Student dane.txt", ios::app);
    if(!dane.good())
    {
        dane.close();
        throw BladPliku("blad pliku - Student dane.txt");
    }
    dane<<endl<<alogin<<" "<<aimie<<" "<<anazwisko<<" "<<wydzial<<" "<<grupa<<" "<<semestr; // dodać semestr
    dane.close();
}

void Pracownik::usun_studenta(string alogin, string aimie, string anazwisko)
{
    string line;
    string plik;
    string templogin;
    string tempimie;
    string tempnazwisko;
    string tempdostep;

    ifstream data_odczyt;
    data_odczyt.open("baza\\Student dane.txt");
    if(!data_odczyt.good())
    {
        data_odczyt.close();
        throw BladPliku("blad pliku - Student dane.txt");
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

        if(_stoi(alogin) != _stoi(templogin) && aimie != tempimie && anazwisko != tempnazwisko)
        {
            plik += line + '\n';
        }
    }
    data_odczyt.close();

    ofstream data_zapis;
    data_zapis.open("baza\\Student dane.txt", ios::trunc);
    if(!data_zapis.good())
    {
        data_zapis.close();
        throw BladPliku("blad pliku - Student dane.txt");
    }
    data_zapis << plik;
    data_zapis.close();

    plik.clear();
    line.clear();
    ifstream users_odczyt;
    users_odczyt.open("baza\\Uzytkownicy.txt");  
    if(!users_odczyt.good())
    {
        users_odczyt.close();
        throw BladPliku("blad pliku - Uzytkownicy.txt");
    }
    while(getline(users_odczyt, line))
    {
        size_t pierwsza_spacja = line.find(' ');

        if(pierwsza_spacja != string::npos)
        {
            templogin = line.substr(0, pierwsza_spacja);
        }

        tempdostep = line.at(line.size() - 1);

        if(_stoi(alogin) != _stoi(templogin) || _stoi(tempdostep) == 2)
        {   
            plik += line + '\n';
        }
    }
    users_odczyt.close();

    ofstream users_zapis;
    users_zapis.open("baza\\Uzytkownicy.txt", ios::trunc);
    if(!users_zapis.good())
    {
        users_zapis.close();
        throw BladPliku("blad pliku - Uzytkownicy.txt");
    }
    users_zapis << plik;
    users_zapis.close();
}

bool Pracownik::sprawdz_plan_zajec_studenta(string akierunek, string agrupa)
{
    Plan_zajec plan;
    plan.import("baza\\Plan zajec.txt", akierunek, agrupa);
    plan.display();

    return true;
}

int Pracownik::dodaj_ksiazke_studentowi(string alogin, string atytul)
{
    ifstream ksiazki_odczyt;
    ksiazki_odczyt.open("baza\\Lista Ksiazek.txt");
    if(!ksiazki_odczyt.good())
    {
        ksiazki_odczyt.close();
        throw BladPliku("blad pliku - Lista Ksiazek.txt");
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
        if(temptytul == atytul && _stoi(tempilosc) != 0)
        {
            int nowa_ilosc = _stoi(tempilosc) - 1;
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
    ksiazki_zapis.open("baza\\Lista Ksiazek.txt", ios::trunc);
    if(!ksiazki_zapis.good())
    {
        ksiazki_zapis.close();
        throw BladPliku("baza\\Lista Ksiazek.txt");
    }
    ksiazki_zapis << plik;
    ksiazki_zapis.close();

    ofstream ksiazki;
    ksiazki.open("baza\\Ksiazki Studentow.txt", ios::app);
    if(!ksiazki.good())
    {
        ksiazki.close();
        throw BladPliku("blad pliku - Ksiazki Studentow.txt");
    }

    ksiazki << alogin << " " << atytul << endl;
    ksiazki.close();
    return 0;
}

int Pracownik::usun_ksiazke_studentowi(string alogin, string atytul)
{
    ifstream ksiazki_odczyt;
    ksiazki_odczyt.open("baza\\Ksiazki Studentow.txt");
    if(!ksiazki_odczyt.good())
    {
        ksiazki_odczyt.close();
        throw BladPliku("blad pliku - Ksiazki Studentow.txt");
    }

    string plik;
    string line;
    string temptytul;
    string tempilosc;
    bool czy_brak_ksiazki = false;
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
        else
        {
            czy_brak_ksiazki = true;
        }
    }
    ksiazki_odczyt.close();

    if(czy_brak_ksiazki)
    {
        return 1;
    }

    ofstream ksiazki_zapis;
    ksiazki_zapis.open("baza\\Ksiazki Studentow.txt", ios::trunc);
    if(!ksiazki_zapis.good())
    {
        ksiazki_zapis.close();
        throw BladPliku("blad pliku - Ksiazki Studentow.txt");
    }
    ksiazki_zapis << plik;
    ksiazki_zapis.close();

    ifstream lista_ksiazek_odczyt;
    lista_ksiazek_odczyt.open("baza\\Lista Ksiazek.txt");
    if(!lista_ksiazek_odczyt.good())
    {
        lista_ksiazek_odczyt.close();
        throw BladPliku("blad pliku - Lista Ksiazek.txt");
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
        if(temptytul == atytul && _stoi(tempilosc) != 0)
        {
            int nowa_ilosc = _stoi(tempilosc) + 1;
            line.clear();
            line = temptytul + " " + to_string(nowa_ilosc);
        }

        plik += line + '\n';
    }
    lista_ksiazek_odczyt.close();

    ofstream lista_ksiazek_zapis;
    lista_ksiazek_zapis.open("baza\\Lista Ksiazek.txt", ios::trunc);
    if(!lista_ksiazek_zapis.good())
    {
        lista_ksiazek_zapis.close();
        throw BladPliku("blad pliku - Lista Ksiazek.txt");
    }

    lista_ksiazek_zapis << plik;
    lista_ksiazek_zapis.close();

    return 0;
}

void Pracownik::dodaj_plan_zajec(string kierunek, string grupa, Plan_zajec::lekcja lekcja)
{
    ofstream plik;
    plik.open("baza\\Plan zajec.txt", ios::app);
    if(!plik.good())
    {
        plik.close();
        throw BladPliku("blad pliku - Plan zajec.txt");
    }
    plik << kierunek << ";" << grupa << ";" << lekcja.tytul << ";" << lekcja.sala << ";" << lekcja.prowadzacy << ";"
    << lekcja.godzina_rozpoczecia << ";" << lekcja.minuta_rozpoczecia << ";" << lekcja.czas_trwania << ";" << lekcja.dzien << endl;
    plik.close();
}

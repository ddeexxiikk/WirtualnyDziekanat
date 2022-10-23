#include "PolaczenieZBazaSQL.h"
#include "Czlowiek.h"
#include <iostream>
#include <string>

using namespace std;

bool polaczenie_z_baza_SQL()
{
    bool proces;

    const string login_do_bazy_danych_SQL = "ddeexxiikk";
    const string haslo_do_bazy_danych_SQL = "A*pxqKxM3rTzke7v_.*@";

    //Proces Łączenia z Bazą SQL
    //Trzeba go zrobić

    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

string poprawny_login_z_bazy_SQL()
{
    string poprawny_login;
    //Proces Pobierania Loginu z Bazy SQL
    //Trzeba go zrobić

    bool proces = polaczenie_z_baza_SQL();

    if(proces) //Jeśli się udało
    {
        poprawny_login = "Login";
        return poprawny_login;
    }
    else //Jeśli się nie udało
    {
        poprawny_login = nullptr;
        return poprawny_login;
    }
};

string poprawne_haslo_z_bazy_SQL()
{
    string poprawne_haslo;
    //Proces Pobierania Hasła z Bazy SQL
    //Trzeba go zrobić

    bool proces = polaczenie_z_baza_SQL();

    if(proces) //Jeśli się udało
    {
        poprawne_haslo = "Login";
        return poprawne_haslo;
    }
    else //Jeśli się nie udało
    {
        poprawne_haslo = nullptr;
        return poprawne_haslo;
    }
};

bool zmiana_hasla_przez_studenta()
{
    string haslo_obecne;
    cout << "Podaj swoje obecne haslo: ";
    cin >> haslo_obecne;
    //Sprawdzic poprawnosc obecnego hasla dla studenta

    string haslo_nowe;
    cout << "Podaj nowe haslo: ";
    cin >> haslo_nowe;

    bool proces;
    //Proces Zmiany obecnego hasła na nowe hasło przez Studenta
    //Trzeba go zrobić

    if(proces) // Jeśli się udało
    {
        cout << "Haslo zostalo zmienione" << endl;
        return true;
    }
    else //Jeśli się nie udało
    {
        cout << "Haslo nie zostalo zmienione" << endl;
        return false;
    }
};

bool zmiana_hasla_przez_pracownika()
{
    string stare_haslo;
    cout << "Podaj swoje stare haslo: ";
    cin >> stare_haslo;
    //Sprawdzic poprawnosc obecnego hasla pracownika

    bool sprawdzenie_obecneg_hasla;

    //Jesli haslo jest poprawne
    if(sprawdzenie_obecneg_hasla)
    {
        string NoweHaslo;
        cout << "Podaj swoje nowe haslo: ";
        cin >> NoweHaslo;

        //Zmienic stare haslo na nowe haslo w Bazie SQL
    }
    else
    {
        cout << "Haslo nie zostalo zmienione" << endl;
        return false;
    }
};

string pokaz_numer_student(string * alogin_uzytkownika)
{
    string numer_studenta = nullptr;

    numer_studenta = *alogin_uzytkownika;

    //Jeśli długość numeru studenta jest większa od 5, tzn., że program załadował jakiś login
    if(numer_studenta.size()>5) //Jeśli się udało
        return numer_studenta;
    else //Jeśli się nie udało
        return numer_studenta;
};

string pokaz_numer_studenta_pracownik()
{
    string imie, nazwisko;
    cout << "Podaj imie studenta: ";
    cin >> imie;
    cout << "Podaj nazwisko studenta: ";
    cin >> nazwisko;

    string numer_studenta;
    bool proces;
    //Proces Pobierania Numeru Studenta z Bazy SQL
    //Trzeba go zrobić

    if(proces) //Jeśli się udało
    {
        //Zrobić wyciagniecie numeru studenta z Bazy SQL i zapisanie go do zmiennej NumerStudenta

        numer_studenta = "NumerStudenta";
        return numer_studenta;
    }
    else //Jeśli się nie udało
    {
        numer_studenta = nullptr;
        return numer_studenta;
    }
};

bool dodanie_studenta()
{
    string imie, nazwisko, haslo, numer_studenta;
    const int poziom_dostepu = 1;
    cout << "Podaj imie studenta: ";
    cin >> imie;
    cout << "Podaj nazwisko studenta: ";
    cin >> nazwisko;
    cout << "Podaj haslo studenta: ";
    cin >> haslo;
    cout << "Podaj numer studenta: ";
    cin >> numer_studenta;

    bool proces;
    //Proces Dodania Studenta do Bazy SQL
    //Trzeba go zrobić

    if(proces)// Jeśli się udało
    {
        cout << "Student zostal dodany." << endl;
        cout << "Poinformuj studenta o koniecznosci zmiana hasla." << endl;
        return true;
    }
    else //Jeśli się nie udało
    {
        cout << "Student nie zostal dodany." << endl;
        return false;
    }
};

bool usuniecie_studenta()
{
    char wybor;
    cout << "Czy na pewno chcesz usunac studenta? (T - tak, N - nie): ";
    cin >> wybor;

    if(wybor == 'N' || wybor == 'n')//Jeśli użytkownik zdecydował się wyjść z tej opcji
        return false;
    else
    {
        string numer_studenta;
        cout << "Podaj numer studenta, ktorego chcesz usunac: ";
        cin >> numer_studenta;

        bool proces;
        //Proces Usunięcia Studenta z Bazy SQL
        //Trzeba go zrobić

        if(proces) // Jeśli się udało
            return true;
        else //Jeśli się nie udało
            return false;
    }
};

void zobaczenie_ocen_student()
{
    //Proces Zobaczenia Ocen Studenta
    //Trzeba go zrobić
};

void zobaczenie_ocen_studenta_pracownik()
{
    //Proces Zobaczenia Ocen Studenta
    //Trzeba go zrobić
};

bool dodanie_oceny()
{
    bool proces;
    //Proces Dodania Oceny Studenta
    //Trzeba go zrobić

    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

void sprawdzenie_grupy_student()
{
    //Proces Sprawdzenia Grupy Studenta
    //Trzeba go zrobić
};

void sprawdzenie_grupy_studenta_pracownik()
{
    //Proces Sprawdzenia Grupy Studenta
    //Trzeba go zrobić
};

void sprawdzenie_ksiazek_student()
{
    //Proces Sprawdzenia Książek Studenta
    //Trzeba go zrobić
};

void sprawdzenie_ksiazek_studenta_pracownik()
{
    string numer_studenta;
    cout << "Podaj numer studenta, ktoremu chcesz sprawdzic ksiazki: ";
    cin >> numer_studenta;

    //Proces Sprawdzenia Książek Studenta w bazie SQL
    //Trzeba go zrobić
};

bool dodanie_ksiazki()
{
    string numer_studenta;
    cout << "Podaj numer studenta, ktoremu chcesz dodac ksiazke: ";
    cin >> numer_studenta;

    bool proces;
    //Proces Dodania Książki Studenta
    //Trzeba go zrobić


    if(proces) // Jeśli się udało
    {
        cout << "Dodano ksiazke do rejestru studenta." << endl;
        return true;
    }
    else //Jeśli się nie udało
    {
        cout << "Nie udalo sie dodac ksiazki do rejestru studenta." << endl;
        return false;
    }
};

bool usuniecie_ksiazki()
{
    string numer_studenta;
    cout << "Podaj numer studenta, ktoremu chcesz usunac ksiazke: ";
    cin >> numer_studenta;

    bool proces;
    //Proces Usunięcia Książki Studenta
    //Trzeba go zrobić


    if(proces) // Jeśli się udało
    {
        cout << "Usunieto ksiazke z rejestru studenta." << endl;
        return true;
    }
    else //Jeśli się nie udało
    {
        cout << "Nie udalo sie usunac ksiazki z rejestru studenta." << endl;
        return false;
    }
};

void sprawdzenie_planu_zajec_student()
{
    //Proces Sprawdzenia Planu Zajęć
    //Trzeba go zrobić
};

void sprawdzenie_planu_zajec_studenta_pracownik()
{
    string numer_studenta;
    cout << "Podaj numer studenta, dla którego chcesz sprawdzic plan zajec: ";
    cin >> numer_studenta;

    bool proces;
    //Proces Sprawdzenia Planu Zajęć wraz z komendą SQL
    //Trzeba go zrobić

    if(proces)
    {
        cout << "Plan zajec studenta o numerze: " << numer_studenta << " to: " << endl;
        //Pokazac Plan Zajec Studenta z bazy SQL
    }
    else
    {
        cout << "Nie udalo sie pobrac planu zajec studenta..." <<endl;
    }
};

void przegladniecie_ogloszen()
{
    //Proces Przeglądnięcia Ogłoszeń
    //Trzeba go zrobić
};

bool dodanie_ogloszen()
{
    //bool Proces - warunek sprawdzający czy funkcja połączyła się dobrze z bazą i dodała ogłoszenie
    bool proces;

    //Dodanie tytułu ogłoszenia
    string tytul, tresc;
    cout << "Podaj tytul ogłoszenia: ";
    cin >> tytul;

    //Dodanie treści ogłoszenia
    cout << "Podaj tresc ogłoszenia: ";
    cin >> tresc;

    //Proces Dodania Ogłoszenia razem z komendą SQL
    //Trzeba go zrobić

    if(proces) // Jeśli się udało
    {
        return  true;
    }
    else//Jeśli się nie udało
    {
        cout << "Nie udalo sie dodac ogloszenia" << endl;
        return false;
    }
};

bool usuniecie_ogloszen()
{
    //Dodanie tytułu ogłoszenia
    string numer_ogloszenia;
    cout << "Podaj numer ogloszenia, ktore chcesz usunac: ";
    cin >> numer_ogloszenia;

    //bool Proces - warunek sprawdzający czy funkcja połączyła się dobrze z bazą i usunęła ogłoszenie
    bool proces;

    //Proces Usunięcia Ogłoszenia razem z komendą SQL
    //Trzeba go zrobić

    if(proces) // Jeśli się udało
    {
        cout << "Usunieto ogloszenie o numerze: " << numer_ogloszenia << endl;
        return  true;
    }
    else//Jeśli się nie udało
    {
        cout << "Nie udalo sie usunac ogloszenia" << endl;
        return false;
    }
};
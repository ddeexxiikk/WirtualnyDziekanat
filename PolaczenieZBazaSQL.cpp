#include "PolaczenieZBazaSQL.h"
#include "Czlowiek.h"
#include <iostream>
#include <string>

using namespace std;

bool PolaczenieZBazaSQL()
{
    //Proces Łączenia z Bazą SQL
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

string LoginZBazySQL()
{
    string PoprawnyLogin;
    //Proces Pobierania Loginu z Bazy SQL
    //Trzeba go zrobić

    bool Proces = PolaczenieZBazaSQL();

    if(Proces) //Jeśli się udało
    {
        //Zrobić wyciagniecie loginu z Bazy SQL i zapisanie go do zmiennej PoprawnyLogin

        PoprawnyLogin = "Login";
        return PoprawnyLogin;
    }
    else //Jeśli się nie udało
    {
        PoprawnyLogin = nullptr;
        return PoprawnyLogin;
    }
};

string HasloZBazySQL()
{
    string PoprawneHaslo;
    //Proces Pobierania Hasła z Bazy SQL
    //Trzeba go zrobić

    bool Proces = PolaczenieZBazaSQL();

    if(Proces) //Jeśli się udało
    {
        //Zrobić wyciagniecie hasla z Bazy SQL i zapisanie go do zmiennej PoprawneHaslo

        PoprawneHaslo = "Login";
        return PoprawneHaslo;
    }
    else //Jeśli się nie udało
    {
        PoprawneHaslo = nullptr;
        return PoprawneHaslo;
    }
};

bool ZmianaHaslaPrzezStudenta()
{
    string HasloObecne;
    cout << "Podaj swoje obecne haslo: ";
    cin >> HasloObecne;
    //Sprawdzic poprawnosc obecnego hasla dla studenta

    string HasloNowe;
    cout << "Podaj nowe haslo: ";
    cin >> HasloNowe;

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

bool ZmianaHaslaPrzezPracownika()
{
    char wybor;
    cout << "Chcesz zmienic swoje haslo czy haslo studenta? (S - swoje, T - studenta): ";
    cin >> wybor;

    if(wybor == 'S' || wybor == 's')//Proces zmiany hasla pracownika
    {
        string StareHaslo;
        cout << "Podaj swoje stare haslo: ";
        cin >> StareHaslo;
        //Sprawdzic poprawnosc obecnego hasla pracownika

        bool SprawdzenieObecnegoHasla;

        //Jesli haslo jest poprawne
        if(SprawdzenieObecnegoHasla)
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
    }
    else if(wybor == 'T' || wybor == 't')//Proces zmiany hasla dla studenta
    {
        string NrStudenta;
        cout << "Pamietaj! Haslo studenta, moze zostac jedynie na jego wniosek!" << endl;
        cout << "Podaj numer studenta, dla ktorego chcesz zmienic haslo: ";
        cin >> NrStudenta;
        //Sprawdzic poprawnosc numeru studenta

        string noweHaslo;
        cout << "Podaj nowe haslo dla studenta: ";
        cin >> noweHaslo;

        bool SprawdzenieDodaniaHaslaStudenta;

        if(SprawdzenieDodaniaHaslaStudenta)
        {
            cout << "Haslo zostalo zmienione" << endl;
            return true;
        }
        else
        {
            cout << "Haslo nie zostalo zmienione" << endl;
            return false;
        }
    }
    else
    {
        cout << "Niepoprawny wybor!" << endl;
        return false;
    }
};

string PokazNumerStudenta()
{
    string NumerStudenta;
    //Proces Pobierania Numeru Studenta z Bazy SQL
    //Trzeba go zrobić

    bool Proces = PolaczenieZBazaSQL();

    if(Proces) //Jeśli się udało
    {
        //Zrobić wyciagniecie numeru studenta z Bazy SQL i zapisanie go do zmiennej NumerStudenta

        NumerStudenta = "NumerStudenta";
        return NumerStudenta;
    }
    else //Jeśli się nie udało
    {
        NumerStudenta = nullptr;
        return NumerStudenta;
    }
};

string PokazNumerStudentaPracownik()
{
    string Imie, Nazwisko;
    cout << "Podaj imie studenta: ";
    cin >> Imie;
    cout << "Podaj nazwisko studenta: ";
    cin >> Nazwisko;

    string NumerStudenta;
    bool Proces;
    //Proces Pobierania Numeru Studenta z Bazy SQL
    //Trzeba go zrobić

    if(Proces) //Jeśli się udało
    {
        //Zrobić wyciagniecie numeru studenta z Bazy SQL i zapisanie go do zmiennej NumerStudenta

        NumerStudenta = "NumerStudenta";
        return NumerStudenta;
    }
    else //Jeśli się nie udało
    {
        NumerStudenta = nullptr;
        return NumerStudenta;
    }
};

bool DodanieStudenta()
{
    string Imie, Nazwisko, Haslo, NrStudenta;
    const int poziom_dostepu = 1;
    cout << "Podaj imie studenta: ";
    cin >> Imie;
    cout << "Podaj nazwisko studenta: ";
    cin >> Nazwisko;
    cout << "Podaj haslo studenta: ";
    cin >> Haslo;
    cout << "Podaj numer studenta: ";
    cin >> NrStudenta;

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

bool UsuniecieStudenta()
{
    char wybor;
    cout << "Czy na pewno chcesz usunac studenta? (T - tak, N - nie): ";
    cin >> wybor;

    if(wybor == 'N' || wybor == 'n')//Jesli uzytkownik zdecydowal sie wyjsc z tej opcji
        return false;
    else
    {
        string NrStudenta;
        cout << "Podaj numer studenta, ktorego chcesz usunac: ";
        cin >> NrStudenta;

        bool proces;
        //Proces Usunięcia Studenta z Bazy SQL
        //Trzeba go zrobić

        if(proces) // Jeśli się udało
            return true;
        else //Jeśli się nie udało
            return false;
    }
};

bool DodaniePracownika()
{
    //Proces Dodania Pracownika do Bazy SQL
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

void ZobaczenieOcenStudent()
{
    //Proces Zobaczenia Ocen Studenta
    //Trzeba go zrobić
};

void ZobaczenieOcenPracownik()
{
    //Proces Zobaczenia Ocen Studenta
    //Trzeba go zrobić
};

bool DodanieOceny()
{
    //Proces Dodania Oceny Studenta
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

void SprawdzenieGrupyStudent()
{
    //Proces Sprawdzenia Grupy Studenta
    //Trzeba go zrobić
};

void SprawdzenieGrupyPracownik()
{
    //Proces Sprawdzenia Grupy Studenta
    //Trzeba go zrobić
};

void SprawdzenieKsiazekStudent()
{
    //Proces Sprawdzenia Książek Studenta
    //Trzeba go zrobić
};

void SprawdzenieKsiazekPracownik()
{
    string NrStudenta;
    cout << "Podaj numer studenta, ktoremu chcesz sprawdzic ksiazki: ";
    cin >> NrStudenta;

    //Proces Sprawdzenia Książek Studenta w bazie SQL
    //Trzeba go zrobić
};

bool DodanieKsiazki()
{
    string NrStudenta;
    cout << "Podaj numer studenta, ktoremu chcesz dodac ksiazke: ";
    cin >> NrStudenta;

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

bool UsuniecieKsiazki()
{
    string NrStudenta;
    cout << "Podaj numer studenta, ktoremu chcesz usunac ksiazke: ";
    cin >> NrStudenta;

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

void SprawdzeniePlanuZajec()
{
    //Proces Sprawdzenia Planu Zajęć
    //Trzeba go zrobić
};

void SprawdzeniePlanuZajecPracownik()
{
    string NrStudenta;
    cout << "Podaj numer studenta, dla którego chcesz sprawdzic plan zajec: ";
    cin >> NrStudenta;

    bool proces;
    //Proces Sprawdzenia Planu Zajęć wraz z komendą SQL
    //Trzeba go zrobić

    if(proces)
    {
        cout << "Plan zajec studenta o numerze: " << NrStudenta << " to: " << endl;
        //Pokazac Plan Zajec Studenta z bazy SQL
    }
    else
    {
        cout << "Nie udalo sie pobrac planu zajec studenta..." <<endl;
    }
};

void PrzegladniecieOgloszen()
{
    //Proces Przeglądnięcia Ogłoszeń
    //Trzeba go zrobić
};

bool DodanieOgloszen()
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

bool UsuniecieOgloszen()
{


    //Dodanie tytułu ogłoszenia
    string NrOgloszenia;
    cout << "Podaj numer ogloszenia, ktore chcesz usunac: ";
    cin >> NrOgloszenia;

    //bool Proces - warunek sprawdzający czy funkcja połączyła się dobrze z bazą i usunęła ogłoszenie
    bool proces;

    //Proces Usunięcia Ogłoszenia razem z komendą SQL
    //Trzeba go zrobić

    if(proces) // Jeśli się udało
    {
        cout << "Usunieto ogloszenie o numerze: " << NrOgloszenia << endl;
        return  true;
    }
    else//Jeśli się nie udało
    {
        cout << "Nie udalo sie usunac ogloszenia" << endl;
        return false;
    }
};

#include "PolaczenieZBazaSQL.h"
#include "Czlowiek.h"
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
    //Proces Zmiany Hasła przez Studenta
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

bool ZmianaHaslaPrzezPracownika()
{
    //Proces Zmiany Hasła Studenta lub własnego przez Pracownika
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

bool ZmianaHaslaPrzezAdmina()
{
    //Proces Zmiany Hasła Studenta, Pracownika lub własnego przez Admina
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
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

string PokazNumerStudentaPracownik(string aImie, string aNazwisko)
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

bool DodanieStudenta()
{
    //Proces Dodania Studenta do Bazy SQL
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

bool UsuniecieStudenta(string NrStudenta)
{
    //Proces Usunięcia Studenta z Bazy SQL
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
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

void ZobaczenieOcenPracownik(string NrStudenta)
{
    //Proces Zobaczenia Ocen Studenta
    //Trzeba go zrobić
};

bool DodanieOceny(string NrStudenta)
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

void SprawdzenieGrupyPracownik(string NrStudenta)
{
    //Proces Sprawdzenia Grupy Studenta
    //Trzeba go zrobić
};

void SprawdzenieKsiazekStudent()
{
    //Proces Sprawdzenia Książek Studenta
    //Trzeba go zrobić
};

void SprawdzenieKsiazekPracownik(string NrStudenta)
{
    //Proces Sprawdzenia Książek Studenta
    //Trzeba go zrobić
};

void SprawdzeniePlanuZajec()
{
    //Proces Sprawdzenia Planu Zajęć
    //Trzeba go zrobić
};

void SprawdzeniePlanuZajecPracownik(string NrStudenta)
{
    //Proces Sprawdzenia Planu Zajęć
    //Trzeba go zrobić
};

void PrzegladniecieOgloszenStudent()
{
    //Proces Przeglądnięcia Ogłoszeń
    //Trzeba go zrobić
};

void PrzegladniecieOgloszenPracownik()
{
    //Proces Przeglądnięcia Ogłoszeń
    //Trzeba go zrobić
};

bool DodanieOgloszen()
{
    //Proces Dodania Ogłoszenia
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

bool UsuniecieOgloszen(string NrOgloszenia)
{
    //Proces Usunięcia Ogłoszenia
    //Trzeba go zrobić

    bool proces;
    if(proces) // Jeśli się udało
        return true;
    else //Jeśli się nie udało
        return false;
};

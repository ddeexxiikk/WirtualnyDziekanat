#include "Panel.h"
#include "PolaczenieZBazaSQL.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "Student.h"
#include "Pracownik.h"

using namespace std;

/*  Funkcja wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość jaką ona zwróci
    w zależności od tego tworzy obiekt Student lub Pracownik w obiekcie przekazanym w argumencie
    oraz zwraca int będący poziomem dostępu użytkownika
*/
int PanelLogowania(void *&obiekt)
{
    static int counter=0;
    if(counter==3) exit(1);
    string login, password;
    cout<<"Podaj login: ";
    cin>>login;
    cout<<"Podaj haslo: ";
    cin>>password;
    int result=CzyPoprawnyUzytkownik(login, password);
    if(result!=0)
    {
        if(result==1) obiekt = new Student("Student data.txt", login);
        if(result==2) obiekt = new Pracownik("Worker data.txt", login);
        return result;
    }
    counter++;
    system("cls");
    Sleep(500);
    cout<<"Niepoprawne haslo lub login, sprobuj ponownie"<<endl;
    PanelLogowania(obiekt);
}

/*  Funkcja łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, znajduje poprawne dane logowania w pliku tekstowym i porówuje z podnymi.
    Zwraca poziom dostępu użytkownika lub 0 jeżeli dane są niepoprawne
*/
int CzyPoprawnyUzytkownik(string alogin, string ahaslo)
{
    ifstream logowanie;
    logowanie.open("Users.txt");
    string temp_login, temp_password;
    int access_lvl;
    while(logowanie>>temp_login>>temp_password>>access_lvl)
    {
        if(temp_login==alogin&&temp_password==ahaslo)
        {
            logowanie.close();
            return access_lvl;
        }
    }
    logowanie.close();
    return 0;
}

int wybor_opcji(int min_przedzialu, int max_przedzialu)
{
    string wybor;
    int iwybor;
    cin>>wybor;
    if(wybor=="q") return -20;
    iwybor=stoi(wybor);
    while(iwybor<min_przedzialu||iwybor>max_przedzialu)
    {
        cout<<"Niepoprawne dane, podaj ponownie: ";
        cin>>iwybor;
    }
    return iwybor;
}

/*
    Ta funkcja dostaje poziom dostêpu u¿ytkownika i wyœwietla dostêpne opcje.
    Zwraca numer wybranej opcji (dla studenta) albo numer wybranej opcji +10 dla pracownika
*/

int wyswietlanie_menu(int poziom_dostepu)
{
    int opcja;
    cout<<"Menu: "<<endl<<"Wpisz q aby wyjsc z programu"<<endl;
    switch(poziom_dostepu)
    {
        case 1:
        {
            cout<<"1. Zmien haslo"<<endl;
            cout<<"2. Sprawdz oceny"<<endl;
            cout<<"3. Sprawdz plan zajec"<<endl;
            cout<<"4. Sprawdz swoja grupe"<<endl;
            cout<<"5. Sprawdz ksiazki"<<endl;
            opcja=wybor_opcji(1, 5);
            break;
        }
        case 2:
        {
            cout<<"1. Zmien haslo"<<endl;
            cout<<"2. Dodaj ocene"<<endl;
            cout<<"3. Sprawdz oceny studenta"<<endl;
            cout<<"4. Sprawdz plan zajec studenta"<<endl;
            cout<<"5. Dodaj ksiazke studenta"<<endl;
            cout<<"6. Usun ksiazke studenta"<<endl;
            cout<<"7. Dodaj plan zajec studenta"<<endl;
            cout<<"8. Sprawdz grupe studenta"<<endl;
            cout<<"9. Dodaj studenta"<<endl;
            cout<<"10. Usun studenta"<<endl;
            opcja=wybor_opcji(1, 10)+10;
            break;
        }
    }
    return opcja;
}

bool obsluz_opcje(int opcja, void *&obiekt)
{
    switch(opcja)
    {
        case 1:
        {
            string new_password;
            cout<<"Podaj nowe haslo: ";
            cin>>new_password;
            ((Student*)obiekt)->zmien_haslo("Users.txt", new_password);
            break;
        }
        case 2:
        {
            cout<<"Wybrano opcje 2"<<endl;
            break;
        }
        case 3:
        {
            ((Student*)obiekt)->wyswietl_plan();
            break;
        }
        case 4:
        {
            cout<<"Grupa: "<<((Student*)obiekt)->sprawdzenie_grupy()<<endl;
            break;
        }
        case 5:
        {
            cout<<"Wybrano opcje 5"<<endl;
            break;
        }
        case 11:
        {
            string new_password;
            cout<<"Podaj nowe haslo: ";
            cin>>new_password;
            ((Pracownik*)obiekt)->zmien_haslo("Users.txt", new_password);
            break;
        }
        case 12:
        {
            //cout<<"Wybrano opcje 12"<<endl;
            string login, przedmiot;
            int semestr;
            double ocena;
            cout << "Podaj login studenta:";
            cin >> login;
            cout << "Podaj przdedmiot:";
            cin >> przedmiot;
            cout << "Podaj semestr:";
            cin >> semestr;
            cout << "Podaj ocene:";
            cin >> ocena;
            ((Pracownik*)obiekt)->dodaj_ocene(login, przedmiot, semestr, ocena);
            break;
        }
        case 13:
        {
            //cout<<"Wybrano opcje 13"<<endl;
            string login, przedmiot;
            int semestr;
            cout<<"Podaj login studenta: ";
            cin>>login;
            cout<<"Podaj przedmiot: ";
            cin>>przedmiot;
            cout<<"Podaj semestr: ";
            cin>>semestr;
            int result=((Pracownik*)obiekt)->sprawdz_ocene("grades.txt", login, przedmiot, semestr);
            if(result==-1) cout<<"Błąd otwierania pliku"<<endl;
            if(result==0) cout<<"Brak oceny"<<endl;
            else cout<<result<<endl;
            break;
        }
        case 14:
        {
            //cout<<"Wybrano opcje 14"<<endl;
            string kierunek, grupa;
            cout << "Podaj kierunek: ";
            cin >> kierunek;
            cout << "Podaj grupe: ";
            cin >> grupa;
            ((Pracownik*)obiekt)->sprawdz_plan_zajec_studenta(kierunek, grupa);
            break;
        }
        case 15:
        {
            //cout<<"Wybrano opcje 15"<<endl;
            string login, tytul;
            cout << "Podaj login studenta: ";
            cin >> login;
            cout << "Podaj tytul ksiazki do wypozyczenia: ";
            getline(cin >> ws, tytul);

            int rezultat = ((Pracownik*)obiekt)->dodaj_ksiazke_studentowi(login, tytul);
            if(rezultat == -1) cout << "Blad w otwieraniu pliku" << endl;
            if(rezultat == 1) cout << "Brak ksiazki na stanie biblioteki" << endl;
            break;
        }
        case 16:
        {
            //cout<<"Wybrano opcje 16"<<endl;
            string login, tytul;
            cout << "Podaj login studenta: ";
            cin >> login;
            cout << "Podaj tytul ksiazki do usuniecia: ";
            getline(cin >> ws, tytul);

            ((Pracownik*)obiekt)->usun_ksiazke_studentowi(login, tytul);
            break;
        }
        case 17:
        {
            cout<<"Wybrano opcje 17"<<endl;
            break;
        }
        case 18:
        {
            string login;
            cout<<"Podaj login studenta: ";
            cin>>login;
            cout<<"Grupa studenta "<<login<<": "<<((Pracownik*)obiekt)->sprawdzenie_grupy_student("Student data.txt", login)<<endl;
            break;
        }
        case 19:
        {
            //cout<<"Wybrano opcje 19"<<endl;
            string login, haslo, grupa, imie, nazwisko, wydzial, semestr;
            cout<<"Podaj login nowego studenta: ";
            cin>>login;
            cout<<"Podaj haslo nowego studenta: ";
            cin>>haslo;
            cout<<"Podaj imie nowego studenta: ";
            cin>>imie;
            cout<<"Podaj nazwisko nowego studenta: ";
            cin>>nazwisko;
            cout<<"Podaj wydzial nowego studenta: ";
            cin>>wydzial;
            cout<<"Podaj grupe nowego studenta: ";
            cin>>grupa;
            cout<<"Podaj semestr na ktorym ma byc nowy student: ";
            cin>>semestr;
            ((Pracownik*)obiekt)->dodaj_studenta(login, haslo, grupa, wydzial, imie, nazwisko, semestr);
            break;
        }
        case 20:
        {
            //cout<<"Wybrano opcje 20"<<endl;
            string login, imie, nazwisko;
            cout << "Podaj login studenta, ktorego chcesz usunac: ";
            cin >> login;
            cout << "Podaj imie studenta, ktorego chcesz usunac: ";
            cin >> imie;
            cout << "Podaj nazwisko studenta, ktorego chcesz usunac: ";
            cin >> nazwisko;
            ((Pracownik*)obiekt)->usun_studenta(login, imie, nazwisko);
            break;
        }
        default:
        {
            exit(0);
        }
    }
    system("pause");
    system("cls");
    return true;
}

#include "Panel.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include "Student.h"
#include "Pracownik.h"
#include "Log.h"
#include "Wyjatki.h"

using namespace std;

/*  Funkcja wyświetla panel logowania, pobiera od użytkownika login i hasło, a następnie
    wywołuje funkcję CzyPoprawnyUzytkownik() i sprawdza, wartość jaką ona zwróci
    w zależności od tego tworzy obiekt Student lub Pracownik w obiekcie przekazanym w argumencie
    oraz zwraca int będący poziomem dostępu użytkownika
*/

void pauza()
{
    cout << "nacisnij dowolny klawisz aby kontynuowac...";
    cin.ignore();
    cin.clear();
    cin.get();
}

int PanelLogowania(void *&obiekt, Log& log)
{
    static int counter=0;
    if(counter==3) exit(1);
    string login, password;
    cout<<"Podaj login: ";
    cin>>login;
    cout<<"Podaj haslo: ";
    cin>>password;
    int result = 0;
    try
    {
        result=CzyPoprawnyUzytkownik(login, password);
    }
    catch(const BladPliku& e)
    {
        cerr << e.what() << endl;
    }
    if(result!=0)
    {
        if(result==1) 
        {
            obiekt = new Student("Student data.txt", login);
            log.zapisz_akcje("zalogowanie studenta:" + login);
        }
        if(result==2) 
        {
            obiekt = new Pracownik("Worker data.txt", login);
            log.zapisz_akcje("zalogowanie pracownika:" + login);
        }
        return result;
    }
    counter++;
    pauza();
    Sleep(500);
    cout<<"Niepoprawne haslo lub login, sprobuj ponownie"<<endl;
    log.zapisz_akcje("wprowadzono niepoprawne haslo lub login");
    PanelLogowania(obiekt, log);
}

/*  Funkcja łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, znajduje poprawne dane logowania w pliku tekstowym i porówuje z podnymi.
    Zwraca poziom dostępu użytkownika lub 0 jeżeli dane są niepoprawne
*/
int CzyPoprawnyUzytkownik(string alogin, string ahaslo)
{
    ifstream logowanie;
    logowanie.open("Users.txt");
    if(!logowanie.good())
    {
        throw BladPliku("blad pliku - Users.txt");
    }
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

bool obsluz_opcje(int opcja, void *&obiekt, Log& log)
{
    try
    {
        switch(opcja)
        {
            case 1:
            {
                string new_password;
                cout<<"Podaj nowe haslo: ";
                cin>>new_password;
                ((Student*)obiekt)->zmien_haslo("Users.txt", new_password);
                log.zapisz_akcje("zmieniono haslo");
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
                log.zapisz_akcje("wyswietlono plan");
                break;
            }
            case 4:
            {
                cout<<"Grupa: "<<((Student*)obiekt)->sprawdzenie_grupy()<<endl;
                log.zapisz_akcje("sprawdzono grupe");
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
                log.zapisz_akcje("zmieniono haslo");
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
                log.zapisz_akcje("dodano ocene studentowi:" + login + " " + przedmiot + " " + to_string(semestr) + " " + to_string(ocena));
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
                if(result==0) 
                {
                    cout<<"Brak oceny"<<endl;
                    log.zapisz_akcje("sprawdzono ocene:brak oceny");
                }
                else
                {
                    cout << result << endl;
                    log.zapisz_akcje("sprawdzono ocene:" + login + " " + przedmiot + " " + to_string(semestr) + " " + to_string(result));
                }
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
                if(!((Pracownik*)obiekt)->sprawdz_plan_zajec_studenta(kierunek, grupa)) return false;
                log.zapisz_akcje("sprawdzono plan zajec:" + kierunek + " " + grupa);
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
                if(rezultat == 1) 
                {
                    cout << "Brak ksiazki na stanie biblioteki" << endl;
                    log.zapisz_akcje("wypozyczono ksiazke:brak ksiazki na stanie biblioteki");
                }
                else
                {
                    cout << "Wypozyczono ksiazke" << endl;
                    log.zapisz_akcje("wypozyczono ksiazke:" + login + " " + tytul);
                }
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
                log.zapisz_akcje("usunieto ksiazke studentowi ksiazke:blad");
                log.zapisz_akcje("usunieto ksiazke studentowi ksiazke:" + login + " " + tytul);
                break;
            }
            case 17:
            {
                //cout<<"Wybrano opcje 17"<<endl;
                string kierunek, grupa, tytul, sala, prowadzacy;
                int dzien, godzina, min, czas;

                cout << "Podaj nazwe kierunku: ";
                cin >> kierunek;
                cout << "Podaj nazwe grupy: ";
                cin >> grupa;
                cout << "Podaj nazwe przedmiotu: ";
                cin >> tytul;
                cout << "Podaj nazwe sali: ";
                cin >> sala;
                cout << "Podaj prowadzacego: ";
                cin >> prowadzacy;
                cout << "Podaj dzien: ";
                cin >> dzien;
                cout << "Podaj godzine rozpoczecia: ";
                cin >> godzina;
                cout << "Podaj minute rozpoczecia: ";
                cin >> min;
                cout << "Podaj czas trwania: ";
                cin >> czas;

                Plan_zajec::lekcja l(tytul, sala, prowadzacy, dzien, godzina, min, czas);
                ((Pracownik*)obiekt)->dodaj_plan_zajec(kierunek, grupa, l);
                log.zapisz_akcje("dodano plan zajec:" + kierunek + " " + grupa + " " + l.display());
                break;
            }
            case 18:
            {
                string login;
                cout<<"Podaj login studenta: ";
                cin>>login;
                cout<<"Grupa studenta "<<login<<": "<<((Pracownik*)obiekt)->sprawdzenie_grupy_student("Student data.txt", login)<<endl;
                log.zapisz_akcje("sprawdzono grupe studencka studenta:" + login);
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
                log.zapisz_akcje("dodano studenta:" + login + " " + grupa + " " + wydzial + " " + imie + " " + nazwisko + " " + semestr);
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
                log.zapisz_akcje("usunieto studenta:" + login + " " + imie + " " + nazwisko);
                break;
            }
            default:
            {
                return false;
            }
        }
    }
    catch(const BladPliku& e)
    {
        try
        {
            log.zapisz_akcje(e.what());
        }
        catch(const BladPliku& e)
        {
            std::cerr << e.what() << '\n';
            std::cerr << "Fatalny blad - blad pliku z logami";
        }
        std::cerr << e.what() << '\n';
    }
    
    pauza();
    system("cls");
    return true;
}

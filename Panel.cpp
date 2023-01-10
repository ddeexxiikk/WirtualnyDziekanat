#include "Panel.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <algorithm>
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
    cout << "\nnacisnij dowolny klawisz aby kontynuowac...";
    cin.ignore();
    cin.clear();
    cin.get();
}

int PanelLogowania(void *&obiekt, Log& log)
{
    int counter=0;
    string login, password;
    do
    {
        login.clear(); password.clear();
        cout<<"Podaj login: ";
        cin>>login;
        cout<<"Podaj haslo: ";
        cin>>password;
        int result = 0;

        try
        {
            result=CzyPoprawnyUzytkownik(login, password);

            if(result!=0)
            {
                if(result==1) 
                {
                    obiekt = new Student("baza\\Student dane.txt", login);
                    log.zapisz_akcje("zalogowanie studenta:" + login);
                }
                if(result==2) 
                {
                    obiekt = new Pracownik("baza\\Pracownik dane.txt", login);
                    log.zapisz_akcje("zalogowanie pracownika:" + login);
                }
                return result;
            }
            cout<<"Niepoprawne haslo lub login"<<endl;
            log.zapisz_akcje("wprowadzono niepoprawne haslo lub login");
            counter++;
        }
        catch(const BladPliku& e)
        {
            cerr << e.what() << endl;
            return 0;
        }

    }while(counter < 3);

    try
    {
        cout << "Przekroczno limit prob zalogowania sie" << endl;
        log.zapisz_akcje("przekroczno limit prob zalogowania sie");
    }
    catch(const BladPliku& e)
    {
        cerr << e.what() << endl;
        return 0;
    }

    return 0;
}

/*  Funkcja łączy się z bazą danych i sprawdza login i hasło wprowadzone przez użytkownika,
    porównuje, znajduje poprawne dane logowania w pliku tekstowym i porówuje z podnymi.
    Zwraca poziom dostępu użytkownika lub 0 jeżeli dane są niepoprawne
*/
int CzyPoprawnyUzytkownik(string alogin, string ahaslo)
{
    ifstream logowanie;
    logowanie.open("baza\\Uzytkownicy.txt");
    if(!logowanie.good())
    {
        throw BladPliku("blad pliku - Uzytkownicy.txt");
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

int wyswietlanie_menu(int poziom_dostepu, void*& obiekt)
{
    int opcja;
    switch(poziom_dostepu)
    {
        case 1:
        {
            Student* stud = (Student*)obiekt;
            Czlowiek* uzyt = stud;
            cout << endl;
            uzyt->wyswietl_informacje();
            cout << "Wpisz q aby wyjsc z programu" << endl;
            cout<<"1. Zmien haslo"<<endl;
            cout<<"2. Sprawdz oceny"<<endl;
            cout<<"3. Sprawdz plan zajec"<<endl;
            cout<<"4. Sprawdz swoja grupe"<<endl;
            cout<<"5. Sprawdz ksiazki"<<endl;
            cout << "Podaj wybor: ";
            opcja=wybor_opcji(1, 5);
            break;
        }
        case 2:
        {
            Pracownik* prac = (Pracownik*)obiekt;
            Czlowiek* uzyt = prac;
            cout << endl;
            uzyt->wyswietl_informacje();
            cout << "Wpisz q aby wyjsc z programu" << endl;
            cout<<"1. Zmien haslo"<<endl;
            cout<<"2. Dodaj ocene"<<endl;
            cout<<"3. Sprawdz oceny studenta"<<endl;
            cout<<"4. Sprawdz plan zajec grupy"<<endl;
            cout<<"5. Dodaj ksiazke studenta"<<endl;
            cout<<"6. Usun ksiazke studenta"<<endl;
            cout<<"7. Dodaj plan zajec grupy"<<endl;
            cout<<"8. Sprawdz grupe studenta"<<endl;
            cout<<"9. Dodaj studenta"<<endl;
            cout<<"10. Usun studenta"<<endl;
            cout << "Podaj wybor: ";
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
                cout<<"\nPodaj nowe haslo: ";
                cin>>new_password;
                ((Student*)obiekt)->zmien_haslo("baza\\Uzytkownicy.txt", new_password);
                cout << "Zmieniono haslo" << endl;
                log.zapisz_akcje("zmieniono haslo");
                break;
            }
            case 2:
            {
                cout << "\nW jaki sposob chcesz zobaczyc oceny?\n";
                cout << "1. z calego semestru\n";
                cout << "2. z calego dotychczasowego toku studiow\n";
                cout << "Podaj opcje: ";
                int opcja;
                cin >> opcja;

                if(opcja == 1)
                {
                    cout<<"\nPodaj semestr: ";
                    int semestr;
                    cin >> semestr;
                    vector<Ocena> oceny = ((Student*)obiekt)->sprawdz_oceny(semestr);
                    if(!oceny.size())
                    {
                        cout << " Brak ocen w danym semestrze" << endl;
                        log.zapisz_akcje("sprawdzono ksiazki:brak ocen w danym semestrze");
                    }
                    else
                    {   
                        cout << "\nLista ocen:\n";
                        for(const auto& e : oceny)
                        {
                            cout << e.przedmiot << ": " << e.ocena << endl;
                        }
                        log.zapisz_akcje(string("sprawdzono oceny w semestrze" + to_string(semestr)).c_str());
                    }
                }
                else if(opcja == 2)
                {
                    auto rezultat = ((Student*)obiekt)->sprawdz_oceny_w_calym_toku_studiow();
                    if(!rezultat.size())
                    {
                        cout << "\nBrak ocen" << endl;
                        log.zapisz_akcje("sprawdzono oceny z calego toku studiow: brak ocen");
                    }
                    else
                    {
                        cout << endl;
                        for(const auto& e : rezultat)
                        {
                            cout << "semestr " << e.first << ": " << e.second.przedmiot << " " << e.second.ocena << endl;
                        }
                        log.zapisz_akcje(string("sprawdzono oceny z calego toku studiow").c_str());
                    }
                }
                else
                {
                    cout << "\nZla opcja" << endl;
                }
                break;
            }
            case 3:
            {
                cout << endl;
                ((Student*)obiekt)->wyswietl_plan();
                log.zapisz_akcje("wyswietlono plan");
                break;
            }
            case 4:
            {
                cout<<"\nGrupa: "<<((Student*)obiekt)->sprawdzenie_grupy()<<endl;
                log.zapisz_akcje("sprawdzono grupe");
                break;
            }
            case 5:
            {
                cout << endl;
                vector<string> lista_ksiazek = ((Student*)obiekt)->sprawdz_liste_ksiazek();
                if(!lista_ksiazek.size())
                {
                    cout << " Brak ksiazek" << endl;
                    log.zapisz_akcje("sprawdzono ksiazki:brak ksiazek");
                }
                else
                {   
                    cout << "Lista ksiazek:\n";
                    std::string pom;
                    for(const auto& e : lista_ksiazek)
                    {
                        cout << e << endl;
                        pom += e + ", ";
                    }
                    pom.pop_back();
                    pom.pop_back();
                    log.zapisz_akcje("sprawdzono ksiazki:" + pom);

                }
                break;
            }
            case 11:
            {
                string new_password;
                cout<<"\nPodaj nowe haslo: ";
                cin>>new_password;
                ((Pracownik*)obiekt)->zmien_haslo("baza\\Uzytkownicy.txt", new_password);
                log.zapisz_akcje("zmieniono haslo");
                break;
            }
            case 12:
            {
                //cout<<"Wybrano opcje 12"<<endl;
                string login, przedmiot;
                int semestr;
                double ocena;
                cout << "\nPodaj login studenta:";
                getline(cin >> ws, login);
                cout << "Podaj przdedmiot:";
                getline(cin >> ws, przedmiot);
                cout << "Podaj semestr:";
                cin >> semestr;
                cout << "Podaj ocene:";
                cin >> ocena;
                ((Pracownik*)obiekt)->dodaj_ocene(login, przedmiot, semestr, ocena);
                cout << "Dodano ocene" << endl;
                log.zapisz_akcje("dodano ocene studentowi:" + login + " " + przedmiot + " " + to_string(semestr) + " " + to_string(ocena));
                break;
            }
            case 13:
            {
                cout << "\nW jaki sposob chcesz zobaczyc oceny?\n";
                cout << "1. danego przedmiotu w danym semestrze\n";
                cout << "2. z calego semestru\n";
                cout << "3. z calego dotychczasowego toku studiow\n";
                cout << "Podaj opcje: ";
                int opcja;
                cin >> opcja;

                if(opcja == 1)
                {
                    string login, przedmiot;
                    int semestr;
                    cout<<"\nPodaj login studenta: ";
                    getline(cin >> ws, login);
                    cout<<"Podaj przedmiot: ";
                    getline(cin >> ws, przedmiot);
                    cout<<"Podaj semestr: ";
                    cin>>semestr;
                    int result=((Pracownik*)obiekt)->sprawdz_ocene("baza\\Oceny.txt", login, przedmiot, semestr);
                    if(result==0) 
                    {
                        cout<<"\nBrak oceny"<<endl;
                        log.zapisz_akcje("sprawdzono ocene:brak oceny");
                    }
                    else
                    {
                        cout << "\nocena: " << result << endl;
                        log.zapisz_akcje("sprawdzono ocene:" + login + " " + przedmiot + " " + to_string(semestr) + " " + to_string(result));
                    }
                }
                else if (opcja == 2)
                {
                    string login;
                    int semestr;
                    cout<<"\nPodaj login studenta: ";
                    getline(cin >> ws, login);
                    cout<<"Podaj semestr: ";
                    cin>>semestr;

                    vector<Ocena> rezultat = ((Pracownik*)obiekt)->sprawadz_oceny_z_calego_semestru("baza\\Oceny.txt", login, semestr);
                    if(!rezultat.size())
                    {
                        cout << "\nBrak ocen w danym semestrze" << endl;
                        log.zapisz_akcje("sprawdzono oceny z calego semestru: brak ocen");
                    }
                    else
                    {
                        cout << "\noceny:\n";
                        for(const auto& e : rezultat)
                        {
                            cout << e.przedmiot << " " << e.ocena << endl;
                        }
                        log.zapisz_akcje(string("sprawdzono oceny z calego semestru studenta: " + login).c_str());
                    }
                }
                else if(opcja == 3)
                {
                    string login;
                    cout << "\nPodaj login:";
                    getline(cin >> ws, login);

                    auto rezultat = ((Pracownik*)obiekt)->sprawdz_oceny_z_calego_toku_studiow("baza\\Oceny.txt", login);
                    if(!rezultat.size())
                    {
                        cout << "\nBrak ocen" << endl;
                        log.zapisz_akcje("sprawdzono oceny z calego toku studiow: brak ocen");
                    }
                    else
                    {
                        cout << endl;
                        for(const auto& e : rezultat)
                        {
                            cout << "semestr " << e.first << ": " << e.second.przedmiot << " " << e.second.ocena << endl;
                        }
                        log.zapisz_akcje(string("sprawdzono oceny z calego toku studiow studenta: " + login).c_str());
                    }
                }
                else
                {
                    cout << "\nZla opcja" << endl;
                }
                break;
            }
            case 14:
            {
                //cout<<"Wybrano opcje 14"<<endl;
                string kierunek, grupa;
                cout << "\nPodaj kierunek: ";
                getline(cin >> ws, kierunek);
                cout << "Podaj grupe: ";
                getline(cin >> ws, grupa);
                if(!((Pracownik*)obiekt)->sprawdz_plan_zajec_studenta(kierunek, grupa)) return false;
                log.zapisz_akcje("sprawdzono plan zajec:" + kierunek + " " + grupa);
                break;
            }
            case 15:
            {
                //cout<<"Wybrano opcje 15"<<endl;
                string login, tytul;
                cout << "\nPodaj login studenta: ";
                getline(cin >> ws, login);
                cout << "Podaj tytul ksiazki do wypozyczenia: ";
                getline(cin >> ws, tytul);

                int rezultat = ((Pracownik*)obiekt)->dodaj_ksiazke_studentowi(login, tytul);
                if(rezultat == 1) 
                {
                    cout << "\nBrak ksiazki na stanie biblioteki" << endl;
                    log.zapisz_akcje("wypozyczono ksiazke:brak ksiazki na stanie biblioteki");
                }
                else if(rezultat == 2)
                {
                    cout << "\nStudent posiada juz dana ksiazke" << endl;
                    log.zapisz_akcje("wypozyczono ksiazke:student posiada juz dana ksiazke");
                }
                else
                {
                    cout << "\nWypozyczono ksiazke" << endl;
                    log.zapisz_akcje("wypozyczono ksiazke:" + login + " " + tytul);
                }
                break;
            }
            case 16:
            {
                //cout<<"Wybrano opcje 16"<<endl;
                string login, tytul;
                cout << "\nPodaj login studenta: ";
                getline(cin >> ws, login);
                cout << "Podaj tytul ksiazki do usuniecia: ";
                getline(cin >> ws, tytul);

                int rezultat = ((Pracownik*)obiekt)->usun_ksiazke_studentowi(login, tytul);
                if(rezultat == 1)
                {
                    cout << "\nBlad w usuwaniu ksiazki studenta" << endl;
                    log.zapisz_akcje("blad w usuwaniu ksiazki studenta:" + login + " " + tytul);
                }
                else
                {
                    cout << "\nUsunieto ksiazke" << endl;
                    log.zapisz_akcje("usunieto ksiazke studentowi ksiazke:" + login + " " + tytul);
                }
                break;
            }
            case 17:
            {
                //cout<<"Wybrano opcje 17"<<endl;
                string kierunek, grupa, tytul, sala, prowadzacy, dzien_str;
                int dzien, godzina, min, czas;

                cout << "\nPodaj nazwe kierunku: ";
                getline(cin >> ws, kierunek);
                cout << "Podaj nazwe grupy: ";
                getline(cin >> ws, grupa);
                cout << "Podaj nazwe przedmiotu: ";
                getline(cin >> ws, tytul);
                cout << "Podaj nazwe sali: ";
                getline(cin >> ws, sala);
                cout << "Podaj prowadzacego: ";
                getline(cin >> ws, prowadzacy);
                
                cout << "Podaj dzien: ";
                cin >> dzien_str;
                if(dzien_str == "poniedzialek" || dzien_str == "Poniedzialek")
                {
                    dzien = 1;
                }
                else if(dzien_str == "wtorek" || dzien_str == "Wtorek")
                {
                    dzien = 2;
                }
                else if(dzien_str == "sroda" || dzien_str == "Sroda")
                {
                    dzien = 3;
                }
                else if(dzien_str == "czwartek" || dzien_str == "Czwartek")
                {
                    dzien = 4;
                }
                else if(dzien_str == "piatek" || dzien_str == "Piatek")
                {
                    dzien = 5;
                }
                else if(dzien_str == "sobota" || dzien_str == "Sobota")
                {
                    dzien = 6;
                }
                else if(dzien_str == "niedziela" || dzien_str == "Niedziela")
                {
                    dzien = 7;
                }
                else
                {
                    dzien = 1;
                }

                cout << "Podaj godzine rozpoczecia: ";
                cin >> godzina;
                cout << "Podaj minute rozpoczecia: ";
                cin >> min;
                cout << "Podaj czas trwania: ";
                cin >> czas;

                Plan_zajec::lekcja l(tytul, sala, prowadzacy, dzien, godzina, min, czas);
                ((Pracownik*)obiekt)->dodaj_plan_zajec(kierunek, grupa, l);
                cout << "\nDodano plan zajec" << endl;
                log.zapisz_akcje("dodano plan zajec:" + kierunek + " " + grupa + " " + l.display());
                break;
            }
            case 18:
            {
                string login;
                cout<<"\nPodaj login studenta: ";
                getline(cin >> ws, login);
                cout<<"\nGrupa studenta "<<login<<": "<<((Pracownik*)obiekt)->sprawdzenie_grupy_student("baza\\Student dane.txt", login)<<endl;
                log.zapisz_akcje("sprawdzono grupe studencka studenta:" + login);
                break;
            }
            case 19:
            {
                //cout<<"Wybrano opcje 19"<<endl;
                string haslo, grupa, imie, nazwisko, wydzial, semestr;
                int login = wygeneruj_login_studenta();
                cout<<"\nWygenerowano login studenta: " << login << endl;
                cout<<"Podaj haslo nowego studenta: ";
                getline(cin >> ws, haslo);
                cout<<"Podaj imie nowego studenta: ";
                getline(cin >> ws, imie);;
                cout<<"Podaj nazwisko nowego studenta: ";
                getline(cin >> ws, nazwisko);;
                cout<<"Podaj wydzial nowego studenta: ";
                getline(cin >> ws, wydzial);
                cout<<"Podaj grupe nowego studenta: ";
                getline(cin >> ws, grupa);
                cout<<"Podaj semestr na ktorym ma byc nowy student: ";
                getline(cin >> ws, semestr);
                ((Pracownik*)obiekt)->dodaj_studenta(to_string(login), haslo, grupa, wydzial, imie, nazwisko, semestr);
                cout << "\nDodano studenta" << endl;
                log.zapisz_akcje("dodano studenta:" + to_string(login) + " " + grupa + " " + wydzial + " " + imie + " " + nazwisko + " " + semestr);
                break;
            }
            case 20:
            {
                //cout<<"Wybrano opcje 20"<<endl;
                string login, imie, nazwisko;
                cout << "\nPodaj login studenta, ktorego chcesz usunac: ";
                getline(cin >> ws, login);
                cout << "Podaj imie studenta, ktorego chcesz usunac: ";
                getline(cin >> ws, imie);
                cout << "Podaj nazwisko studenta, ktorego chcesz usunac: ";
                getline(cin >> ws, nazwisko);
                int rezultat = ((Pracownik*)obiekt)->usun_studenta(login, imie, nazwisko);

                if(rezultat == 1)
                {
                    cout << "\nStudent nie istnieje" << endl;
                    log.zapisz_akcje("usunieto studenta: student nie istnieje");
                }
                else
                {
                    ((Pracownik*)obiekt)->usun_wszystkie_ksiazki_studenta(login);
                    ((Pracownik*)obiekt)->usun_wszystkie_oceny_studenta(login);
                    cout << "\nUsunieto studenta" << endl;
                    log.zapisz_akcje("usunieto studenta:" + login + " " + imie + " " + nazwisko);
                }
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

int wygeneruj_login_studenta()
{
    ifstream plik;
    plik.open("baza\\Uzytkownicy.txt");
    if(!plik.good())
    {
        plik.close();
        throw BladPliku("blad pliku - Uzytkownicy.txt");
    }

    int login_temp;
    string haslo_temp;
    int tryb_temp;

    vector<int> pom;

    while(plik >> login_temp >> haslo_temp >> tryb_temp)
    {
        pom.push_back(login_temp);
    }

    sort(pom.begin(), pom.end());

    plik.close();
    return pom.at(pom.size() - 1) + 1;
}

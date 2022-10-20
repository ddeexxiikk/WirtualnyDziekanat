#include "Czlowiek.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
    /*Główny plik, do którego podłączymy własne moduły, aby wykorzystać w mainie jedynie funkcję, 
    które stworzymy we własnych plikach (chyba najlepiej) '.h' + '.cpp'*/
    cout << "Witaj w Wirtualnym Dziekanacie" << endl;

    Czlowiek Student("Jan", "Kowalski", 1);
    Student.Powitanie();
  
    return 0;
}

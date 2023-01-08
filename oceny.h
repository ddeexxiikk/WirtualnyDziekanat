#ifndef OCENY_H
#define OCENY_H
#include <vector>
#include <iostream>

using namespace std;

class oceny
{
    public:
        oceny(string file_name, string login, string przedmiot);
        bool dodanie_oceny(int ocena, int semestr);

    protected:
         vector<int> stopnie;//0 - znaczy brak oceny, pozosta�e oceny tak jak normalnie na studiach
    private:
};

#endif // OCENY_H

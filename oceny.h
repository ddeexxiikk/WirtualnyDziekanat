#ifndef OCENY_H
#define OCENY_H
#include <vector>
#include <iostream>

using namespace std;

class oceny
{
    public:
        oceny(string file_name, string login, string przedmiot);
        virtual bool dodanie_oceny(int ocena, int semestr)=0;

    protected:
         vector<int> stopnie;//0 - znaczy brak oceny, pozosta³e oceny tak jak normalnie na studiach
    private:
};

#endif // OCENY_H

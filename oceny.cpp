#include "oceny.h"
#include <fstream>
#include <sstream>
#include "Wyjatki.h"
oceny::oceny(string file_name, string login, string przedmiot)
{
    ifstream data;
    data.open(file_name.c_str());
    string line, temp_login, temp_przedmiot, temp_semestr, temp_ocena;
    if(data.good())
    {
        while(getline(data, line))
        {
            istringstream csvStream(line);
            getline(csvStream, temp_login, ';');
            getline(csvStream, temp_przedmiot, ';');
            getline(csvStream, temp_semestr, ';');
            getline(csvStream, temp_ocena, ';');
            if(temp_login==login&&temp_przedmiot==przedmiot)
            {
                stopnie[stoi(temp_semestr)]=stoi(temp_ocena);
            }
        }
    }
    else
    {
        data.close();
        throw BladPliku("blad pliku - " + file_name);
    }
    data.close();
}

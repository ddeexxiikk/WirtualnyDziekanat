#include "oceny.h"

oceny::oceny(int ile_semstrow)
{
    //ctor
    oceny_koncowe=new int[ile_semstrow];
    for(int i=0; i<ile_semstrow; i++) oceny_koncowe[i]=0;
}

oceny::~oceny()
{
    //dtor
    delete oceny_koncowe;
}

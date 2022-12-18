#ifndef OCENY_H
#define OCENY_H

class oceny
{
    public:
        oceny(int ile_semestrow);
        ~oceny();
        virtual bool dodanie_oceny(int ocena, int semestr)=0;

    protected:
        int *oceny_koncowe; //0 - znaczy brak oceny, pozostałe oceny tak jak normalnie na studiach
    private:
};

#endif // OCENY_H

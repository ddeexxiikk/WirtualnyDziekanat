#ifndef OCENY_H
#define OCENY_H


class oceny
{
    public:
        oceny(int ile_semstrow);
        ~oceny();
        virtual bool dodanie_oceny(int ocena, int semestr)=0;

    protected:
        int *oceny_koncowe; //0 - znaczy brak oceny, pozosta³e oceny tak jak normalnie na studiach
    private:
};

#endif // OCENY_H

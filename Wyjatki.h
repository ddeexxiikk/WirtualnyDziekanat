#ifndef WYJATKI_H
#define WYJATKI_H

#include <stdexcept>

using namespace std;

class BladPliku : public exception 
{
public:
    BladPliku(const char* wiad) : wiadomosc(wiad) 
    {}

    const char * what () const noexcept override
    {
        return wiadomosc.c_str();
    }

private:
    string wiadomosc;
};

class BladWyboru : public exception 
{
public:
    BladWyboru(const char* wiad) : wiadomosc(wiad) 
    {}

    const char * what () const noexcept override
    {
        return wiadomosc.c_str();
    }

private:
    string wiadomosc;
};

#endif
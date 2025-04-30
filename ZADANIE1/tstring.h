#ifndef TSTRING_H
#define TSTRING_H

#include <cstring>
#include <string>
#include <iostream>


class TString {

    public:
        TString(const char* s = nullptr); // c-tor
        TString(const TString& s); // cc-tor
        TString(TString&& s); // move c-tor
        TString& operator=(const TString& s); // copy operator=
        TString& operator=(TString&& s); // move operator=
        ~TString(); // d-tor

        static size_t getLicznik() { return licznik; }

        const char& operator[](std::size_t n) const; // to zdefiniuj w pełni
        char& operator[](std::size_t n); // to poprzez rzutowanie poprzedniego

        friend std::ostream& operator<<( std::ostream& strumien, const TString& s );
        friend std::istream& operator>>( std::istream& strumien, TString& s );

    private:
        size_t len {};
        char* ptr {};
        
        inline static size_t licznik {}; // licznik obiektow

};

#endif // TSTRING_H
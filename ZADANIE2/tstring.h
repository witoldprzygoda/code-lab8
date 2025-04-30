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

        char* insert(size_t pos, const char* c); 
        char* insert(size_t pos, char c);
        
        void push_back(const char* c) { insert(len, c); } 
        void push_back(char c) { insert(len, c); }

        char* TString::begin() { return ptr; }
        char* TString::end() { return ptr + len; }
        const char* TString::begin() const { return ptr; }
        const char* TString::end() const { return ptr + len; }
        size_t TString::length() const { return len; }
        size_t TString::size() const noexcept { return len; }
        void TString::clear() { delete[] ptr; ptr = nullptr; len = 0; }
        bool TString::empty() const { return len ? false : true; }
        char& TString::front() { return *ptr; }
        const char& TString::front() const { return *ptr; }
        char& TString::back() { return *(ptr + len - 1); }
        const char& TString::back() const { return *(ptr + len - 1); }


        friend std::ostream& operator<<( std::ostream& strumien, const TString& s );
        friend std::istream& operator>>( std::istream& strumien, TString& s );

    private:
        size_t len {};
        char* ptr {};
        
        inline static size_t licznik {}; // licznik obiektow

};

#endif // TSTRING_H
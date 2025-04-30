#define DEBUG
#include "tstring.h"
#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

TString::TString(const char* s) {
    if (s != nullptr) {
        len = strlen(s);
        ptr = new char[len+1]; // +1 bo na koncu jest jeszcze \0 konczące literał napisowy
        strcpy(ptr, s);
    }
    #ifdef DEBUG
        cout << "TString c-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
    #endif
    ++licznik;
}

TString::~TString() {
    #ifdef DEBUG
        cout << "TString d-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
    #endif
    delete [] ptr;
    --licznik;
}

TString::TString(const TString& s) : len(s.len), ptr(s.ptr ? new char[s.len + 1] : nullptr) {
    if (ptr)
        strcpy(ptr, s.ptr);
    #ifdef DEBUG
        cout << "TString cc-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
    #endif
    ++licznik;
}

TString::TString(TString&& s) : len(s.len), ptr(s.ptr) {
    s.len = 0;
    s.ptr = nullptr;
    #ifdef DEBUG
        cout << "TString move c-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
    #endif
    ++licznik;
}

TString& TString::operator=(const TString& s) {
    if (this != &s) {
        delete [] ptr;
        len = s.len;
        ptr = s.ptr ? new char[s.len + 1] : nullptr;
        if (ptr)
            strcpy(ptr, s.ptr);
    }
    #ifdef DEBUG
        cout << "TString copy operator=: [" << (ptr ? ptr : "pusty") << "]" << endl;
    #endif
    return *this;
}

TString& TString::operator=(TString&& s) {
    if (this != &s) {
        delete [] ptr;
        len = s.len;
        ptr = s.ptr;
        s.len = 0;
        s.ptr = nullptr;
    }
    #ifdef DEBUG
        cout << "TString move operator=: [" << (ptr ? ptr : "pusty") << "]" << endl;
    #endif
    return *this;
}


char* TString::insert(size_t pos, const char* c) {
    if (c == nullptr) return ptr;
    if (pos > len) throw std::out_of_range("Zly argument");

    size_t insert_len = std::strlen(c);
    size_t new_len = len + insert_len;
    char* tmp = new char[new_len + 1]; 

    // Kopiowanie starego przedziału przed 'pos'
    std::strncpy(tmp, ptr, pos);
    // Kopiowanie wstawianego ciągu
    std::strcpy(tmp + pos, c);
    // Kopiowanie starego przedziału za 'pos'
    std::strcpy(tmp + pos + insert_len, ptr + pos);

    delete[] ptr; // Usuwamy stary ciąg
    ptr = tmp;    // Przypisujemy nowy ciąg do ptr
    len = new_len; // Aktualizujemy długość

    return ptr + pos; // Wskaźnik do miejsca wstawienia
}

char* TString::insert(size_t pos, char c) {
   return insert(pos, string( { c } ).c_str()); 
} 

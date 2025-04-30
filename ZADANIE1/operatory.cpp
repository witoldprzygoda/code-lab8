#include "tstring.h"

using namespace std;

std::ostream& operator<<(std::ostream& strumien, const TString& s) {
    if (s.ptr)
        strumien << s.ptr;
    return strumien;
}

std::istream& operator>>(std::istream& strumien, TString& s) {
    std::string tmp;
    if (strumien >> tmp) {
        s = tmp.c_str(); // używa operatora przypisania kopiującego TString
    }
    return strumien;
}

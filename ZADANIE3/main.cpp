#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

class TKlasa {
public:
    TKlasa(const char* c) : str(c) {}

// operator<=>

// operator std::string_view

// operator const char* - sprawdzić co się stanie


private:
    std::string str;
};

int main() {
    TKlasa obj1("AAAA");
    TKlasa obj2("BBBB");

    if ((obj1 <=> obj2) < 0)
        std::cout << std::string_view(obj1) << " jest przed " << std::string_view(obj2) << '\n';
    else
        std::cout << std::string_view(obj1) << " jest po " << std::string_view(obj2) << '\n';

    std::string_view sv = obj2;
    std::cout << "Konwersja do string_view: " << sv << '\n';

    std::vector<TKlasa> vec = { "ZZZZ", "YYYY", "DDDD", "TTTT", "HHHH" };

    std::ranges::sort(vec);

    std::cout << "Posortowane:\n";
    for (const auto& item : vec)
        std::cout << std::string_view(item) << '\n';

    return 0;
}

# Zadanie 3

Mamy klasę TKlasa. Proszę do niej dopisać operator<=> i operator konwersji do std::string_view. W programie są przypadki użycia powyższych. Ponadto jest wektor obiektów TKlasa, zainicjalizowany (5 elementów) i posortowanyza pomocą std::ranges::sort. Po sprawdzeniu powyższego, dodać jeszcze operator konwersji do const char* i zobaczyć, co się stanie z wynikiem sortowania. Jak można taką sytuację naprawić (patrz trzeci argument ranges::sort)? Rozwiązaniem może być dodanie explicit do konwersji na const char*, ale wtedy również definicja operator==.


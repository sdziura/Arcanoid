// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

#ifndef PCH_H
#define PCH_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

const unsigned 
BLOCKSX{ 10 }, BLOCKSY{ 4 }, 
BLOCKWIDTH{ 60 }, BLOCKHEIGHT{ 20 }, 
WINDOWWIDTH{ 800 }, WINDOWHEIGHT{ 600 },
BALLPOSX{ 400 }, BALLPOSY{ 300 },
PADDLEPOSX{ 400 }, PADDLEPOSY{ 550 };



#endif //PCH_H

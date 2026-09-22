#include "Biblioteka.h"
#include <iostream>
using namespace std;

void Biblioteka::dodajKsiazke(Ksiazka ksiazka) {
	ksiazki.push_back(ksiazka);
}

void Biblioteka::wyswietlKsiazki() {
    if (ksiazki.empty()) {
        cout << "Brak ksiazek \n";
    }
    else {
        cout << "\n";
        for (Ksiazka& ksiazka : ksiazki) {
            ksiazka.wyswietl();
        }
    }
}
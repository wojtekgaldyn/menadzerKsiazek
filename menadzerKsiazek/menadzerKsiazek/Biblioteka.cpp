#include "Biblioteka.h"
#include <iostream>
using namespace std;

void Biblioteka::dodajKsiazke(Ksiazka ksiazka) {
	ksiazki.push_back(ksiazka);
}

bool Biblioteka::usunKsiazke(int id)
{
    for (auto it = ksiazki.begin(); it != ksiazki.end(); ++it)
    {
        if (it->getId() == id)
        {
            ksiazki.erase(it);
            return true;
        }
    }

    return false;
}

void Biblioteka::wyswietlKsiazki() {
    if (ksiazki.empty()) {
        cout << "Brak ksiazek \n";
    }
    else {
        cout << "\n";
        for (Ksiazka& ksiazka : ksiazki) {
            ksiazka.wyswietl();
            cout << "\n";
        }
    }
}

vector<Ksiazka>& Biblioteka::pobierzKsiazki()
{
    return ksiazki;
}

int Biblioteka::pobierzNastepneId() {
    int najwyzszeId = 0;

    for (Ksiazka& ksiazka : ksiazki) {
        if (ksiazka.getId() > najwyzszeId) {
            najwyzszeId = ksiazka.getId();
        }
    }
    return najwyzszeId + 1;
}
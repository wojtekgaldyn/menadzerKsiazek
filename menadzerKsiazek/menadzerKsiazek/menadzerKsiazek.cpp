#include <iostream>
#include <vector>
#include <string>
#include "Ksiazka.h"
#include "Biblioteka.h"

using namespace std;
int main()
{
    Biblioteka biblioteka;
    int nastepneId = 1;
    int wybor;

    while (true) {
        cout << "\n===== TASK MANAGER =====\n";
        cout << "1. Dodaj ksiazke\n";
        cout << "2. Usun ksiazke\n";
        cout << "3. Pokaz ksiazki\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz: ";

        cin >> wybor;
        cin.ignore();
        if (wybor == 1) {
            string tytul;
            string autor;
            int rok;
            cout << "Podaj tytul ksiazki: \n";
            getline(cin, tytul);
            cout << "Podaj autora ksiazki: \n";
            getline(cin, autor);
            cout << "Podaj rok wydania ksiazki: \n";
            cin >> rok;

            Ksiazka nowaKsiazka(nastepneId, tytul, autor, rok);
            biblioteka.dodajKsiazke(nowaKsiazka);

            nastepneId++;

            cout << "Dodano ksiazke.\n";
        }
        else if (wybor == 2) {
            int idKsiazkiDoUsuniecia;
            cout << "Podaj id ksiazki do usuniecia \n";
            cin >> idKsiazkiDoUsuniecia;
            biblioteka.usunKsiazke(idKsiazkiDoUsuniecia);
        }
        else if (wybor == 3) {
            biblioteka.wyswietlKsiazki();
        }
    }
}

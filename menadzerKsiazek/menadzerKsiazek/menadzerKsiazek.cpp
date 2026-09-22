#include <iostream>
#include <vector>
#include <string>
#include "Ksiazka.h"
#include "Biblioteka.h"
#include "FileManager.h"

using namespace std;
int main()
{
    Biblioteka biblioteka;
    int wybor;
    FileManager::wczytajZPliku(biblioteka, "books.txt");
    int nastepneId = biblioteka.pobierzNastepneId();
    while (true) {
        cout << "\n===== MENADZER KSIAZEK =====\n";
        cout << "1. Dodaj ksiazke\n";
        cout << "2. Usun ksiazke\n";
        cout << "3. Pokaz ksiazki\n";
        cout << "4. Zapis ksiazek w bazie\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz: ";

        cin >> wybor;
        cin.ignore();
        if (wybor == 0)
        {
            break;
        }
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
            cin.ignore();

            Ksiazka nowaKsiazka(nastepneId, tytul, autor, rok);
            biblioteka.dodajKsiazke(nowaKsiazka);

            nastepneId++;

            cout << "Dodano ksiazke.\n";
        }
        else if (wybor == 2) {
            int idKsiazkiDoUsuniecia;
            cout << "Podaj id ksiazki do usuniecia \n";
            cin >> idKsiazkiDoUsuniecia;
            cin.ignore();

            if (biblioteka.usunKsiazke(idKsiazkiDoUsuniecia))
            {
                cout << "Usunieto ksiazke.\n";
            }
            else
            {
                cout << "Nie znaleziono ksiazki o takim ID.\n";
            }
        }
        else if (wybor == 3) {
            biblioteka.wyswietlKsiazki();
        }
        else if(wybor == 4) {
            FileManager::zapiszDoPliku(biblioteka, "books.txt");
        }
    }
}

#include "FileManager.h"
#include <fstream>
#include <sstream>
using namespace std;

bool FileManager::zapiszDoPliku(Biblioteka& biblioteka, string nazwaPliku)
{
    ofstream plik(nazwaPliku);

    if (!plik.is_open())
    {
        return false;
    }

    for (Ksiazka& ksiazka : biblioteka.pobierzKsiazki())
    {
        plik << ksiazka.getId() << "|"
            << ksiazka.getTytul() << "|"
            << ksiazka.getAutor() << "|"
            << ksiazka.getRokWydania() << "|"
            << "\n";
    }

    plik.close();

    return true;
}

bool FileManager::wczytajZPliku(Biblioteka& biblioteka, string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open())
    {
        return false;
    }

    string linia;

    while (getline(plik, linia))
    {
        stringstream ss(linia);

        string id;
        string tytul;
        string autor;
        string rok;

        getline(ss, id, '|');
        getline(ss, tytul, '|');
        getline(ss, autor, '|');
        getline(ss, rok, '|');

        Ksiazka ksiazka(
            stoi(id),
            tytul,
            autor,
            stoi(rok)
        );

        biblioteka.dodajKsiazke(ksiazka);
    }

    plik.close();

    return true;
}
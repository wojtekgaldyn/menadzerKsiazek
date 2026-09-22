#include "Ksiazka.h"
#include <iostream>

using namespace std;

Ksiazka::Ksiazka(int idKsiazki, string tytulKsiazki, string autorKsiazki, int rokWydaniaKsiazki) {
	id = idKsiazki;
	tytul = tytulKsiazki;
	autor = autorKsiazki;
	rokWydania = rokWydaniaKsiazki;
};

void  Ksiazka::wyswietl() {
	cout << "ID: " << id << "\n";
	cout << "Tytul: " << tytul << "\n";
	cout << "Autor: " << autor << "\n";
	cout << "Rok wydania: " << rokWydania << "\n";
};

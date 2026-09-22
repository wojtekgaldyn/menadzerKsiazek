#pragma once
#include "Ksiazka.h"
#include <vector>
using namespace std;
class Biblioteka
{
private:
	vector<Ksiazka> ksiazki;

public:
	void dodajKsiazke(Ksiazka ksiazka);
	void wyswietlKsiazki();
	bool usunKsiazke(int id);
};



#pragma once

#include <string>
using namespace std;

class Ksiazka
{
private:
	int id;
	string tytul;
	string autor;
	int rokWydania;

public:
	Ksiazka(int idKsiazki, string tytulKsiazki, string autorKsiazki, int rokWydaniaKsiazki);
	void wyswietl();
	int getId();
	string getTytul();
	string getAutor();
	int getRokWydania();
};


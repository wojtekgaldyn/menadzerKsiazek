#pragma once
#include "Biblioteka.h"
#include <string>

class FileManager
{
public:
    static bool zapiszDoPliku(Biblioteka& biblioteka, std::string nazwaPliku);
    static bool wczytajZPliku(Biblioteka& biblioteka, std::string nazwaPliku);
};


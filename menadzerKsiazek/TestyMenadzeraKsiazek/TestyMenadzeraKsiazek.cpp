#include "pch.h"
#include "CppUnitTest.h"

#include "../menadzerKsiazek/Biblioteka.h"
#include "../menadzerKsiazek/Ksiazka.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestyMenadzeraKsiazek
{
	TEST_CLASS(TestyMenadzeraKsiazek)
	{
	public:
		
		TEST_METHOD(DodawanieKsiazki) 
		{ 
			Biblioteka biblioteka; 
			Ksiazka ksiazka(1, "Wiedzmin", "Andrzej Sapkowski", 1993); 
			biblioteka.dodajKsiazke(ksiazka); 
			Assert::AreEqual((size_t)1, biblioteka.pobierzKsiazki().size()); 
		}
		TEST_METHOD(UsuwanieKsiazki) 
		{	
			Biblioteka biblioteka;
			Ksiazka ksiazka(1, "Wiedzmin", "Andrzej Sapkowski", 1993); 
			biblioteka.dodajKsiazke(ksiazka); 
			bool wynik = biblioteka.usunKsiazke(1); 
			Assert::IsTrue(wynik); 
			Assert::AreEqual((size_t)0, biblioteka.pobierzKsiazki().size());
		}

		TEST_METHOD(UsuwanieNieistniejacejKsiazki) 
		{ 
			Biblioteka biblioteka; 
			Ksiazka ksiazka(1, "Wiedzmin", "Andrzej Sapkowski", 1993); 
			biblioteka.dodajKsiazke(ksiazka);
			bool wynik = biblioteka.usunKsiazke(99);
			Assert::IsFalse(wynik);
			Assert::AreEqual((size_t)1, biblioteka.pobierzKsiazki().size()); 
		}

		TEST_METHOD(PobieranieNastepnegoId) 
		{ 
			Biblioteka biblioteka; 
			Ksiazka ksiazka1(1, "Wiedzmin", "Andrzej Sapkowski", 1993); 
			Ksiazka ksiazka2(5, "Hobbit", "J.R.R. Tolkien", 1937); 
			biblioteka.dodajKsiazke(ksiazka1); 
			biblioteka.dodajKsiazke(ksiazka2); 
			int noweId = biblioteka.pobierzNastepneId();
			Assert::AreEqual(6, noweId); 
		}
		TEST_METHOD(SprawdzenieDanychKsiazki) 
		{ 
			Biblioteka biblioteka;
			Ksiazka ksiazka(1, "Wiedzmin", "Andrzej Sapkowski", 1993);
			biblioteka.dodajKsiazke(ksiazka);
			Ksiazka& znalezionaKsiazka = biblioteka.pobierzKsiazki()[0]; 
			Assert::AreEqual(1, znalezionaKsiazka.getId()); 
			Assert::AreEqual(std::string("Wiedzmin"), znalezionaKsiazka.getTytul()); 
			Assert::AreEqual(std::string("Andrzej Sapkowski"), znalezionaKsiazka.getAutor());
			Assert::AreEqual(1993, znalezionaKsiazka.getRokWydania());
		}
	};
}

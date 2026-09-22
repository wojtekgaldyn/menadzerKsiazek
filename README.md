# Menedżer książek

Prosta aplikacja konsolowa napisana w języku C++ w Visual Studio.

## Opis projektu

Program pozwala zarządzać listą książek. Dane książek są przechowywane w pliku tekstowym `books.txt`.

Projekt został podzielony na kilka klas:

- `Ksiazka` – przechowuje informacje o pojedynczej książce.
- `Biblioteka` – zarządza listą książek.
- `FileManager` – odpowiada za zapis i odczyt danych z pliku.
- `main.cpp` – obsługuje menu oraz komunikację z użytkownikiem.

## Funkcjonalności

Program umożliwia:

1. Dodawanie książek.
2. Usuwanie książek na podstawie ID.
3. Wyświetlanie wszystkich książek.
4. Zapisywanie książek do pliku `books.txt`.
5. Wczytywanie książek z pliku przy uruchomieniu programu.
6. Automatyczne nadawanie kolejnych ID książkom.

## Testy

Projekt zawiera testy jednostkowe wykorzystujące framework Microsoft Visual Studio CppUnitTestFramework.

Testy sprawdzają między innymi:

- dodawanie książki,
- usuwanie książki,
- próbę usunięcia nieistniejącej książki,
- generowanie kolejnego ID,
- poprawność danych książki.

## Wymagania

Do uruchomienia projektu potrzebne są:

- Windows,
- Visual Studio 2022,
- workload `Desktop development with C++`.

## Uruchomienie

1. Sklonuj repozytorium.
2. Otwórz plik `.sln` w Visual Studio.
3. Ustaw projekt `menadzerKsiazek` jako projekt startowy.
4. Zbuduj Solution:
   
   `Build → Build Solution`

5. Uruchom program.

Przy pierwszym zapisie danych plik `books.txt` zostanie utworzony automatycznie.

## Uruchamianie testów

W Visual Studio wybierz:

`Test → Test Explorer`

Następnie wybierz:

`Run All`

Testy powinny zakończyć się statusem `Passed`.

## GitHub Actions

Projekt posiada pipeline CI, który:

1. uruchamia się po `push`,
2. uruchamia się przy `pull_request` do gałęzi `main`,
3. buduje Solution w konfiguracji `Release`,
4. uruchamia testy jednostkowe.

Dzięki temu każda zmiana wysłana do repozytorium jest automatycznie sprawdzana.

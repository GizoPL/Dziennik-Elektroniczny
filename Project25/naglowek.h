#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
struct uczen {    
	string imie;
	string nazwisko;
	uczen * kolejny;
	vector<double> oceny_ucznia;
	int numer_ucznia;
	void drukuj();
	
};
using Uczen = uczen * ;

//struktura listy
struct Lista {
	Uczen pierwszy;
	void dodaj();
	void drukujListe();
	void szukaj();
	void losuj_ucznia_do_odpowiedzi();
	void usun(int);
	void przydzielanie_numeru_ucznia();
	void zapisz_do_pliku();
	void dodaj_ocene();
};
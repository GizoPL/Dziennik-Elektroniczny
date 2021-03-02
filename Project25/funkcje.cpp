#include "naglowek.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iomanip>


using namespace std;
void uczen::drukuj()  
{
	cout << setw(2)<< numer_ucznia <<". " << setw(21) << nazwisko << setw(21) << imie <<"        " << "| ";  //  Konifurowanie odpowiedniego sposobu wyswietlania obiektow listy.
	for(int i=0;i < oceny_ucznia.size();i++) //  Wyswietlanie ocen 
	{
		cout << oceny_ucznia[i] << " | ";
		
	}
	cout << endl;
	cout << endl;
}

void Lista::dodaj()
{
	Uczen Nowy = new uczen;
	cout << "Imie:";				//
	string imie, nazwisko;			//Wprowadzanie danych nowego ucznia.
	cin >> imie;					//
	cout << "Nazwisko:";			//
	cin >> nazwisko;				//
	Nowy->imie = imie;				//
	Nowy->nazwisko = nazwisko;		//
	cout << "Ilosc ocen ucznia :";	//
	int ilosc_ocen;
	cin >> ilosc_ocen;
	for (int i = 0; i < ilosc_ocen; i++)	//  Wprowadzanie dowlonej ilosci ocen dla nowego ucznia.
	{										
		double oceny;
		cout << "Ocena nr." << i+1<<":";
		cin >> oceny;
		Nowy->oceny_ucznia.push_back(oceny);
	}
	//sprawdzamy czy cos juz jest na liscie;
	if (pierwszy == nullptr)
	{
		pierwszy = Nowy;
		Nowy->kolejny = nullptr;
	}
	else
	{
		Uczen Biezacy = pierwszy;
		while (Biezacy->kolejny)
			Biezacy = Biezacy->kolejny;
		Biezacy->kolejny = Nowy;
		Nowy->kolejny = nullptr;
	}
	getchar();
	getchar();
	system("cls");
}
void Lista::drukujListe()
{
	Uczen biezacy = pierwszy;
	if(biezacy != nullptr)
	{
		cout << "Lp." << "              Nazwisko"<< "                 Imie    " << "     Oceny" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
		while (biezacy != nullptr)
		{
			biezacy->drukuj();
			biezacy = biezacy->kolejny;
		}
	} 
	else
		cout << "*** Lista jest pusta ***" << endl;
}

void Lista::szukaj()
{
	Uczen biezacy = new uczen;
	biezacy = pierwszy;
	string nazwisko_szukane,imie_szukane;
	cout << "Nazwisko:"; cin >> nazwisko_szukane;			//Wprowadzenie danych szukanej osoby.
	cout << "Imie:"; cin >> imie_szukane;					//
	system("cls");
	if (biezacy->nazwisko == nazwisko_szukane && biezacy->imie == imie_szukane)
	{
		cout << "Lp." << "              Nazwisko" << "                 Imie    " << "     Oceny" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------" << endl;
		biezacy->drukuj();
	}
	else
	{
		while (biezacy->kolejny != nullptr)
		{
			biezacy = biezacy->kolejny;
			if (biezacy->nazwisko == nazwisko_szukane && biezacy->imie == imie_szukane)
			{
				cout << "Lp." << "              Nazwisko" << "                 Imie    " << "     Oceny" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------" << endl;
				biezacy->drukuj();
				break;
			}

		}
	}
	getchar();
	getchar();
	system("cls");
}

void Lista::losuj_ucznia_do_odpowiedzi()
{
	Uczen biezacy = pierwszy;
	int liczba_osob_w_lisicie = 0;
	while (biezacy != nullptr)
	{
		biezacy = biezacy->kolejny;

		liczba_osob_w_lisicie++;
	}
	
	srand(time(NULL));											//losowanie liczby dowolonej z zakresu od 1 do liczby uczniow wprowadzonych do dziennika 
	int losowa_liczba = (rand() % liczba_osob_w_lisicie) + 1;	//
	biezacy = pierwszy;
	if(losowa_liczba !=1)
	{
		biezacy = biezacy->kolejny;								//
		for (int i = 2; i < losowa_liczba; i++)					//ustawienie wskaznika na osobe o pozycji w liscie wylosowanej w powyzszym kroku.
			biezacy = biezacy->kolejny;							//
	}
	cout << "Do odpowiedzi zostal wywolany uczen:" << biezacy->nazwisko << ' ' << biezacy->imie<<endl; //Wywolanie osoby wylosowanej do odpowiedzi
}

void Lista::usun(int nr)
{	
	Uczen wczesniejszy, biezacy;
	int ind = 1;
	if (pierwszy == nullptr) return;
	if (nr == 1) {
		biezacy = pierwszy->kolejny;
		delete pierwszy;
		pierwszy = biezacy;
	}
	else {
		biezacy = pierwszy;
		wczesniejszy = pierwszy;
		while (biezacy->kolejny != nullptr&&ind < nr) {
			wczesniejszy= biezacy;
			biezacy = biezacy->kolejny;
			ind++;
		}
		if (biezacy != nullptr) {
			wczesniejszy->kolejny = biezacy->kolejny;
			delete biezacy;
		}
	}
}

void Lista::przydzielanie_numeru_ucznia()
{
	int numer = 1;    //ustaweine poczatkowego numeru
	Uczen biezacy = pierwszy;
	while (biezacy != nullptr) //Petla w ktorej kazdemu nastepnemu uczniowi przydziela sie numer o 1 wiekszy od poprzedniego.
		{
		biezacy->numer_ucznia = numer;
		numer++;
		biezacy = biezacy->kolejny;
		}
}
void Lista::dodaj_ocene()
{
	Uczen biezacy = new uczen;
	biezacy = pierwszy;
	string nazwisko_szukane, imie_szukane;
	cout << "Nazwisko:"; cin >> nazwisko_szukane;
	cout << "Imie:"; cin >> imie_szukane;
	system("cls");
	if (biezacy->nazwisko == nazwisko_szukane && biezacy->imie == imie_szukane)
	{
		int ilosc_ocen;
		cout << "Ile ocen chcesz dopisac:";
		cin >> ilosc_ocen;
		for (int i = 0; i < ilosc_ocen; i++)
		{
			double oceny;
			cout << "Ocena nr." <<(i + 1) << ":";
			cin >> oceny;
			biezacy->oceny_ucznia.push_back(oceny); // Dopisanie kolejnych ocen ucznia do klasy vektor.
		}
	}
	else
	{
		while (biezacy->kolejny != nullptr)
		{
			biezacy = biezacy->kolejny;
			if (biezacy->nazwisko == nazwisko_szukane && biezacy->imie == imie_szukane)
			{
				int ilosc_ocen;
				cout << "Ile ocen chcesz dopisac:";
				cin >> ilosc_ocen;
				for (int i = 0; i < ilosc_ocen; i++)
				{
					double oceny;
					cout << "Ocena nr." << + (i+1) << ":";
					cin >> oceny;
					biezacy->oceny_ucznia.push_back(oceny);
				}
				break;
			}

		}
	}
	
}


void Lista::zapisz_do_pliku()
{
	fstream plik;								//Utworzenie pliku "Lista_uczniow.txt" i otowrzenie go z trybem otwarcia umozliwiajacym zapis danych do pliku.
	plik.open("Lista_uczniow.txt", ios::out);	//
	Uczen biezacy = pierwszy;
	plik << "Lp." << "              Nazwisko" << "                 Imie    " << "     Oceny" << endl;
	plik << "---------------------------------------------------------------------------------------------------------------" << endl;

		while (biezacy != nullptr) //Wpisywanie kolejnych osob z listy wraz z jej numerem i ocenami, w wyniku czego otrzymujemy pelna liste zapisana w pliku tekstowym.
		{
			plik<< setw(2) << biezacy->numer_ucznia << ". " << setw(21) << biezacy->nazwisko << setw(21) << biezacy->imie << "        " << "| ";
			for (int i = 0; i < biezacy->oceny_ucznia.size(); i++)
			{
				plik << biezacy->oceny_ucznia[i] << " | ";

			}
			plik << endl;
			biezacy = biezacy->kolejny;
		}
	plik.close();								// Zamkniecie pliku po operacji zapisu listy.
	cout << "*** Lista uczniow zostala zapisana ***";
	getchar();
	getchar();
	system("cls");
}





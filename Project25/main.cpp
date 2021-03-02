#include <iostream>
#include <string>
#include "naglowek.h"
#include <vector>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <iomanip>

Lista struktura;
using namespace std;
int main()
{
	int petla_menu = 0;
	while (petla_menu != 1)  //Petla, umozliwiajaca zakonczenie dzialania programu oraz powrot do menu po kazdej wykonanej czynnosci.
	{
		cout << "***********DZIENNIK************" << endl; //MENU DZIENNIKA.
		cout << "[1].Skonfiguruj dziennik" << endl;
		cout << "[2].Wyswietl dziennik" << endl;
		cout << "[3].Wprowadz ocene" << endl;
		cout << "[4].Szybkie wyszukiwanie ucznia" << endl;
		cout << "[5].Losuj ucznia do odpowiedzi" << endl;
		cout << "[6].Usun ucznia z dziennika" << endl;
		cout << "[7].Zapisz liste w pliku" << endl;
		cout << "[8].Wyjscie." << endl;
		int wybor;
		cout << "Wybor:"; cin >> wybor; //Wybor akcji z menu.
		system("cls");
		switch (wybor)
		{
		case 1:
			int liczba_uczniow_do_wprowadzenia;
			cout << "Liczba uczniow do wprowadzenia:";
			cin >>  liczba_uczniow_do_wprowadzenia;
			system("cls");
			for(int i=0;i< liczba_uczniow_do_wprowadzenia;i++)				 // Petla For pozwala nam utowrzyc dziennik poprzez wprowadzenie kilku
				struktura.dodaj();											//uczniow na raz. 
				struktura.przydzielanie_numeru_ucznia();	//Funckcja odpowiedzialna za wprowadzanie danych i towrzenie dziennika.
				cout << "*** dziennik zostal skonfigurowany ***";
				getchar();
				system("cls");
			break;
		case 2:
			struktura.drukujListe();	//Funckcja odpowiedzialna za wyswietlanie dziennika.
			getchar();
			getchar();
			system("cls");
			break;
		case 3:
			struktura.dodaj_ocene();	//Funkcja umozliwiajaca dodanie dowolnej ilosci ocen do ucznia znajdujacego sie w dzienniku
			getchar();
			getchar();
			system("cls");
			break;
		case 4:
			struktura.szukaj();							//Funkcja umozliwiajaca szybki dostep do informacji konretnego ucznia(numer,dane osobowe, oceny)
			break;
		case 5:
			struktura.losuj_ucznia_do_odpowiedzi();		//Funkcja umozliwiajaca losowanie dowolnego ucznia z calej listy do odpowiedzi. 
			getchar();
			getchar();
			system("cls");
			break;
		case 6:
			int nr;										//Numer ucznia, ktorego usuwamy z listy. 
			cout << "Podaj numer ucznia:"; cin >> nr;
			struktura.usun(nr);							//Funkcja odpowiedzialna za proces usuwania.
			struktura.przydzielanie_numeru_ucznia();	//Funkcja, która na nowo przydziela numery w liscie dla kazdego ucznia.
			system("cls");
			cout << "*** Uczen o numerze " << nr << " zostal usuniety ***";
			getchar();
			getchar();
			system("cls");
			break;
		case 7:
			struktura.zapisz_do_pliku();				//Funkcja zapisujaca liste w pliku typu "txt".
			break;
		case 8:
			petla_menu = 1;								//Powoduje zakonczenie petli while i tym samym zakonczenie dzialania programu
			break;
		}
	}



	system("pause");
}



































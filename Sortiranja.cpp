// Sortiranja.cpp : Razlièiti algoritmi sortiranja
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "time.h"

using namespace std;

void BubbleSort(int lista[], int velicina);
void SelectionSort(int lista[], int velicina);
void InsertionSort(int lista[], int velicina);
void sortiraj_imena(string popis[], int velicina);

int main()
{
	srand(time(NULL));
	int velicina_polja;
	
	cout << "Unesi koliko brojeva/imena zelis sortirati:";
	cin >> velicina_polja;

	int *polje = new int[velicina_polja];
	string *polje_ime = new string[velicina_polja];
	
	//cout << "Unesi " << velicina_polja << " nasumicnih brojeva (mogu biti i negativni):" << endl;
	for (int i = 0; i < velicina_polja; i++)
	{
		polje[i] = rand() % 1000 + 1;
	}

	/*cout << "Unesi " << velicina_polja << " imena:" << endl;
	for (int i = 0; i < velicina_polja; i++)
	{
		cin >> polje_ime[i];
	}
	*/

	cout << "Nesortirani brojevi:" << endl;
	for (int i = 0; i < velicina_polja; i++)
	{
		cout << polje[i] << "\t";
	}

	// BubbleSort(polje, velicina_polja);
	// SelectionSort(polje, velicina_polja);
	// InsertionSort(polje, velicina_polja);
	// sortiraj_imena(polje_ime, velicina_polja);

	cout << endl << "Sortirani brojevi:" << endl;
	for (int i = 0; i < velicina_polja; i++)
	{
		cout << polje[i] << "\t";
	}



	cout << endl;
 
	delete[] polje;
	system("PAUSE");
    return 0;
}

void BubbleSort(int lista[], int velicina)
{
	int temp, j;
	bool bilaZamjena = true;

	for (int i = 0; bilaZamjena == true; i++)
	{
		bilaZamjena = false;
		for (j = 0; j < velicina - 1 - i; j++)
		{
			if (lista[j] > lista[j + 1])
			{
				temp = lista[j];
				lista[j] = lista[j + 1];
				lista[j + 1] = temp;
				bilaZamjena = true;
			}
		}
	}
}

void SelectionSort(int lista[], int velicina)
{
	int min, temp, i, j;
	
	for (i = 0; i < velicina - 1; i++)
	{
		min = i;
		for (j = i + 1; j < velicina; j++)
		{
			if (lista[j] < lista[min])
			{
				min = j;
			}
		}
		temp = lista[i];
		lista[i] = lista[min];
		lista[min] = temp;
	}
}

void InsertionSort(int lista[], int velicina)
{
	int temp, i, j;

	for (i = 0; i < velicina; i++)
	{
		temp = lista[i];
		for (j = i; j >= 1 && lista[j - 1] > temp; j--)
		{
			lista[j] = lista[j - 1];
		}
		lista[j] = temp;
	}
}

void sortiraj_imena(string popis[], int velicina) {
	string temp;
	int j;
	bool bilaZamjena = true;

	for (int i = 0; bilaZamjena == true; i++)
	{
		bilaZamjena = false;
		for (j = 0; j < velicina - 1 - i; j++)
		{
			if (popis[j] > popis[j + 1])
			{
				temp = popis[j];
				popis[j] = popis[j + 1];
				popis[j + 1] = temp;
				bilaZamjena = true;
			}
		}
	}
}
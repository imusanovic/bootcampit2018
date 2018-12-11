// Pretrazivanja.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// 3 parametra - polje, velicina polja i trazeni broj
int linearnoPretrazivanje(int polje[], int velicina, int trazeniBroj) { 
	// prelazimo polje jedan element za drugim
	for (int i = 0; i <= 9; i++) 
	{
		// tražimo poklapa li se vrijednost s traženim brojem
		if (polje[i] == trazeniBroj) 
		{
			// ukoliko se poklapa vraæamo poziciju u polju na kojem se vrijednost nalazi
			return i; 
		}
	}
	// ukoliko smo prošli cijelo polje i nismo pronašli element vraæamo vrijednost -1
	return -1; 
}

// 3 parametra - polje, velicina polja i trazeni broj
int binarnoPretrazivanje(int polje[], int velicina, int trazeniBroj) 
{
	// postavljanje pocetka na prvi element u polju
	int start = 0;
	// postavljanje kraja na zadnji element u polju
	int kraj = velicina;
	// postavljanje sredine na element u aritmetickoj sredini
	int sredina = (start + kraj) / 2; 


	// postavljanje uvjeta za while petlju neka se ponavlja dok god je pocetak manji ili
	// jednak kraju i dok vrijednost polje[sredina] nije jednaka trazenom broju -
	// ako su uvjeti zadovoljeni onda izlazimo van iz petlje jer smo ili presli sve
	// elemente ili pronasli trazeni broj
	while (start<=kraj && polje[sredina] != trazeniBroj) 
	{
		// ako uvjeti nisu zadovoljeni, provjeravamo je li trazeni broj veci ili manji od
		// trenutne vrijednosti sredine polja
		if (polje[sredina] < trazeniBroj)
		{
			// ukoliko je sredina manja od trazenog broja onda se trazeni broj nalazi u
			// veæoj polovici pa start postavljamo na trenutnu vrijednost sredine + 1,
			// dok kraj ostaje isti na taj naèin smo eliminirali polovicu polja na kojoj
			// se nalaze brojevi koji su manji od trazenog broja
			start = sredina + 1;
		}
		else
		{
			// ista stvar kao i iznad samo za suprotni slucaj - kada je trazeni broj manji od
			// vrijednosti na sredini tablice
			kraj = sredina - 1;
		}
		// nakon što smo "ispravili" vrijednost starta ili kraja ponovo racunamo sredinu
		// (sada se ona nalazi na polovici polovice, itd..)
		sredina = (start + kraj) / 2;
	}

	// while petlja se vrti dok god se ne "poklope" pocetak i kraj polja - sto znaci
	// da smo prosli cijelo polje ili dok se vrijednost sredine ne poklopi sa trazenim
	// brojem sto znaci da smo pronasli trazeni broj

	// nakon izlaska iz while petlje pitamo se je li pronadjen trazeniBroj - ako jest
	// onda vracamo vrijednost sredine (pozicije u polju na kojemu se nalazi trazeni broj)
	if (polje[sredina] == trazeniBroj)
	{
		return sredina;
	}
	// ako nije onda vracamo -1
	else
	{
		return -1;
	}
}

int main()
{
	// polje1 - za linearno pretrazivanje - ne mora biti sortirano
	int polje1[10] = { 10, 5, 7, 12, 345, 76, 34, 13, 9, 11 };
	// polje2 - za binarno pretrazivanje - mora biti sortirano
	int polje2[10] = { 5, 7, 11, 15, 64, 76, 101, 300, 444, 445 };

	// deklariranje varijable trazenog broja
	int trazeniBroj;

	// Unos trazenog broja u varijablu trazeniBroj
	cout << "Unesi broj koji zelis: ";
	cin >> trazeniBroj;

	// spremanje rezultata linearnogPretrazivanja u varijablu x i binarnog u varijablu y
	int x = linearnoPretrazivanje(polje1, 9, trazeniBroj);
	int y = binarnoPretrazivanje(polje2, 9, trazeniBroj);

	// Ispis rezultata za linearno pretrazivanje u polju1
	cout << "Linearno pretrazivanje: " << endl;
	if (x == -1)
	{
		cout << "Broj nije pronaden!" << endl;
	}
	else
	{
		cout << "Broj je pronaden na poziciji " << x << endl;
	}

	// Ispis rezultata za binarno pretrazivanje u polju2
	cout << "Binarno pretrazivanje: " << endl;
	if (y == -1)
	{
		cout << "Broj nije pronaden!" << endl;
	}
	else
	{
		cout << "Broj je pronaden na poziciji " << y << endl;
	}
		
	system("PAUSE");
    return 0;
}
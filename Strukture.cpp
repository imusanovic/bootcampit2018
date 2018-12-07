#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

struct SpaceShip
{
	int x_coordinate = (rand() % 10) + 1;
	int y_coordinate = (rand() % 10) + 1;
	bool outOfRange = false;
	int broj_pomicanja = 0;
};

struct Osoba
{
	char ime[20];
	char adresa[30];
	char telefon[12];
};

struct Knjiga {
	int id;
	string naslov;
	string autor;
	char isbn[13];
	string podrucje;
};

void novaOsoba();
void spaceShip();
void crtanjeLokacije(SpaceShip ship);

int main()
{
	/*
	Knjiga knjiga1;

	knjiga1.id = 1;
	knjiga1.autor = "Pero Peric";
	knjiga1.naslov = "blablabla";
	*/

	/*
	cout << "Unesite ID knjige: ";
	cin >> knjiga1.id;
	cin.ignore();
	cout << "Unesite naslov knjige: ";
	getline(cin, knjiga1.naslov);
	cout << "Unesite autora knjige: ";
	getline(cin, knjiga1.autor);
	cout << "Unesite ISBN knjige: ";
	cin >> knjiga1.isbn;
	cin.ignore();
	cout << "Unesite podrucje knjige: ";
	getline(cin, knjiga1.podrucje);

	cout << "ID: " << knjiga1.id << endl;
	cout << knjiga1.autor << ": " << knjiga1.naslov << endl;
	cout << knjiga1.podrucje << endl;
	cout << "ISBN: " << knjiga1.isbn << endl;
	*/
	/*
	Knjiga knjiga[3];
	/*
	for (int i = 0; i < 3; i++) {
		cout << "Unesite ID knjige: ";
		cin >> knjiga[i].id;
		cin.ignore();
		cout << "Unesite naslov knjige: ";
		getline(cin, knjiga[i].naslov);
		cout << "Unesite autora knjige: ";
		getline(cin, knjiga[i].autor);
		cout << "Unesite ISBN knjige: ";
		cin >> knjiga[i].isbn;
		cin.ignore();
		cout << "Unesite podrucje knjige: ";
		getline(cin, knjiga[i].podrucje);
	}

	for (int i = 0; i < 3; i++) {
		cout << "ID: " << knjiga1.id << endl;
		cout << knjiga1.autor << ": " << knjiga1.naslov << endl;
		cout << knjiga1.podrucje << endl;
		cout << "ISBN: " << knjiga1.isbn << endl;
	}
	*/
	/*
	Knjiga knjizica;
	vector <Knjiga> knjige;
	char x = 'x';
	while (x == 'x') {
		cout << "Unesite ID knjige: ";
		cin >> knjizica.id;
		cin.ignore();
		cout << "Unesite naslov knjige: ";
		getline(cin, knjizica.naslov);
		cout << "Unesite autora knjige: ";
		getline(cin, knjizica.autor);
		cout << "Unesite ISBN knjige: ";
		cin >> knjizica.isbn;
		cin.ignore();
		cout << "Unesite podrucje knjige: ";
		getline(cin, knjizica.podrucje);

		knjige.push_back(knjizica);

		cout << endl << "Unesite x za unos nove knjige\nili bilo koji drugi znak za izlaz: ";
		cin >> x;
	}

	for (int i = 0; i < knjige.size(); i++) {
		cout << "ID: " << knjiga1.id << endl;
		cout << knjiga1.autor << ": " << knjiga1.naslov << endl;
		cout << knjiga1.podrucje << endl;
		cout << "ISBN: " << knjiga1.isbn << endl;
	}
	*/

	//novaOsoba();
	spaceShip();

    return 0;
}

void novaOsoba()
{
	Osoba ivo;
	cout << "Unesite ime: ";
	cin.getline(ivo.ime, 20);
	cout << "Unesite adresu: ";
	cin.getline(ivo.adresa, 30);
	cout << "Unesite telefon: ";
	cin.getline(ivo.adresa, 12);

	cout << ivo.ime << "\t" << ivo.adresa << "\t" << ivo.telefon << endl;
}

void spaceShip()
{
	srand(time(NULL));

	SpaceShip ship[5];
	int outOfRangeCounter = 0, lastX[5], lastY[5];

	while (outOfRangeCounter < 5)
	{
		for (int i = 0; i < 5; i++)
		{
			if (ship[i].outOfRange == true)
			{
				continue;
			}
			else
			{
				if (ship[i].x_coordinate > 10 || ship[i].y_coordinate > 10)
				{
					outOfRangeCounter += 1;
					ship[i].outOfRange = true;
					lastX[i] = ship[i].x_coordinate;
					lastY[i] = ship[i].y_coordinate;
				}
				else
				{
					ship[i].broj_pomicanja += 1;
					crtanjeLokacije(ship[i]);
					cout << "Koordinate broda " << i + 1 << " su: "
						<< ship[i].x_coordinate << ", " << ship[i].y_coordinate
						<< endl << endl;
					ship[i].x_coordinate = (rand() % 15) + 1;
					ship[i].y_coordinate = (rand() % 15) + 1;
				}
			}
			system("pause");
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Zadnje koordinate broda "
			<< i + 1 << " su: " << lastX[i] << ", " << lastY[i]
			<< " - broj pomicanja: " << ship[i].broj_pomicanja << endl;
	}
}

void crtanjeLokacije(SpaceShip ship)
{
	// crtanje - do y koordinate
	for (int i = 1; i < ship.y_coordinate; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "()";
		}
		cout << endl;
	}
	
	// crtanje - do x koordinate
	for (int i = 0; i < ship.x_coordinate-1; i++)
	{
		cout << "()";
	}
	
	// crtanje lokacije koordinata
	cout << "<>";

	// crtanje -- poslije lokacije x koordinate
	for (int i = ship.x_coordinate; i < 10; i++)
	{
		cout << "()";
	}
	cout << endl;

	// crranje -- u ostalim redovima do kraja tablice
	for (int i = ship.y_coordinate; i < 10; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "()";
		}
		cout << endl;
	}	
}
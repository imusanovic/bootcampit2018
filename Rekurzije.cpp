// Rekurzije.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void sagradiZid(int visina);
int brojanje(int x);
int Fibbonacci(int x);
int potencija(int x, int y);
void fibbonacci_niz(int x);

void ispisBrojeva(int i) {
	cout << "Broj " << i << endl;
}

void rekurzivniIspisBrojeva(int i) {
	//cout << "Broj " << i << endl;
	i++;
	if (i < 10) {
		rekurzivniIspisBrojeva(i);
	}
}

void beskonacnaRekurzija() {
	cout << "Nemam kraja :(" << endl;
	beskonacnaRekurzija();
}

int faktorijela(int i) {
	if (i > 1) {
		return i * faktorijela(i - 1);
	}
	else {
		return i;
	}
}

int zbrajanje(int x) {
	if (x == 0) {
		return 0;
	}
	return (zbrajanje(x-1) + x);
}

int main()
{
	//fibbonacci_niz(15);

	//cout << zbrajanje(4) << endl;

	
	// ispis Fib broja;
	//cout << Fibbonacci(7) << endl;

	//cout << endl;
	
	// ispis Fib niza
	/*
	for (int i = 1; i < 8; i++) {
		cout << Fibbonacci(i) << endl;
	}
	*/
	//cout << faktorijela(6) << endl;

	//beskonacnaRekurzija();

	/*
	cout << "for petlja:" << endl;
	for (int i = 1; i <= 10; i++) {
		cout << "Broj " << i << endl;
	}

	cout << "for petlja s funkcijom:" << endl;
	for (int i = 1; i <= 10; i++) {
		ispisBrojeva(i);
	}
	
	cout << "rekurzivna funkcija:" << endl;
	rekurzivniIspisBrojeva(1);
	*/
	/*
	int x, i = 0;

	cout << "Unesite duzinu Fibbonaccijevog niz: ";
	cin >> x;

	while (i < x)
	{
		cout << endl << Fibbonacci(i);
		i++;
	}
	*/

	//cout << brojanje(5);

	// kao argument unosimo željenu visinu zida
	sagradiZid(5);

	cout << Fibbonacci(7) << endl;

	//cout << potencija(2, 15) << endl;

	system("PAUSE");
    return 0;
}

void sagradiZid(int visina) // kao parametar dajemo ukupnu visinu zida
{
	//cout << visina << endl;
	if (visina > 0) // dok je visina (do koje trebamo izgraditi) veæa od nula
	{
		sagradiZid(visina - 1); // pozovemo funkciju umanjenu za 1 red cigli
								// jer je potrebna visina sad manja za 1 red
	}
	cout << visina << endl; // na kraju ispišemo ("sagradimo" red cigli)
}

int brojanje(int x)
{
	if (x == 1)
	{
		return x;
	}
	else
	{ 
		return brojanje(x - 1) + x;
	}
}

int Fibbonacci(int x)
{
	if (x == 0 || x == 1)
	{
		return x;
	}
	else
	{
		return Fibbonacci(x - 1) + Fibbonacci(x - 2);
	}
}

int potencija(int x, int y)
{
	if (y > 1)
	{
		return (x * potencija(x, y - 1));
	}
	else
		return 1;
}

void fibbonacci_niz(int x) {
	if (x > 0) {
		fibbonacci_niz(x - 1);
	}
	cout << Fibbonacci(x) << endl;
}
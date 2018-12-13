// Goldbachova pretpostavka.cpp : Defines the entry point for the console application.
// Je li svaki parni broj veæi od 2, suma dva prosta broja?

#include "stdafx.h"
#include <iostream>

using namespace std;

bool goldbach_provjera(int x);
bool prosti_provjera(int n);
void goldbach_niz();

int main()
{
	goldbach_niz();
	return 0;
}

void goldbach_niz() {
	int x = 4;
	while (goldbach_provjera(x) == true) {
		x += 2;
	}
}

bool goldbach_provjera(int x) {
	int marker = false;
	for (int i = 1; i < x / 2; i++) {
		if (prosti_provjera(i)) {
			if (prosti_provjera(x - i)) {
				cout << "Broj " << x << " se moze zbrojiti prostim brojevima " << i << " i " << x - i << "." << endl;
				marker = true;
			}
		}
	}
	return marker;
}

bool prosti_provjera(int n) {
	bool marker = true;
	for (int i = 2; i < n / 2; i++) {
		if (n%i == 0) {
			marker = false;
			break;
		}
	}
	return marker;
}
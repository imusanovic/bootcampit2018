// Strukture - Student management.cpp :
/* Napišite program koji æe omoguæiti administraciju studenata:
	- unos novih
	- brisanje (po ID-u)
	- izmjenu podataka o studentu
	- prikaz svih studenata
	- prikaz prosjeka po ispitu
	- prikaz najboljeg
	- prikaz najgoreg
	- prikaz po ID-u
	- sortiranje po ukupnom uspjehu

	struktura Student mora imati sljedeæe podatke:
	- ID
	- ime
	- prezime
	- spol
	- rezultat 1. kolokvija
	- rezultat 2. kolokvija
	- rezultat zavrsnog ispita
	- ukupni uspjeh

	Pametno iskoristite sturukture podataka
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <array>

using namespace std;

struct Student {
	string ID;
	string ime;
	char spol;
	map <string, double> rezultati;
};

void menu();
int search(Student st[100], string id, int itemcount);
void add_student(Student st[100], int &itemcount);
void show_students(Student st[100], int itemcount);
void delete_student(Student st[100], int &itemcount);
void izmjena_student(Student st[100], int itemcount);
void prosjek_po_ispitu(Student st[100], int itemcount);
void prikaz_najboljeg(Student st[100], int itemcount);
void prikaz_najgoreg(Student st[100], int itemcount);
void pronalazak_po_id(Student st[100], int itemcount);
void soriranje_studenata(Student st[100], int itemcount);

int main()
{
	cout << "\t\t - Sustav za upravljanje studentima - \n";
	
	Student st[100];
	int student_count = 0;


	int izbor = -1;

	while (izbor != 0) {
		menu();
		cout << "Unesite svoj izbor: ";
		cin >> izbor;
		switch (izbor) {
		case 1:
			add_student(st, student_count);
			break;
		case 2:
			delete_student(st, student_count);
			break;
		case 3:
			izmjena_student(st, student_count);
			break;
		case 4:
			show_students(st, student_count);
			break;
		case 5:
			prosjek_po_ispitu(st, student_count);
			break;
		case 6:
			prikaz_najboljeg(st, student_count);
			break;
		case 7:
			prikaz_najgoreg(st, student_count);
			break;
		case 8:
			pronalazak_po_id(st, student_count);
			break;
		case 9:
			soriranje_studenata(st, student_count);
			break;
		case 0:
			cout << endl;
			break;
		default:
			cout << "\nNiste unijeli valjani izbor. Pokusajte ponovo\n";
			menu();
			break;
		}
	}
	system("pause");
	return 0;
}

void menu() {
	
	cout << "\nOdaberite sto zelite uciniti:\n\n";
	cout << "1 - Unos novog studenta\n";
	cout << "2 - Brisanje studenta\n";
	cout << "3 - Izmjena podataka o studentu\n";
	cout << "4 - Pregled podataka o svim studentima\n";
	cout << "5 - Racunanje prosjeka rezultata po ispitu\n";
	cout << "6 - Prikaz najboljeg studenta\n";
	cout << "7 - Prikaz najgoreg studenta\n";
	cout << "8 - Pronalazak studenta po ID-u\n";
	cout << "9 - Sortiranje studenata po uspjehu\n";
	cout << "0 - Izlaz\n\n";
}

int search(Student st[100], string id, int itemcount) {
	int found = -1;
	
	for (int i = 0; i < itemcount && found == -1; i++)
	{
		if (st[i].ID == id) {
			found = i;
		}
		else {
			found = -1;
		}
	}

	return found;
}

void add_student(Student st[100], int &itemcount) {
	cout << "Unesite ID studenta: ";
	cin >> st[itemcount].ID;
	if (search(st, st[itemcount].ID, itemcount) != -1)
	{
		cout << "\nVec postoji student s tim ID-om!\n";
		add_student(st, itemcount);
	}
	else {
		cout << "Unesite ime studenta: ";
		cin >> st[itemcount].ime;
		cout << "Unesite spol studenta: ";
		cin >> st[itemcount].spol;
		cout << "Unesite rezultat 1. kolokvija: ";
		cin >> st[itemcount].rezultati["1. Kolokvij"];
		cout << "Unesite rezultat 2. kolokvija: ";
		cin >> st[itemcount].rezultati["2. Kolokvij"];
		cout << "Unesite rezultat 3. kolokvija: ";
		cin >> st[itemcount].rezultati["3. Kolokvij"];
		cout << "Unesite rezultat zavrsnog ispita: ";
		cin >> st[itemcount].rezultati["Zavrsni ispit"];
		st[itemcount].rezultati["Ukupan rezultat"] =
			(st[itemcount].rezultati["1. Kolokvij"] +
				st[itemcount].rezultati["2. Kolokvij"] +
				st[itemcount].rezultati["3. Kolokvij"] +
				st[itemcount].rezultati["Zavrsni ispit"]) / 4;
		
	}
	itemcount++;
}

void show_students(Student st[100], int itemcount) {
	cout << "\nPodaci o studentima: \n\n";
	for (int i = 0; i < itemcount; i++) {
		cout << st[i].ID << " " << st[i].ime << " " << st[i].spol << " ";
		cout << st[i].rezultati["1. Kolokvij"] << " ";
		cout << st[i].rezultati["2. Kolokvij"] << " ";
		cout << st[i].rezultati["3. Kolokvij"] << " ";
		cout << st[i].rezultati["Zavrsni ispit"] << " ";
		cout << st[i].rezultati["Ukupan rezultat"] << "\n";
	}
}

void delete_student(Student st[100], int &itemcount) {
	string id;
	int index;
	cout << "Unesite ID studenta: ";
	cin >> id;
	for (int i = 0; i < itemcount; i++) {
		if (st[i].ID == id) {
			index = i;
			break;
		}
	}
	array <Student, 100> temp;
	for (int i = 0; i < index; i++) {
		temp[i] = st[i];
	}
	for (int i = index + 1; i < 100; i++) {
		temp[i - 1] = st[i];
	}
	for (int i = 0; i < 100; i++) {
		st[i] = temp[i];
	}
	itemcount--;
}

void izmjena_student(Student st[100], int itemcount) {
	string id;
	int index;
	cout << "Unesite ID studenta: ";
	cin >> id;
	for (int i = 0; i < itemcount; i++) {
		if (st[i].ID == id) {
			index = i;
			break;
		}
	}
	cout << "Unesite ime studenta: ";
	cin >> st[index].ime;
	cout << "Unesite spol studenta: ";
	cin >> st[index].spol;
	cout << "Unesite rezultat 1. kolokvija: ";
	cin >> st[index].rezultati["1. Kolokvij"];
	cout << "Unesite rezultat 2. kolokvija: ";
	cin >> st[index].rezultati["2. Kolokvij"];
	cout << "Unesite rezultat 3. kolokvija: ";
	cin >> st[index].rezultati["3. Kolokvij"];
	cout << "Unesite rezultat zavrsnog ispita: ";
	cin >> st[index].rezultati["Zavrsni ispit"];
	st[index].rezultati["Ukupan rezultat"] =
		(st[index].rezultati["1. Kolokvij"] +
			st[index].rezultati["2. Kolokvij"] +
			st[index].rezultati["3. Kolokvij"] +
			st[index].rezultati["Zavrsni ispit"]) / 4;
}

void prosjek_po_ispitu(Student st[100], int itemcount) {
	int izbor;
	cout << "\nIzaberite za sto zelite prosjek (1 - 1. kolokvij,\n";
	cout << "2 - 2. kolokvij, 3 - 3. kolokvij, 4 - Zavrsni ispit,\n";
	cout << "5 - Ukupni rezultat\n";
	cout << "Unesite izbor: ";
	cin >> izbor;
	double prosjek = 0;
	switch (izbor)
	{
	case 1:
		prosjek = 0;
		for (int i = 0; i < itemcount; i++) {
			prosjek += st[i].rezultati["1. Kolokvij"];
		}
		cout << "Prosjek 1. kolokvija je " << prosjek / itemcount << endl;
		break;
	case 2:
		prosjek = 0;
		for (int i = 0; i < itemcount; i++) {
			prosjek += st[i].rezultati["2. Kolokvij"];
		}
		cout << "Prosjek 2. kolokvija je " << prosjek / itemcount << endl;
		break;
	case 3:
		prosjek = 0;
		for (int i = 0; i < itemcount; i++) {
			prosjek += st[i].rezultati["3. Kolokvij"];
		}
		cout << "Prosjek 3. kolokvija je " << prosjek / itemcount << endl;
		break;
	case 4:
		prosjek = 0;
		for (int i = 0; i < itemcount; i++) {
			prosjek += st[i].rezultati["Zavrsni ispit"];
		}
		cout << "Prosjek zavrsnog ispita je " << prosjek / itemcount << endl;
		break;
	case 5:
		prosjek = 0;
		for (int i = 0; i < itemcount; i++) {
			prosjek += st[i].rezultati["Ukupan prosjek"];
		}
		cout << "Ukupni prosjek je " << prosjek / itemcount << endl;
		break;
	default:
		cout << "Niste unijeli valjan odabir!" << endl;
		break;
	}
}

void prikaz_najboljeg(Student st[100], int itemcount) {
	int index = 0;
	for (int i = 1; i < itemcount; i++) {
		if (st[i].rezultati["Ukupan rezultat"] > st[i-1].rezultati["Ukupan rezultat"]) {
			index = i;
		}
	}
	cout << "Najbolji student je " << st[index].ime << endl;
}

void prikaz_najgoreg(Student st[100], int itemcount) {
	int index = 0;
	for (int i = 1; i < itemcount; i++) {
		if (st[i].rezultati["Ukupan rezultat"] < st[i - 1].rezultati["Ukupan rezultat"]) {
			index = i;
		}
	}
	cout << "Najgori student je " << st[index].ime << endl;
}

void pronalazak_po_id(Student st[100], int itemcount) {
	string id;
	int index;
	cout << "Unesite ID studenta: ";
	cin >> id;
	for (int i = 0; i < itemcount; i++) {
		if (st[i].ID == id) {
			index = i;
			break;
		}
	}
	cout << "ID: " << st[index].ID << endl;
	cout << "Ime: " << st[index].ime << endl;
	cout << "Spol: " << st[index].spol << endl;
	cout << "Rezultati: " << endl;
	cout << "1. kolokvij: " << st[index].rezultati["1. kolokvij"] << endl;
	cout << "2. kolokvij: " << st[index].rezultati["2. kolokvij"] << endl;
	cout << "3. kolokvij: " << st[index].rezultati["3. kolokvij"] << endl;
	cout << "Zavrsni ispit: " << st[index].rezultati["Zavrsni ispit"] << endl;
	cout << "Ukupan rezultat: " << st[index].rezultati["Ukupan rezultat"] << endl << endl;
}

void soriranje_studenata(Student st[100], int itemcount) {
	Student temp;
	for (int i = 0; i < itemcount; i++) {
		for (int j = i+1; j < itemcount; j++) {
			if (st[i].rezultati["Ukupan rezultat"] < st[j].rezultati["Ukupan rezultat"]) {
				temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
}
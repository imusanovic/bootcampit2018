#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>

using namespace std;

void glavni_menu();
void igre_menu(int &chipovi, int &novac);
void kupovina_chipova(int &novac, int &chipovi);
void prodaja_chipova(int &novac, int &chipovi);
void slot_machine(int &chipovi);
void kockice(int &chipovi);
void duplo(int &chipovi);
string karta(int broj);
void spremanje_stanja(int chipovi, string file);
void highscore(string file);

string ime;

int main(){
	int stanje_novca = 0;
	int stanje_chipova = 0;
	int izbor;
	cout << "Unesite ime: ";
	getline(cin, ime);
	cout << "Unesite koliko novca imate: ";
	cin >> stanje_novca;
	int pocetno_stanje = stanje_novca;
	
	do {
		glavni_menu();
		cout << endl;
		cin >> izbor;
		switch (izbor)
		{
		case 1:
			kupovina_chipova(stanje_novca, stanje_chipova);
			break;
		case 2:
			prodaja_chipova(stanje_novca, stanje_chipova);
			break;
		case 3:
			igre_menu(stanje_chipova, stanje_novca);
			break;
		case 4:
			system("cls");
			cout << "\nJednoruki Jack\n\n";
			highscore("jack.txt");
			cout << "\nKockice\n\n";
			highscore("kockice.txt");
			cout << "\nDuplo ili nista\n\n";
			highscore("duplo.txt");
			cout << "\nUkupno\n\n";
			highscore("ukupno.txt");
			system("pause");
			break;
		case 0:
			break;
		default:
			cout << "\nNiste unijeli dobar izbor!\n";
			break;
		}
	} while (izbor != 0);
	int zavrsno_stanje = stanje_novca;
	spremanje_stanja(zavrsno_stanje - pocetno_stanje, "ukupno.txt");
	return 0;
}

void glavni_menu() {
	system("cls");
	cout << "\t\tC++ Casino\n\n";
	cout << "1 - Kupovina chipova\n2 - Prodaja chipova\n";
	cout << "3 - Igre\n4 - High scores\n0 - Izlaz";
}

void igre_menu(int &chipovi, int &novac) {
	if (chipovi > 0) {
		int izbor_igre;
		do {
			system("cls");
			cout << "\n1 - Jednoruki Jack\n2 - Kockice\n3 - Duplo ili nista\n";
			cout << "0 - Povratak\n";
			cout << "Unesite svoj izbor: ";
			cin >> izbor_igre;
			switch (izbor_igre)
			{
			case 1:
				slot_machine(chipovi);
				break;
			case 2:
				kockice(chipovi);
				break;
			case 3:
				duplo(chipovi);
				break;
			case 0:
				break;
			default:
				cout << "\nUnesite valjani izbor\n";
				break;
			}
		} while (izbor_igre != 0);
	}
	else {
		cout << "Nemate dovoljno novca za igrati se!" << endl;
		system("pause");
	}
}

void kupovina_chipova(int &novac, int &chipovi)
{
	int chip;
	system("cls");
	cout << "Trenutno stanje\n";
	cout << novac << " kn\n";
	cout << chipovi << " chipova\n\n";
	cout << "Cijena: 1 chip = 5 kn\n";
	cout << "Koliko chipova zelite kupiti: ";
	cin >> chip;
	if ((chip * 5) <= novac) {
		chipovi += chip;
		novac -= chip * 5;
	}
	else {
		cout << "Nemate dovoljno novca za kupiti toliko chipova!\n";
	}
}

void prodaja_chipova(int &novac, int &chipovi)
{
	int chip;
	system("cls");
	cout << "Trenutno stanje\n";
	cout << novac << "kn\n";
	cout << chipovi << "chipova\n\n";
	cout << "1 chip = 5 kn\n";
	cout << "Koliko chipova zelite prodati: ";
	cin >> chip;
	if (chip <= chipovi) {
		chipovi -= chip;
		novac += (chip * 5);
	}
	else {
		cout << "Nemate toliko chipova!\n";
	}
}

void slot_machine(int &chipovi) {
	system("cls");
	int pocetno_stanje = chipovi;
	srand(time(NULL));
	char ruka = 'x';
	int a, b, c, ulog;
	while (ruka == 'x' || ruka == 'X' && chipovi != 0) {
		cout << "Unesite svoj ulog ili 0 za izlaz: ";
		cin >> ulog;
		if (ulog > chipovi) {
			cout << "Nemate toliko chipova!" << endl;
		}
		else if (ulog == 0) {
			break;
		}
		else {
			system("cls");
			cout << "Povucite Jednorukog Jack-a za ruku\n";
			cout << "i osvojite milijune! :) :) :)\n";
			cout << "Kako biste povukli unesite X: ";
			cin >> ruka;
			if (ruka == 'x' || ruka == 'X') {
				cout << endl;
				chipovi -= ulog;
				a = rand() % 4 + 1;
				b = rand() % 4 + 1;
				c = rand() % 4 + 1;
				cout << a << " " << b << " " << c << endl;
				if (a == b && b == c) {
					cout << "Pobjeda! Osvojili ste " << ulog * 16
						<< "chipova!\n";
					chipovi += ulog * 16; 
				}
			}
			else {
				break;
			}
		}
	}
	int zavrsno_stanje = chipovi;
	spremanje_stanja(zavrsno_stanje - pocetno_stanje, "jack.txt");
}

void kockice(int &chipovi) {
	int pocetno_stanje = chipovi;
	system("cls");
	srand(time(NULL));
	char bacanje = 'x';
	int a, b, c, d, ulog;
	while (bacanje == 'x' || bacanje == 'X' && chipovi != 0) {
		cout << "Unesite svoj ulog ili 0 za izlaz: ";
		cin >> ulog;
		if (ulog > chipovi) {
			cout << "Nemate toliko chipova!" << endl;
		}
		else if (ulog == 0) {
			break;
		}
		else {
			system("cls");
			cout << "Bacajte kockice protiv racunala\n";
			cout << "i osvojite milijune! :) :) :)\n";
			cout << "Kako biste bacili unesite X: ";
			cin >> bacanje;
			if (bacanje == 'x' || bacanje == 'X') {
				cout << endl;
				chipovi -= ulog;
				a = rand() % 6 + 1;
				b = rand() % 6 + 1;
				c = rand() % 6 + 1;
				d = rand() % 6 + 1;
				cout << "Vi ste bacili: " << a << endl;
				cout << "Racunalo je bacilo: " << b << endl;
				cout << "Vi ste bacili: " << c << endl;
				cout << "Racunalo je bacilo: " << d << endl;
				if (a + c > b + d) {
					cout << "Pobjeda! Osvojili ste " << ulog * 2
						<< "chipova!\n";
					chipovi += ulog * 2;
				}
				else if (a + c == b + d) {
					cout << "Izjednaceno! Ulog vam se vraca!\n";
					chipovi += ulog;
				}
				else {
					cout << "Izgubili ste! :(" << endl;
					system("pause");
					break;
				}
			}
		}
	}
	int zavrsno_stanje = chipovi;
	spremanje_stanja(zavrsno_stanje - pocetno_stanje, "kockice.txt");
}

void duplo(int &chipovi) {
	int pocetno_stanje = chipovi;
	srand(time(NULL));
	vector <int> karte;
	karte.push_back(0);
	for (int i = 1; i <= 52; i++) {
		karte.push_back(i);
	}
	char unos = 'x';
	int ulog;
	int karta_komp, karta_igrac, brojac = 52;
	system("cls");
	cout << "Kartu vucete vi i racunalo.\n";
	cout << "Tko ima vecu pobjedjuje!\n";
	cout << "Svaki put kada izgubite mozete igrati za duplo ili nista.\n";
	cout << "Unesite pocetni ulog: ";
	cin >> ulog;
	// bool dovoljno_novca = true;
	do {
		system("cls");
		if (ulog > chipovi /*&& dovoljno_novca == false*/) {
			cout << "Nemate toliko chipova!\nUnesite ulog: ";
			cin >> ulog;
		}
		else {
			while (karte.size() != 1 && unos == 'x') {
				cout << "Unesite x za izvlacenje karte: ";
				cin >> unos;
				int karta_i, karta_k;
				karta_igrac = (rand() % brojac) + 1;
				cout << "Vasa karta: " << karta(karte[karta_igrac]) << endl;
				karta_i = karte[karta_igrac];
				karte.erase(karte.begin() + karta_igrac);
				brojac--;
				karta_komp = (rand() % brojac) + 1;
				cout << "Karta racunala: " << karta(karte[karta_komp]) << endl;
				karta_k = karte[karta_komp];
				karte.erase(karte.begin() + karta_komp);
				brojac--;
				if ((karta_i % 13) + 1 > (karta_k % 13) + 1) {
					cout << "Pobijedili ste!\n\n";
					chipovi += ulog * 2;
				}
				else if ((karta_i % 13) + 1 == (karta_k % 13) + 1) {
					cout << "Karte iste jacine!\n\n";
					chipovi += ulog;
				}
				else {
					cout << "Izgubili ste!\n\n";
					chipovi -= ulog;
				}
				if (chipovi >= (ulog * 2)) {
					char izbor;
					cout << "Zelite li duplo ili nista? D/N: ";
					cin >> izbor;
					if (izbor == 'D' || izbor == 'd') {
						ulog *= 2;

					}
					else {
						unos = 'k';
						break;
					}
				}
				else {
					cout << "Nemate dovoljno chipova za odigrati duplo ili nista!\n";
					cout << "Unesite pocetni ulog za nastavak igre ili 0 za povratak: ";
					cin >> ulog;
					cout << endl;
					break;
				}
			}
		}
	} while (unos == 'x' && ulog != 0);
	int zavrsno_stanje = chipovi;
	spremanje_stanja(zavrsno_stanje - pocetno_stanje, "duplo.txt");
}

string karta(int broj) {
	string boja, znak;
	if (broj > 0 && broj <= 13) {
		boja = "pik";
	}
	else if (broj > 13 && broj <= 26) {
		boja = "herc";
	}
	else if (broj > 26 && broj <= 39) {
		boja = "tref";
	}
	else {
		boja = "karo";
	}
	switch (broj % 13) {
	case 0:
		znak = "Dvojka";
		break;
	case 1:
		znak = "Trojka";
		break;
	case 2:
		znak = "Cetvorka";
		break;
	case 3:
		znak = "Petica";
		break;
	case 4:
		znak = "Sestica";
		break;
	case 5:
		znak = "Sedmica";
		break;
	case 6:
		znak = "Osmica";
		break;
	case 7:
		znak = "Devetka";
		break;
	case 8:
		znak = "Desetka";
		break;
	case 9:
		znak = "Decko";
		break;
	case 10:
		znak = "Dama";
		break;
	case 11:
		znak = "Kralj";
		break;
	case 12:
		znak = "As";
		break;
	}
	return znak + " " + boja;
}

void spremanje_stanja(int chipovi, string file) {
	ofstream output;
	string za_krcat;
	output.open(file, ios::app);
	za_krcat = ime + " " + to_string(chipovi) + "\n";
	output << za_krcat;
	output.close();
}

void highscore(string file) {
	ifstream input;
	vector <string> ime;
	vector <int> bodovi;
	string i;
	int bod;
	input.open(file);
	while (input) {
		input >> i >> bod;
		ime.push_back(i);
		bodovi.push_back(bod);
	}
	input.close();
	for (int i = 0; i < bodovi.size() - 1; i++) {
		for (int j = 0; j < bodovi.size(); j++) {
			if (bodovi[i] > bodovi[j]) {
				int bod_temp = bodovi[i];
				string ime_temp = ime[i];
				bodovi[i] = bodovi[j];
				ime[i] = ime[j];
				bodovi[j] = bod_temp;
				ime[j] = ime_temp;
			}
		}
	}
	for (int i = 0; i < bodovi.size() - 1 && i < 3; i++) {
		cout << ime[i] << " " << bodovi[i] << endl;
	}
}
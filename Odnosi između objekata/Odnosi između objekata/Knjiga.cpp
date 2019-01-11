#include "pch.h"
#include "Knjiga.h"

std::vector <Knjiga*> Knjiga::knjige;

Knjiga::Knjiga()
{
	std::string naziv, autor;
	std::cout << "Unesite naslov: ";
	std::cin >> naziv;
	std::cout << "Unesite autora: ";
	std::cin >> autor;
	this->set_naziv(naziv);
	this->set_autor(autor);
}

Knjiga::~Knjiga()
{
	knjige.erase(knjige.begin() + index);
}

void Knjiga::set_naziv(std::string n) {
	naziv = n;
}

std::string Knjiga::get_naziv() {
	return naziv;
}

void Knjiga::set_autor(std::string a) {
	autor = a;
}

std::string Knjiga::get_autor() {
	return autor;
}

void Knjiga::unos_knjige() {
	Knjiga* k = new Knjiga();
	knjige.push_back(k);
}

void Knjiga::popis_knjiga() {
	for (int i = 0; i < knjige.size(); i++) {
		std::cout << knjige[i]->get_naziv() << " - " << knjige[i]->get_autor() << std::endl;
	}
	system("pause");
}

void Knjiga::brisanje_knjige(Knjiga* k) {
	delete k;
}

Knjiga* Knjiga::pretraga_knjige() {
	std::string naziv;
	int brojac = 0;
	std::cout << "Unesite naziv knjige: ";
	std::cin >> naziv;
	for (int i = 0; i < knjige.size(); i++) {
		if (knjige[i]->get_naziv() == naziv) {
			return knjige[i];
		}
	}
	return nullptr;
}

void Knjiga::izbornik_knjiga() {
	int izbor;
	do {
		std::system("cls");
		std::cout << "1 - Unos knjige\n2 - Brisanje knjige\n3 - Popis knjiga\n0 - Povratak\n\n";
		std::cout << "Unesite svoj odabir: ";
		std::cin >> izbor;
		switch (izbor) {
		case 1:
			Knjiga::unos_knjige();
			break;
		case 2:
			Knjiga::brisanje_knjige(Knjiga::pretraga_knjige());
			break;
		case 3:
			Knjiga::popis_knjiga();
			break;
		case 0:
			break;
		default:
			std::cout << "Loš odabir!" << std::endl;
		}
	} while (izbor != 0);
}

int Knjiga::get_index() {
	for (int i = 0; i < knjige.size(); i++) {
		if (this == knjige[i]) {
			return i;
		}
	}
}
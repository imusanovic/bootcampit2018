#include "pch.h"
#include "Korisnik.h"

std::vector <Korisnik*> Korisnik::korisnici;

Korisnik::Korisnik()
{
	std::string ime, prezime;
	std::cout << "Unesite ime: ";
	std::cin >> ime;
	std::cout << "Unesite prezime: ";
	std::cin >> prezime;
	this->set_ime(ime);
	this->set_prezime(prezime);
}

Korisnik::~Korisnik()
{
}

void Korisnik::set_ime(std::string i) {
	ime = i;
}

std::string Korisnik::get_ime() {
	return ime;
}

void Korisnik::set_prezime(std::string p) {
	prezime = p;
}

std::string Korisnik::get_prezime() {
	return prezime;
}

void Korisnik::unos_korisnika() {
	Korisnik* k = new Korisnik();
	korisnici.push_back(k);
}

void Korisnik::popis_korisnika() {
	for (int i = 0; i < korisnici.size(); i++) {
		std::cout << korisnici[i]->get_ime() << " " << korisnici[i]->get_prezime() << std::endl;
	}
	system("pause");
}

int Korisnik::get_index() {
	for (int i = 0; i < korisnici.size(); i++) {
		if (this == korisnici[i]) {
			return i;
		}
	}
}

void Korisnik::brisanje_korisnika(Korisnik *k) {
	korisnici.erase(korisnici.begin() + k->get_index());
	delete k;
}

Korisnik* Korisnik::pretraga_korisnika() {
	std::string prezime;
	int brojac = 0;
	std::cout << "Unesite prezime korisnika: ";
	std::cin >> prezime;
	for (int i = 0; i < korisnici.size(); i++) {
		if (korisnici[i]->get_prezime() == prezime) {
			return korisnici[i];
		}
	}
	return nullptr;
}

void Korisnik::izbornik_korisnik() {
	int izbor;
	do {
		std::system("cls");
		std::cout << "1 - Unos korisnika\n2 - Brisanje korisnika\n3 - Popis korisnika\n0 - Povratak\n\n";
		std::cout << "Unesite svoj odabir: ";
		std::cin >> izbor;
		switch (izbor) {
		case 1:
			Korisnik::unos_korisnika();
			break;
		case 2:
			Korisnik::brisanje_korisnika(Korisnik::pretraga_korisnika());
			break;
		case 3:
			Korisnik::popis_korisnika();
			break;
		case 0:
			break;
		default:
			std::cout << "Loš odabir!" << std::endl;
		}
	} while (izbor != 0);
}
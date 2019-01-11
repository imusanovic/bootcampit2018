#include "pch.h"
#include "Posudba.h"

std::vector <Posudba*> Posudba::izdane_knjige;

Posudba::Posudba()
{
	this->knjiga = Knjiga::pretraga_knjige();
	this->korisnik = Korisnik::pretraga_korisnika();
	this->datum_posudbe = time(0);
}

Posudba::~Posudba()
{
}

void Posudba::posudi_knjigu() {
		Posudba* p = new Posudba();
		izdane_knjige.push_back(p);
}

int Posudba::pretraga() {
	std::string naziv;
	std::cout << "Unesite naziv knjige: ";
	std::cin >> naziv;
	for (int i = 0; i < izdane_knjige.size(); i++) {
		if (izdane_knjige[i]->knjiga->get_naziv() == naziv) {
			return i;
		}
	}
	return -1;
}

void Posudba::vrati_knjigu(int index) {
	izdane_knjige.erase(izdane_knjige.begin() + index);
}

void Posudba::popis_izdanih_knjiga() {
	for (int i = 0; i < izdane_knjige.size(); i++) {
		std::cout << izdane_knjige.size();
		std::cout << "Knjiga:\n";
		std::cout << izdane_knjige[i]->knjiga->get_naziv() << " - " << izdane_knjige[i]->knjiga->get_autor() << std::endl;
		std::cout << "je posudena:\n";
		std::cout << izdane_knjige[i]->korisnik->get_ime() << " - " << izdane_knjige[i]->korisnik->get_prezime() << std::endl;
	}
	system("pause");
}

void Posudba::izbornik_posudba() {
	int izbor;
	do {
		std::system("cls");
		std::cout << "1 - Posudi knjigu\n2 - Vrati knjigu\n3 - Popis posudenih knjiga\n0 - Povratak\n\n";
		std::cout << "Unesite svoj odabir: ";
		std::cin >> izbor;
		switch (izbor) {
		case 1:
			Posudba::posudi_knjigu();
			break;
		case 2:
			Posudba::vrati_knjigu(Posudba::pretraga());
			break;
		case 3:
			Posudba::popis_izdanih_knjiga();
			break;
		case 0:
			break;
		default:
			std::cout << "Loš odabir!" << std::endl;
		}
	} while (izbor != 0);
}
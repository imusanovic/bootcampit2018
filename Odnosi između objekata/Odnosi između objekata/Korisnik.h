#pragma once
#ifndef KORISNIK_H
#define KORISNIK_H

#include <iostream>
#include <string>
#include <vector>

class Korisnik {
private:
	std::string ime;
	std::string prezime;
	int index;

	Korisnik();
	~Korisnik();
	static void popis_korisnika();
	static void unos_korisnika();
	static void brisanje_korisnika(Korisnik* k);
	int get_index();
public:
	static std::vector <Korisnik*> korisnici;
	void set_ime(std::string i);
	std::string get_ime();
	void set_prezime(std::string p);
	std::string get_prezime();
	
	static void izbornik_korisnik();
	static Korisnik* pretraga_korisnika();
};

#endif // !KORISNIK_H
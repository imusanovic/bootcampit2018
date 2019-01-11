#pragma once
#include <string>
#include <vector>
#include <iostream>
class Knjiga
{
private:
	std::string naziv;
	std::string autor;

	Knjiga();
	~Knjiga();
	static void unos_knjige();
	static void brisanje_knjige(Knjiga* k);
	int get_index();

public:
	static std::vector <Knjiga*> knjige;
	void set_naziv(std::string n);
	std::string get_naziv();
	void set_autor(std::string a);
	std::string get_autor();

	static void popis_knjiga();
	static Knjiga* pretraga_knjige();
	static void izbornik_knjiga();
};


#pragma once
#include <iostream>
#include <string>
#include "Knjiga.h"
#include "Korisnik.h"
#include <ctime>

class Posudba
{
private:
	static std::vector <Posudba*> izdane_knjige;
	std::time_t datum_posudbe;
	Knjiga* knjiga;
	Korisnik* korisnik;
	Posudba();
	~Posudba();
	static void popis_izdanih_knjiga();
	static void posudi_knjigu();
	static void vrati_knjigu(int index);
	static int pretraga();
public:
	static void izbornik_posudba();
};

